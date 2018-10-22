{-# LANGUAGE OverloadedStrings #-}
{-# LANGUAGE TemplateHaskell #-}
{-# LANGUAGE CPP #-}

module Main where
import System.IO

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