#!/usr/bin/python3

def canUnlockAll(boxes):
    newKeys = set(boxes[0])
    keys = newKeys.union((0,))
    while len(newKeys) > 0:
        index = newKeys.pop()
        box = set(boxes[index]) - keys
        newKeys |= box
        keys |= box
    return len(keys) == len(boxes)
