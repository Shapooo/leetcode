module LastDigit where

lastDigitCycle = [1, 1, 4, 4, 2, 1, 1, 4, 4, 2]

lastDigit :: Integer -> Integer -> Integer
lastDigit a b =
  (rem a 10 ^ (rem (b - 1) 4 + 1)) `rem` 10
