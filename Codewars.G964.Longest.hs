module Codewars.G964.Longest where

import Data.List (sort)

longest :: [Char] -> [Char] -> [Char]
longest s1 s2 =
  (deduplicate . sort) (s1 ++ s2)
  where
    deduplicate (x : y : xs)
      | x == y = deduplicate (x : xs)
      | otherwise = x : deduplicate (y : xs)
    deduplicate xs = xs
