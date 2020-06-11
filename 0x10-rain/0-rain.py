#!/usr/bin/python3
"""If rain fell on a bar graph, how much would it collect?"""


def findPeak(arr, start, right):
    """Find the next peak in the given array"""

    while start < len(arr):
        if (
            (start == 0) or
            (right and arr[start] > arr[start - 1]) or
            (not right and arr[start] >= arr[start - 1])
        ) and (
            (start == len(arr) - 1) or
            (right and arr[start] >= arr[start + 1]) or
            (not right and arr[start] > arr[start + 1])
        ):
            return start
        start += 1
    return -1


def rain(walls):
    """Count the amount of rain that could be collected in a bar graph"""

    left = findPeak(walls, 0, False)
    right = findPeak(walls, left + 1, True)
    result = 0
    while left > -1 and right > -1:
        print(walls[left:right + 1])
        result += min(walls[left], walls[right]) * (right - left - 1)
        result -= sum(walls[left + 1:right])
        print(left, right)
        left = findPeak(walls, right, False)
        right = findPeak(walls, left + 1, True)
    return result
