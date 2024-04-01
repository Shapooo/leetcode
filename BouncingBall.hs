module Codewars.Kata.BouncingBall where

bouncingBall :: Double -> Double -> Double -> Integer
bouncingBall h b w
  | h > 0 && b < 1 && b > 0 && w < h = result
  | otherwise = -1
  where
    result = ((+ 1) . (* 2) . toInteger . length . takeWhile (> w)) a
    a = h * b : map (* b) a
