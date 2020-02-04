#!/usr/bin/python3

def canUnlockAll(boxes):
    """Determine whether keys for all boxes are accessible."""
    if (
        not isinstance(boxes, list) or
        not all(isinstance(box, list) for box in boxes) or
        not all(isinstance(index, int) for box in boxes for index in box)
    ):
        return False
    newKeys = set(boxes[0])
    keys = newKeys.union((0,))
    indexes = set(range(len(boxes)))
    while len(newKeys) > 0:
        index = newKeys.pop()
        if index < 0 or index >= len(boxes):
            continue
        box = set(boxes[index]) - keys & indexes
        newKeys |= box
        keys |= box
    return len(keys) == len(boxes)
