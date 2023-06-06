#!/usr/bin/env python3

import sys

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
    #print(format_string)
    shouldDo=True
    for idx in range(0,len(format_string)):
        if shouldDo:
            if format_string[idx] == '#' and format_string[idx+1] == 'k':
                print(param,end="")
                shouldDo=False
            else:
                print(format_string[idx],end="")
        else:
            shouldDo=True
    print("")

data=sys.stdin.readlines()

for i in range(0,len(data),2):
    my_printf(data[i].rstrip(),data[i+1].rstrip())
