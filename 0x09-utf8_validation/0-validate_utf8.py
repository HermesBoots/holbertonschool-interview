#!/usr/bin/python3
"""UTF-8 validation module"""


def validUTF8(data):
    """Validate whether a list of ints is valid UTF-8"""

    if len(data) < 1:
        return True
    if not all(isinstance(i, int) for i in data):
        return False
    index = 0
    while index < len(data):
        if data[index] < 128:
            index += 1
        elif (
            data[index] & 0xE0 == 0xC0 and
            len(data) > index + 1 and
            data[index + 1] & 0xC0 == 0x80
        ):
            index += 2
        elif (
            data[index] & 0xF0 == 0xE0 and
            len(data) > index + 2 and
            data[index + 1] & 0xC0 == 0x80 and
            data[index + 1] & 0xC0 == 0x80
        ):
            index += 3
        elif (
            data[index] & 0xF8 == 0xF0 and
            len(data) > index + 3 and
            data[index + 1] & 0xC0 == 0x80 and
            data[index + 2] & 0xC0 == 0x80 and
            data[index + 3] & 0xC0 == 0x80
        ):
            index += 4
        else:
            return False
    return True
