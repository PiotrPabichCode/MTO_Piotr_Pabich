#!/usr/bin/env python3

import sys

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
