import os
import time
rows, columns = map(int, os.popen('stty size', 'r').read().split())
data = [[" " for i in range(columns)] for i in range(rows)]
clearString = "\n" * (columns + 1)

def disp(data):
    print("\n".join(["".join(row) for row in data]))

def clear():
    os.system("clear")
    print("\n")

def write(y, x, word, data):
    for i, l in enumerate(word):
        data[y][x + i] = l

def shiftRight(data):
    for r, row in enumerate(data):
        for c, l in enumerate(row[1:] + [row[0]]):
            data[r][c] = l

def tick(data, rate):
    while True:
        disp(data)
        shiftRight(data)
        time.sleep(rate)
        clear()

write(5, 30, "CS 1331 is the best!", data)
clear()
tick(data, 0.5)

