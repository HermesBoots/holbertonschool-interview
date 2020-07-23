#!/usr/bin/python3
"""Module to swap dimensions of a 2D matrix"""


def rotate_2d_matrix(matrix: list):
    """Swap the dimensions of a 2D matrix"""

    if not isinstance(matrix, list):
        return
    if len(matrix) < 1 or len(matrix[0]) < 1:
        return
    if not all(isinstance(sub, list) for sub in matrix):
        return
    if not all(isinstance(item, int) for sub in matrix for item in sub):
        return
    if not all(len(sub) == len(matrix) for sub in matrix):
        return
    copy = list(list(sub) for sub in zip(*reversed(matrix)))
    for y in range(len(matrix)):
        for x in range(len(matrix[0])):
            matrix[y][x] = copy[y][x]
