#!/usr/bin/python3
"""Module for lockboxes algorithm"""


def canUnlockAll(boxes):
    """Determine whether allKeys for all boxes are accessible."""
    if (
        not isinstance(boxes, list) or
        not all(isinstance(box, list) for box in boxes) or
        not all(isinstance(index, int) for box in boxes for index in box)
    ):
        return False
    indexes = set(range(len(boxes)))
    newKeys = set(boxes[0]) & indexes
    allKeys = newKeys.union((0,))
    while len(newKeys) > 0:
        index = newKeys.pop()
        if index < 0 or index >= len(boxes):
            continue
        box = set(boxes[index]) - allKeys & indexes
        newKeys |= box
        allKeys |= box
    return len(allKeys) == len(boxes)
