#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.


Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
"""

from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        cost = []
        cur = 0
        for i in grid[0]:
            cur += i
            cost.append(cur)

        width = len(grid[0])
        height = len(grid)

        for i in range(1, height):
            for j in range(width):
                if j == 0:
                    cost[0] += grid[i][0]
                else:
                    a = cost[j] + grid[i][j]
                    b = cost[j - 1] + grid[i][j]
                    cost[j] = min(a, b)

        return cost[-1]


s = Solution()
grid = [[1, 3, 1], [1, 5, 1], [4, 2, 1]]
print(s.minPathSum(grid))

grid = [[1, 2, 3], [4, 5, 6]]
print(s.minPathSum(grid))
