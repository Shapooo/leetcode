# -*- coding: utf-8 -*-
"""72. Edit Distance
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character


Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
"""


class Solution:

    def minDistance(self, word1: str, word2: str) -> int:
        dp = []
        len1 = len(word1)
        len2 = len(word2)

        if not word1:
            return len2
        if not word2:
            return len1

        if len1 > len2:
            len1, len2 = len2, len1
            word1, word2 = word2, word1

        dp.append(list(range(len2 + 1)))

        for i in range(1, len1 + 1):
            dp.append([i])
            for j in range(1, len2 + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i].append(dp[i - 1][j - 1])
                else:
                    dp[i].append(
                        min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1)

        return dp[-1][-1]

    def minDistance2(self, word1: str, word2: str) -> int:

        def help(word1: str, word2: str) -> int:
            # print(f"{word1} {word2}")
            if not word1:
                return len(word2)
            if not word2:
                return len(word1)
            a = help(word1[1:], word2) + 1
            b = help(word1, word2[1:]) + 1
            c = help(word1[1:], word2[1:])
            if word1[0] != word2[0]:
                c += 1
            return min(a, b, c)

        return help(word1, word2)


s = Solution()
word1 = "horse"
word2 = "ros"
print(s.minDistance(word1, word2))

word1 = "intention"
word2 = "execution"
print(s.minDistance(word1, word2))
