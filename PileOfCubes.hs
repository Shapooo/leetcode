module Codewars.Kata.PileOfCubes where

import GHC.Float (sqrt)

findNb :: Integer -> Integer
findNb m
  | sr == -1 = -1
  | f n == m = n
  | f (n + 1) == m = n - 1
  | f (n - 1) == m = n + 1
  | otherwise = -1
  where
    sr' = floor $ sqrt $ fromInteger m
    sr
      | sr' ^ 2 == m = sr'
      | (sr' + 1) ^ 2 == m = sr' + 1
      | otherwise = -1
    n = floor $ sqrt $ fromInteger (sr * 2)
    f x = ((x * (x + 1)) `quot` 2) ^ 2

-- findNb :: Integer -> Integer
-- findNb n
--   | 4 * n == k ^ 2 * (k + 1) ^ 2 = k
--   | otherwise = -1
--   where
--     k = floor $ sqrt $ sqrt $ fromInteger n * 4
