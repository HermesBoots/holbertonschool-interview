#!/usr/bin/python3
"""Solve the N queens problem"""


import sys


def checkQueen(queens, queen):
    """Check if a queen is not attacking the others
    Args:
        queens (list of tuple of int): queens placed so far
        queen (tuple): queen to check
    Returns:
        bool: True if queen can be placed there, False otherwise
    """

    for x, y in queens:
        if y == queen[1]:
            return False
        if abs((y - queen[1]) / (x - queen[0])) == 1:
            return False
    return True


def placeQueen(n, queens, solutions):
    """Try to place the next queen on the board
    Args:
        n (int): number of queens that need to be placed
        queens (list of tuple of int): queens placed so far
        solutions (list of list of list of int): queen positions that work
    """

    if len(queens) == n:
        solutions.append([list(q) for q in queens])
        return
    x = len(queens)
    for y in range(n):
        queen = (x, y)
        if checkQueen(queens, queen):
            queens.append(queen)
            placeQueen(n, queens, solutions)
            queens.pop()


def validate_args():
    """Validate the N queens program's command-line arguments
    Returns:
        int: first command-line argument
    """

    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        sys.exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print('N must be a number')
        sys.exit(1)
    if n < 4:
        print('N must be at least 4')
        sys.exit(1)
    return n


def main():
    """Entry point to N queens program"""

    n = validate_args()
    queens = []
    solutions = []
    placeQueen(n, queens, solutions)
    print('\n'.join(str(s) for s in solutions))


if __name__ == '__main__':
    main()
