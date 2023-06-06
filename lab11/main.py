#!/usr/bin/env python3

import sys
import re

look_up_table = ['a','b','c','d','e','f','g','h','i','j']

def convert_param(value):
    output = []
    value = value[::-1]
    pos = 0
    for i in value:
        if x == '1':
            output.append(look_up_table[pos%10])
        else:
            output.append('0')
        pos += 1
    out_s = ''.join(str(i) for i in output)
    return out_s[::-1]

def my_printf(format_string,param):
    match = re.search("#b", format_string)
    if not match:
        print(format_string)
        return
    
    value = bin(int(param))[2:]
    converted_value = convert_param(value)
    out_s = format_string.replace(match.group(), converted_value)
    print(out_s)

data=sys.stdin.readlines()

for i in range(0,len(data),2):
    my_printf(data[i].rstrip(),data[i+1].rstrip())
