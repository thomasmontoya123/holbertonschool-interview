#!/usr/bin/python3
"""min operations module"""


def minOperations(n):
    """
        calculates the fewest number of operations needed
        Parameters
        ----------
        n : int
        shape (nx, m) contains the input data
    """
    if type(n) != int:
        return 0

    partial_res = []
    i = 2
    while n > 1:
        if n % i == 0:
            partial_res.append(i)
            n //= i
        else:
            i += 1
    res = sum(partial_res)
    return res
