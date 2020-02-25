#!/usr/bin/python3
"""Minimum copy and paste operations"""

import itertools


def minOperations(n):
    """Find the minimum number of "copy all" and "pastes" needed to get n"""
    if n < 2:
        return 0
    dividend = n
    ret = 0
    for divisor in itertools.count(2):
        while dividend % divisor == 0:
            dividend /= divisor
            ret += divisor
        if dividend == 1:
            return ret
