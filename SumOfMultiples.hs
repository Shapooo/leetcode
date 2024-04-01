module SumOfMultiples where

findSum n =
  sum [x | x <- [3 .. n], x `rem` 3 == 0 || x `rem` 5 == 0]

a = 3 : 5 : concatMap (\x -> [x * 3, x * 5]) a
