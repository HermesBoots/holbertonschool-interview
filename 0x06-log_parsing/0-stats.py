#!/usr/bin/python3
"""Monitor a running server log and track statistics about it"""


import re
import sys


logLine = re.compile(r"""
    ([^\s-]+\s*)? # IP address
    (-\s*) # the weird line
    (\[[^\]]*\]\s+)? # date
    ("[^"]*"\s+)? # request URL
    (\S+)?\s*(\S+)? # status and size""", re.VERBOSE)
outBuf = []
status = {
    '200': 0, '301': 0, '400': 0, '401': 0, '403': 0, '404': 0, '405': 0,
    '500': 0
}
total = 0


def printStats():
    """Print total size transferred and status code statistics from log"""

    while len(outBuf) > 0:
        print(outBuf.pop())


def createRecord():
    """Format record to be printed"""

    outBuf.append(
        'File size: ' + str(total) + '\n' +
        ('\n'.join(
            k + ': ' + str(v) for k, v in sorted(status.items()) if v > 0
        ))
    )


if __name__ == '__main__':
    count = 0
    try:
        for line in sys.stdin:
            match = logLine.match(line)
            if match is None:
                continue
            code = match.groups()[4]
            size = match.groups()[5]
            if code is not None and code.isnumeric() and code in status:
                status[code] += 1
            if size is not None and size.isnumeric():
                total += int(size)
            count += 1
            if count == 10:
                count = 0
                createRecord()
                printStats()
    except KeyboardInterrupt:
        createRecord()
        count = 0
        printStats()
    finally:
        if count != 0 or len(outBuf) == 0:
            createRecord()
        printStats()
