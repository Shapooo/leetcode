module Kata (findOutlier) where

findOutlier :: [Int] -> Int
findOutlier xs
  | length evens == 1 = head evens
  | otherwise = (head . filter odd) xs
  where
    evens = filter even xs
