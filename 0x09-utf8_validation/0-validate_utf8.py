#!/usr/bin/python3
"""Utf-8 validator module"""


def validUTF8(data):
    """
    determines if a given data set represents a valid UTF-8 encoding

        :param data: list of integers
    """
    bytes = 0
    mask_1 = 0b10000000
    mask_2 = 0b01000000
    for bit in data:
        mask = 1 << 7
        if bytes == 0:
            while mask & bit:
                bytes += 1
                mask = mask >> 1

            if bytes == 0:
                continue

            if bytes == 1 or bytes > 4:
                return False
        else:
            if not (bit & mask_1 and not (bit & mask_2)):
                return False
        bytes -= 1
    return bytes == 0
