--Help the bookseller
module Codewars.Kata.Bookseller where

-- import Codewars.Kata.Bookseller.Types

data Stock = Stock String Int deriving (Show, Eq)

stocklist :: [Stock] -> [Char] -> [(Char, Int)]
stocklist [] _ = []
stocklist _ [] = []
stocklist st cs =
  map f cs
  where
    f c =
      (c, (sum . map (\(Stock _ i) -> i) . filter f1) st)
      where
        f1 (Stock s i) = head s == c

stock = [Stock "ABAR" 200, Stock "CDXE" 500, Stock "BKWR" 250, Stock "BTSQ" 890, Stock "DRTY" 600]

main :: IO ()
main = do
  print $ stocklist stock ['A', 'B']
  print $ stocklist stock ['C', 'X']
  print $ stocklist stock ['Y', 'X']
  print $ stocklist stock ['C']
  print $ stocklist stock []
