#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The maximum sum subarray problem consists in finding the maximum sum of a contiguous subsequence in an array or list of integers:

max_sequence([-2, 1, -3, 4, -1, 2, 1, -5, 4])
# should be 6: [4, -1, 2, 1]
Easy case is when the list is made up of only positive numbers and the maximum sum is the sum of the whole array. If the list is made up of only negative numbers, return 0 instead.

Empty list is considered to have zero greatest sum. Note that the empty list or array is also a valid sublist/subarray.
"""
from typing import List


def max_sequence(arr: List[int]) -> int:
    result = 0
    cur = 0
    for i in arr:
        cur += i
        if cur > result:
            result = cur
        if cur < 0:
            cur = 0
    return result


print(max_sequence([-2, 1, -3, 4, -1, 2, 1, -5, 4]))

assert max_sequence([]) == 0
assert max_sequence([-2, 1, -3, 4, -1, 2, 1, -5, 4]) == 6
