module ConvertCase where

import Data.Char (isUpper, toLower, toUpper)

changeCase :: String -> String -> Maybe String
changeCase xs ys =
  toTransformer <*> (fromTransformer <*> Just xs)
  where
    fromTransformer
      | checkSnake xs = Just (fromSnake . ('S' :))
      | checkCamel xs = Just (fromCamel . ('S' :))
      | checkKebab xs = Just (fromKebab . ('S' :))
      | otherwise = Nothing

    toTransformer
      | ys == "snake" = Just (snakePost . toSnake)
      | ys == "kebab" = Just (kebabPost . toKebab)
      | ys == "camel" = Just (camelPost . toCamel)
      | otherwise = Nothing

snakePost :: String -> String
snakePost (x : y : xs)
  | y == '_' = xs
  | otherwise = y : xs
snakePost _ = []

kebabPost :: String -> String
kebabPost (x : y : xs)
  | y == '-' = xs
  | otherwise = y : xs
kebabPost _ = []

camelPost :: String -> String
camelPost = tail

toSnake :: [String] -> String
toSnake =
  unwordsWith '_' . map uncapitalize

toCamel :: [String] -> String
toCamel =
  concatMap capitalize

toKebab :: [String] -> String
toKebab =
  unwordsWith '-' . map uncapitalize

checkSnake :: String -> Bool
checkSnake xs =
  -- elem '_' xs && notElem '-' xs
  -- elem '-' xs && notElem '_' xs &&
  all (\c -> c /= '-' && (not . isUpper) c) xs && elem '_' xs

checkKebab :: String -> Bool
checkKebab xs =
  all (\c -> c /= '_' && (not . isUpper) c) xs && elem '-' xs

checkCamel :: String -> Bool
checkCamel =
  all (\c -> c /= '-' && c /= '_')

fromCamel :: String -> [String]
fromCamel =
  words . foldr (\c b -> if isUpper c then ' ' : c : b else c : b) []

fromSnake :: String -> [String]
fromSnake =
  words . map f
  where
    f c = if c == '_' then ' ' else c

fromKebab :: String -> [String]
fromKebab =
  words . map f
  where
    f c = if c == '-' then ' ' else c

capitalize :: String -> String
capitalize =
  maniHead toUpper

uncapitalize :: String -> String
uncapitalize =
  maniHead toLower

maniHead :: (a -> a) -> [a] -> [a]
maniHead f (x : xs) = f x : xs
maniHead _ [] = []

unwordsWith :: Char -> [String] -> String
unwordsWith _ [] = []
unwordsWith c xs =
  (tail . concatMap (c :)) xs
