#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""1143. Longest Common Subsequence
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.


Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.


Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
"""


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        if not text1 or not text2:
            return 0
        len1 = len(text1)
        len2 = len(text2)
        dp = [[0] * len2]

        dp[0][0] = 1 if text1[0] == text2[0] else 0

        for i in range(1, len2):
            dp[0][i] = 1 if dp[0][i - 1] == 1 or text1[0] == text2[i] else 0

        for i in range(1, len1):
            k = 1 if dp[i - 1][0] == 1 or text1[i] == text2[0] else 0
            dp.append([k])

        for i in range(1, len(dp)):
            for j in range(1, len(dp[0])):
                if text1[i] == text2[j]:
                    dp[i].append(dp[i - 1][j - 1] + 1)
                else:
                    dp[i].append(max(dp[i - 1][j], dp[i][j - 1]))
        return dp[-1][-1]

    def longestCommonSubsequence_force(self, text1: str, text2: str) -> int:
        def help(t1: str, t2: str) -> int:
            if not t1 or not t2:
                return 0
            if t1[0] == t2[0]:
                return help(t1[1:], t2[1:]) + 1
            else:
                return max(help(t1[1:], t2), help(t1, t2[1:]))

        return help(text1, text2)


s = Solution()
text1 = "oxcpqrsvwf"
text2 = "shmtulqrypy"
assert s.longestCommonSubsequence(text1, text2) == 2
text1 = "abcde"
text2 = "ace"
assert s.longestCommonSubsequence(text1, text2) == 3
text1 = "abc"
text2 = "abc"
assert s.longestCommonSubsequence(text1, text2) == 3
text1 = "abc"
text2 = "def"
assert s.longestCommonSubsequence(text1, text2) == 0
text1 = "bl"
text2 = "yby"
assert s.longestCommonSubsequence(text1, text2) == 1
