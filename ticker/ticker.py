import curses
import time
import sys
test ="""
  _____      _      ____       ___    _   _     ____    _   _   _____  __   __    
 |_   _|    / \    / ___|     / _ \  | \ | |   |  _ \  | | | | |_   _| \ \ / /  _ 
   | |     / _ \   \___ \    | | | | |  \| |   | | | | | | | |   | |    \ V /  (_)
   | |    / ___ \   ___) |   | |_| | | |\  |   | |_| | | |_| |   | |     | |    _ 
   |_|   /_/   \_\ |____/     \___/  |_| \_|   |____/   \___/    |_|     |_|   (_)

"""

def tick(screen, string, starty = 0, rate = 0.016):
    curses.curs_set(0)
    maxy, maxx = screen.getmaxyx()
    
    def wrapLine(line, y, x):
        lim = min(len(line), maxx - x)
        screen.addstr(y, max(x, 0), line[abs(min(x, 0)):lim] + " ") 

    data = string.split("\n")
    if len(data) > maxy:
        raise Exception("Too many rows in the data and not enough screen space!")
    maxline = max([len(line) for line in data])

    x = maxx - 1
    y = starty
    while True:
        for i, line in enumerate(data):
            wrapLine(line, y + i, x)

        if x < -maxline:
            x = maxx

        x -= 1

        screen.refresh()
        time.sleep(rate)

if __name__ == "__main__":
    if len(sys.argv) == 1:
        curses.wrapper(tick, test)
    else:
        string = ""
        with open(sys.argv[1], 'r') as f:
            string = f.read()
        curses.wrapper(tick, string)

