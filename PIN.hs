module PIN where

import Data.Char (ord)

adjNums :: [[Char]]
adjNums =
  [ ['0', '8'],
    ['1', '2', '4'],
    ['1', '2', '3', '5'],
    ['2', '3', '6'],
    ['1', '4', '5', '7'],
    ['2', '4', '5', '6', '8'],
    ['3', '5', '6', '9'],
    ['4', '7', '8'],
    ['5', '7', '8', '9', '0'],
    ['6', '8', '9']
  ]

getPINs :: String -> [String]
getPINs (x : xs) = [x' : xs' | x' <- adjNums !! (ord x - 48), xs' <- getPINs xs]
getPINs [] = [[]]
