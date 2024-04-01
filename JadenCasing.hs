module JadenCasing where

import Data.Char (isLower)
import System.Directory.Internal.Prelude (toUpper)

toJadenCase :: String -> String
toJadenCase =
  unwords
    . map f
    . words
  where
    f (x : xs) = toUpper x : xs
    f [] = []
