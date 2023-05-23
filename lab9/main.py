#!/usr/bin/env python3

import sys
import re

def change_number(number):
    out = []
    for i in number:
        if i == '0':
            out.append('a')
        elif i == '1':
            out.append('b')
        elif i == '2':
            out.append('c')
        elif i == '3':
            out.append('d')
        elif i == '4':
            out.append('e')
        elif i == '5':
            out.append('f')
        elif i == '6':
            out.append('g')
        elif i == '7':
            out.append('h')
        elif i == '8':
            out.append('i')
        elif i == '9':
            out.append('j')
        outNumber = ''.join(str(j) for j in out)
        return outNumber

def change_digit(digit):
    digit = int(digit)
    digit = (digit + 5) % 10
    return str(digit)

def change_second_part(number):
    out = []
    for i in number:
        out.append(change_digit(i))
    outNumber = ''.join(str(j) for j in out)
    return outNumber

def my_printf(format_string,param):
    match = re.search("#\.(\d+)h", format_string)
    if not match:
        print(format_string)
        return
    
    given_format = match.group(0)
    given_len = match.group(1)

    param = float(param)
    formatted_number = f"{param:.{given_len}}"

    first = ''
    second = ''

    if '.' in formatted_number:
        first, second = formatted_number.split('.')
    else:
        first = formatted_number
        second = ''

    formatted_number = first + ('.' if second else '') + second

    print(format_string.replace(given_format, formatted_number))

data=sys.stdin.readlines()

for i in range(0,len(data),2):
    my_printf(data[i].rstrip(),data[i+1].rstrip())
