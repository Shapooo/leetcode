module Codewars.G964.Josephus where

josephusSurvivor :: Int -> Int -> Int
josephusSurvivor n k =
  1 + foldl (mod . (k +)) 0 [2 .. n]

-- josephusSurvivor n k =
--   head (iterate killOne [1 .. n] !! (n - 1))
--   where
--     killOne :: [Int] -> [Int]
--     killOne xs =
--       (take (l - 1) . drop k . cycle) xs
--       where
--         l = length xs
