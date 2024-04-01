#!/usr/bin/env python
# -*- coding: utf-8 -*-

from multiprocessing import Pool
import time

def f(x):
    return x*x

if __name__ == '__main__':
    with Pool() as p:
        for i in range(1,100):
            time1 = time.time()
            p.map(f, range(i))
            time2 = time.time()
            print('task {} time elapses {}'.format(i, time2 - time1))
