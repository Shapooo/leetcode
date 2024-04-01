module Rot13 where

import Data.Char

rot13 :: String -> String
rot13 =
  map (\c -> if isLetter c && isAscii c then rot13c c else c)

rot13c :: Char -> Char
rot13c c =
  let b = if isUpper c then 65 else 97
   in (chr . (+ b) . (`rem` 26) . (+ 13) . subtract b . ord) c
