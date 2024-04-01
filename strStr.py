# -*- coding: utf-8 -*-
"""28. Implement strStr()
Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().


Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
"""


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        next_ = [-1]
        text_len = len(haystack)
        patern_len = len(needle)

        i = 0
        j = -1
        while i < patern_len:
            if j == -1 or needle[i] == needle[j]:
                i += 1
                j += 1
                next_.append(j)
            else:
                j = next_[j]

        result = -1
        i = j = 0
        while i < text_len and j < patern_len:
            if j == -1 or needle[j] == haystack[i]:
                i += 1
                j += 1
            else:
                j = next_[j]

        if j == patern_len:
            result = i - j
        return result


s = Solution()
haystack = "hello"
needle = "ll"
assert s.strStr(haystack, needle) == 2
haystack = "aaaaa"
needle = "bba"
assert s.strStr(haystack, needle) == -1
print("complete")
