module Codewars.G964.DblLinear where

import Data.Set

l = 1 : concatMap (\x -> [x * 2 + 1, x * 3 + 1]) l

dblLinear :: Int -> Integer
dblLinear n =
  helper n (singleton 1)
  where
    helper :: Int -> Set Integer -> Integer
    helper m s
      | m == 0 = elemAt 0 s
      | otherwise =
        let x = elemAt 0 s
         in helper (m - 1) ((insert (x * 3 + 1) . insert (x * 2 + 1) . deleteAt 0) s)
