#!/usr/bin/env python3

import sys

def generate_new_number(old_number):
    new_num = int((old_number * 2) / len(str(old_number)))
    if new % 2 == 0:
        return str(new_num)
    return str(hex(new_num)).replace('0x', '')

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