module Kata (highAndLow) where

highAndLow :: String -> String
highAndLow input =
  show theMax ++ ' ' : show theMin
  where
    theMax = maximum intList
    theMin = minimum intList
    intList = (map read . words) input :: [Int]

-- highAndLow = unwords . map show . sequence [maximum,minimum] . map (read ::String->Int) . words
