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

main :: IO ()
main = do putStrLn $ "it Works"