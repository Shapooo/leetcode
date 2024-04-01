module CamelCase where

import Data.Char (toUpper)

toCamelCase :: String -> String
toCamelCase =
  tail . concatMap capitalize . words . map dashToBlank . ('S' :)
  where
    dashToBlank c =
      if c == '-' || c == '_' then ' ' else c
    capitalize (x : xs) = toUpper x : xs
    capitalize [] = []
