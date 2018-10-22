{-# LANGUAGE OverloadedStrings #-}
{-# LANGUAGE TemplateHaskell #-}
{-# LANGUAGE CPP #-}

module Main where
import System.IO
import System.IO.Unsafe  
import System.Random


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
