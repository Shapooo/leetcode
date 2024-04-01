module High.JorgeVS.Kata where

import Data.Char (ord)

high :: String -> String
high =
  fst . foldl f ("", 0) . words
  where
    f (r, s) w =
      let s' = score w
       in if s' > s then (w, s') else (r, s)

score :: String -> Int
score =
  sum . map (\c -> ord c - ord 'a' + 1)
