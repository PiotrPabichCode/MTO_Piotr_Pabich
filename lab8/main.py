#!/usr/bin/env python3

import sys
import re

def change_number(number, num_len):
    hexValue = int(number)
    strValue = str(hex(hexValue))
    changed = strValue.replace('0x','')
    out = []
    for i in changed:
        if i == 'a':
            out.append('g')
        elif i == 'b':
            out.append('h')
        elif i == 'c':
            out.append('i')
        elif i == 'd':
            out.append('j')
        elif i == 'e':
            out.append('k')
        elif i == 'f':
            out.append('l')
        elif i == '0':
            out.append('o')
        else:
            out.append(i)
    leadingZeros = "o" * max(0, int(num_len) - len(out))
    outNumber = ''.join(str(j) for j in out)
    output = leadingZeros + outNumber
    return output


def my_printf(format_string,param):
    match = re.search("#\.(\d+)j", format_string)
    if not match:
        print(format_string)
        return
    given_format = match.group(0)
    given_len = match.group(1)
    changed_number = change_number(given_format, given_len)

    print(format_string.replace(given_format, changed_number))

data=sys.stdin.readlines()

for i in range(0,len(data),2):
    my_printf(data[i].rstrip(),data[i+1].rstrip())
