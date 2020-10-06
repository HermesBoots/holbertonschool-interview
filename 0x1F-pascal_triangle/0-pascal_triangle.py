#!/usr/bin/python3
"""Function to print Pascal's triangle"""


def pascal_triangle(n):
    """Return Pascal's triangle with n rows"""

    ret = []
    for i in range(1, n + 1):
        ret.append([1] * i)
    for y in range(2, n):
        row = ret[y]
        prev = ret[y - 1]
        for x in range(1, len(row) - 1):
            row[x] = prev[x - 1] + prev[x]
    return ret
