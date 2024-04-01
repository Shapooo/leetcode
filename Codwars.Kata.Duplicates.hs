module Codwars.Kata.Duplicates where

import Data.Char (toLower)
import Data.List (group, sort)

duplicateCount :: String -> Int
duplicateCount =
  length . filter (> 1) . map length . group . sort . map toLower
