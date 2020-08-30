#!/usr/bin/python3
""" Log parsing  module"""

from sys import stdin


def log_parser():
    """
    Reads stdin line by line and computes metrics

        Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1"
        <status code> <file size>
    """
    total_file_size = 0
    status_codes_count = {200: 0, 301: 0, 400: 0, 401: 0,
                          403: 0, 404: 0, 405: 0, 500: 0}

    try:
        for idx, line in enumerate(stdin, 1):
            in_tokens = line.split(" ")
            if len(in_tokens) > 2:
                status_code = int(in_tokens[-2])
                file_size = int(in_tokens[-1])
                total_file_size += file_size

                if status_code in status_codes_count.keys():
                    status_codes_count[status_code] += 1

                if idx % 10:
                    print("File size: {}".format(total_file_size))
                    for status, count in sorted(status_codes_count.items()):
                        if count != 0:
                            print("{}: {}".format(status, count))

    finally:
        print("File size: {}".format(total_file_size))
        for status, count in sorted(status_codes_count.items()):
            if count != 0:
                print("{}: {}".format(status, count))


if __name__ == "__main__":
    log_parser()
