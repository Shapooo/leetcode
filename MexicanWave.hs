module MexicanWave where

import Data.Char (isUpper, toUpper)
import Data.List (inits, tails)

wave :: String -> [String]
wave str =
  filter (any isUpper) $ zipWith (++) (inits str) ((map f . tails) str)
  where
    f (x : xs) = toUpper x : xs
    f [] = []
