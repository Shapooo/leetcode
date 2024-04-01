module Codewars.Kata.PP (isPP) where

import Data.List (group, head)

isPP :: Integer -> Maybe (Integer, Integer)
isPP i =
  f 2 2
  where
    f b p
      | b ^ p == i = Just (b, p)
      | b ^ p < i = f b (p + 1)
      | p > 2 = f (b + 1) 2
      | otherwise = Nothing

--   f [x | x <- [2 ..], x * x <= i]
--   where
--     f :: [Integer] -> Maybe (Integer, Integer)
--     f [] = Nothing
--     f (x : xs) =
--       let (t, b) = isThePP i x
--        in if b then Just (x, t) else f xs

-- isThePP :: Integer -> Integer -> (Integer, Bool)
-- isThePP i n =
--   f i n 0
--   where
--     f a b t
--       | a == b = (t + 1, True)
--       | rem a b == 0 = f (quot a b) n (t + 1)
--       | otherwise = (0, False)

-- isPP' :: Integer -> Bool
-- isPP' i =
--   any (isThePP i) [x | x <- [2 ..], x * x <= i]

--   if e == 1 && c /= 1 then Just (d, c) else Nothing
--   where
--     factorsGroup :: [[Integer]]
--     factorsGroup = group $ primeFactors i
--     a = map length factorsGroup
--     b = group a
--     c = toInteger $ head a
--     d = product $ map head factorsGroup
--     e = length b

-- factorize :: Integer -> Integer -> [Integer]
-- factorize _ 1 = []
-- factorize d n
--   | d * d > n = [n]
--   | n `mod` d == 0 = d : factorize d (n `div` d)
--   | otherwise = factorize (d + 1) n

-- primeFactors :: Integer -> [Integer]
-- primeFactors =
--   factorize 2

-- | length h /= 1 && product h == i = Just (head h, power)
-- | otherwise = Nothing
-- where
--   h = (map product . sequence . group . primeFactors) i
--   power = toInteger $ length h

-- | (length lengths /= 1 && (length . group) lengths == 1)
--     || (length lengths == 1 && head lengths /= 1) =
--   Just ((product . map head) factors, head lengths)
-- | otherwise = Nothing
-- where
--   factors = (group . primeFactors) i
--   lengths = map (toInteger . length) factors
