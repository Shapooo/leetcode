module Codewars.Parentheses where

validParentheses :: String -> Bool
validParentheses =
  (== 0) . foldl f 0
  where
    f :: Int -> Char -> Int
    f xs x
      | xs < 0 = -1
      | x == '(' = xs + 1
      | otherwise = xs - 1
