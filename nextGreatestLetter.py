from typing import List


class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        result = "{"
        f = False
        for l in letters:
            if l < result and l > target:
                f = True
                result = l
        if not f:
            result = letters[0]
        return result

    def nextGreatestLetter2(self, letters: List[str], target: str) -> str:
        return next((letter for letter in letters if letter > target), letters[0])


s = Solution()

letters = ["c", "f", "j"]
target = "a"
print(s.nextGreatestLetter(letters, target))
letters = ["c", "f", "j"]
target = "c"
print(s.nextGreatestLetter(letters, target))
letters = ["c", "f", "j"]
target = "d"
print(s.nextGreatestLetter(letters, target))
letters = ["c", "f", "j"]
target = "j"
print(s.nextGreatestLetter(letters, target))
letters = [
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "g",
    "h",
    "j",
    "k",
    "l",
    "m",
    "n",
    "o",
    "p",
    "q",
    "r",
    "s",
    "t",
    "u",
    "v",
    "w",
    "x",
    "y",
    "z",
]
target = "y"
print(s.nextGreatestLetter(letters, target))
