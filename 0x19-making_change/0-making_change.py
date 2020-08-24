#!/usr/bin/python3
"""Make change from a pile of coins"""


def makeChange(coins, total):
    """Make change from a pile of coins"""

    coins = sorted(coins, reverse=True)
    index = 0
    count = 0
    while index < len(coins) and total > 0:
        quotient = total // coins[index]
        count += quotient
        total -= coins[index] * quotient
        index += 1
    if total > 0:
        return -1
    return count
