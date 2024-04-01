#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''Given an array of integers and an integer m, return the sum of the product of its subsequences of length m.

Ex1:

a = [1, 2, 3]
m = 2
the subsequences (of length 2) are (1,2) (1,3) (2,3), you should multiply the numbers of each subsequence and take their sum

product_sum = (1*2) + (1*3) + (2*3) #=> 11
Ex2:

a = [2,3,4,5]
m = 3
the subsequences (of length 3) are (2,3,4) (2,4,5) (2,3,5) (3,4,5)

product_sum = (2*3*4) + (2*3*5) + (2*4*5) + (3*4*5) #=> 154
Task:
Write a function `product_sum(a, m)`` that does as described above

The sum can be really large, so return the result in modulo 109+7

Constraints
0 <= A[i] < 1000000

1 <= m <= 20
49 random tests |A| <= 10^4
1 big test |A| = 10^5
m < |A|
'''
