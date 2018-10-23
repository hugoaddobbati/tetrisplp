{-# LANGUAGE OverloadedStrings #-}
{-# LANGUAGE TemplateHaskell #-}
{-# LANGUAGE CPP #-}

module Main where
import System.IO
import System.IO.Unsafe  
import System.Random
import Lens.Micro ((^.), (&), (.~), (%~))
import Lens.Micro.TH (makeLenses)
import Control.Monad (void, forever)
import Control.Concurrent (threadDelay, forkIO)

#if !(MIN_VERSION_base(4,11,0))
import Data.Monoid
#endif

import qualified Graphics.Vty as V
import qualified Brick.Widgets.Border.Style as BS
import Brick.Widgets.Border as B
import Brick.Widgets.Center as C
import Brick.BChan
import Brick.Main
  ( App(..)
  , showFirstCursor
  , customMain
  , continue
  , halt
  )

import Brick.Util (on, fg)
import Brick.AttrMap (attrMap, AttrMap ,attrName)
import Brick.Types
  ( Widget
  , Next
  , EventM
  , BrickEvent(..)
  , Padding(..)
  )
import Brick.Widgets.Core
  ( (<=>)
  , (<+>)
  , str
  , padLeft
  , padRight
  , padTop
  , padBottom
  , padTopBottom
  , padLeftRight
  , vBox
  , hBox
  ,fill
  ,withAttr
  ,vLimit
  ,hLimit
  ,withBorderStyle
  )

  data CustomEvent = Counter deriving Show

---------------------
-- MOVE TETROMINO DOWN, CLEAR ROWS AND PUT NEW TETROMINO IF FULL

tryGoDownTetromino :: St -> EventM () (Next St)
tryGoDownTetromino st = 
    if isValidState tmpBd
        then goDownTetromino st
        else halt $ st
    where 
        newSt = simulateNextBoard st
        tmpBd = newSt^.board
        


simulateNextBoard :: St -> St
simulateNextBoard st = 
    if isValidState (goDown simulatedBoard)
        then st & board %~ goDown
        else st & board %~ (appendAndClearRow (st ^. g)) 
                & g %~ newR
    where simulatedBoard = st^.board    

              


goDownTetromino :: St -> EventM () (Next St)
goDownTetromino st = continue 
    $ if isValidState (goDown simulatedBoard)
        then st & board %~ goDown
        else st & board %~ (appendAndClearRow (st ^. g)) 
                & g %~ newR
    where simulatedBoard = st^.board    

getIntFromStd :: (Int, StdGen) -> Int
getIntFromStd (x,y) = ((x `mod` 7)+1)


newR :: (Int, StdGen) -> (Int, StdGen)
newR (x, y) = randomR (1,7) y

goDown :: Board -> Board
goDown bd = bd & tetrominoPts %~ map movePointDown

movePointDown :: Point -> Point
movePointDown p = p & y %~ (+1)

appendAndClearRow :: (Int, StdGen) -> Board -> Board
appendAndClearRow (a,b) bd = clearRows (appendPiece (a,b) bd)

clearRows :: Board -> Board
clearRows bd = bd & points %~ removeAndFix 

removeAndFix :: [Point] -> [Point]
removeAndFix pts = removeAllRows (removeRow) 0 rows pts
    where   
        rows = getFullRows pts
        t = (length rows) + (-1)


removeAllRows :: (Int -> [Point] -> [Point]) -> Int -> [Int] -> [Point] -> [Point]
removeAllRows op n rows pts
    |length rows == 0 = pts
    |n == (length rows) -1  = (op (nth n rows) pts)
    |otherwise = removeAllRows op (n+1) rows (op (nth n rows) pts)

removeRow :: Int -> [Point] -> [Point]
removeRow _ [] = []
removeRow n (x:xs) = if x^.y == n
                        then removeRow n xs
                        else if x^.y < n
                            then [x & y %~ (+1)] ++ removeRow n xs
                            else [x] ++ removeRow n xs

isRowFull :: Int -> [Point] -> Bool
isRowFull rowNum pts = (length temporary) == 10
    where
        temporary = [x | x <-pts, x^.y == rowNum]

getFullRows:: [Point] -> [Int]
getFullRows pts = [y | y <- [0..19], isRowFull y pts]

getScorePostAppend :: Board -> Int
getScorePostAppend bd 
    |rows == 0 = 0
    |rows == 1 = 100
    |rows == 2 = 300
    |rows == 3 = 800
    |rows == 4 = 2000
    where 
        rows = length $ getFullRows ((bd & points %~ (<>) pts)^.points)
        pts = bd^.tetrominoPts


        
getLinesPostAppend :: Board -> Int
getLinesPostAppend bd = l
    where
        l = length $ getFullRows ((bd & points %~ (<>) pts)^.points)
        pts = bd^.tetrominoPts

appendPiece :: (Int, StdGen) -> Board -> Board
appendPiece (a,b) bd = bd & points %~ (<>) pts
                        & tetrominoPts .~ getT a
                        & score %~ (+ getScorePostAppend (bd))
                        & powerUp %~ (+ getLinesPostAppend (bd))
    where
        pts = bd^.tetrominoPts



drawUI :: St -> [Widget ()]
drawUI st = [a]
    where
        a = C.hCenter $ 
            C.vCenter $ 
            hBox[
                vBox
                [padRight (Pad 5) $ borderWithLabel (str $ "score") $ padLeft (Pad 5) $  padRight (Pad 5) $ str $ show $ scr, 
                padRight (Pad 5) $ padTop (Pad 2) $  borderWithLabel (str $ "last highscore") $ padLeft(Pad 7) $ padRight (Pad 7) $ str $ show $ bestScr],
            vLimit 22 $ 
            hLimit 22 $ 
            borderWithLabel (str $ "not a tetris") $
            drawGrid st,
            vBox
                [padLeft (Pad 5) $ borderWithLabel (str $ "nextTetro") $ padLeft (Pad 5) $ padRight (Pad 5) $ vb,
                padLeft(Pad 5) $ padTop(Pad 2) $ borderWithLabel (str $ "PowerUP Status") $ padLeft (Pad 7) $ padRight(Pad 7) $ getPowerUpStatus st]]
            
        bd = st^.board
        scr = bd^.score
        var = length (getNumberOfRows bd)
        vb = getNextTetrovBox ( getNextTetroPos (st))
        bestScr = st^.lastBestScore
 
makeLenses ''St
makeLenses ''Board
makeLenses ''Point

data Point = 
    Point {
        _x :: Int,
        _y :: Int,
        _color :: [Char]
    }

data Board = 
    Board {
        _tetrominoPts :: [Point],
        _points :: [Point],
        _score :: Int,
        _powerUp :: Int
    }

data St =
    St {_board :: Board,
        _g :: (Int, StdGen),
        _lastBestScore :: Int
       }

theApp :: App St CustomEvent ()
theApp =
    App { appDraw = drawUI
        , appChooseCursor = showFirstCursor
        , appHandleEvent = appEvent
        , appStartEvent = return
        , appAttrMap = const theMap
        }

appEvent :: St -> BrickEvent () CustomEvent -> EventM () (Next St)
appEvent st e =
    case e of
        VtyEvent (V.EvKey (V.KChar 'p') []) -> powerUpSt st
        VtyEvent (V.EvKey V.KEsc []) -> halt st
        VtyEvent (V.EvKey V.KRight []) -> goRightTetromino st
        VtyEvent (V.EvKey V.KLeft []) -> goLeftTetromino st  
        VtyEvent (V.EvKey V.KUp []) -> rotateTetrominoSt st  
        VtyEvent (V.EvKey V.KDown []) -> tryGoDownTetromino st
        VtyEvent (V.EvKey (V.KChar ' ') []) -> pushDownTetrominoEvent st  
        VtyEvent _ -> continue st
        AppEvent Counter -> tryGoDownTetromino st
        _ -> continue st

globalDefault :: V.Attr
globalDefault = V.white `on` V.black


theMap :: AttrMap
theMap = attrMap globalDefault
    [ 
        ("general",          V.black `on` V.black),
        ("readyStatus",      V.green `on` V.black),
        ("notReadyStatus",   V.red `on` V.black),
        ("T",                V.blue `on` V.blue),
        ("Z",                V.white `on` V.white),
        ("I",                V.yellow `on` V.yellow),
        ("L",                V.magenta `on` V.magenta),
        ("J",                V.cyan `on` V.cyan),
        ("S",                V.red `on` V.red),
        ("O",                V.green `on` V.green)
    ]

initBoard :: Board
initBoard = Board getRandomTetromino [] 0 0

data CustomEvent = Counter deriving Show

playGame :: Int -> IO St
playGame a = do
    chan <- newBChan 10

    forkIO $ forever $ do
        threadDelay 200000
        writeBChan chan Counter

    game <- customMain (V.mkVty V.defaultConfig) (Just chan) theApp (initialState a)
    return game

getScore :: St -> Int
getScore st = sc
    where
        bd = st^.board
        sc = bd^.score

main :: IO ()
main = do putStrLn $ "it Works"
