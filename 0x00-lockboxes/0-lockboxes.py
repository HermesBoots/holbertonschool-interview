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
    newKeys = set(boxes[0])
    allKeys = newKeys.union((0,))
    indexes = set(range(len(boxes)))
    while len(newKeys) > 0:
        index = newKeys.pop()
        if index < 0 or index >= len(boxes):
            continue
        box = set(boxes[index]) - allKeys & indexes
        newKeys |= box
        allKeys |= box
    return len(allKeys) == len(boxes)
