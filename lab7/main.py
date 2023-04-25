#!/usr/bin/env python3

import sys

def print_changed(number):
    changed = str(hex(int(number)))
    changed = changed.replace('0x','')
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
