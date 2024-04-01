module Codewars.Kata.Hashtag where

import Data.Char (toUpper)

generateHashtag :: String -> Maybe String
generateHashtag =
  f . ('#' :) . concatMap capitalize . words
  where
    f s =
      let l = length s
       in if l > 140 || l == 1
            then Nothing
            else Just s

capitalize :: String -> String
capitalize (x : xs) =
  toUpper x : xs
capitalize [] = []
