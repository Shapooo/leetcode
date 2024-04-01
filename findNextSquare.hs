module Perfect (findNextSquare) where

findNextSquare :: Integer -> Integer
findNextSquare n =
  hh 0
  where
    hh i
      | i * i == n = (i + 1) * (i + 1)
      | i * i > n = -1
      | otherwise = hh (i + 1)
