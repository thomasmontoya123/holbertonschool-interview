#!/usr/bin/python3
"""Lockboxes challenge"""


def canUnlockAll(boxes):
    """Determines if all the boxes can be opened"""

    keys = [0]
    for key in keys:
        box = boxes[key]
        for key_box in box:
            if key_box < len(boxes) and key_box not in keys:
                keys.append(key_box)
    if len(boxes) == len(keys):
        return True

    return False
