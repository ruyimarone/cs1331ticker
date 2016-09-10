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

def tick(screen, string, starty = 0, rate = 0.016, times = 0):
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
    t = 0
    while times == 0 or t < times:
        for i, line in enumerate(data):
            wrapLine(line, y + i, x)

        if x < -maxline:
            if times != 0:
                t += 1
            x = maxx

        x -= 1

        screen.refresh()
        time.sleep(rate)


if __name__ == "__main__":
    #no file, debug mode
    if len(sys.argv) == 1:
        curses.wrapper(tick, test, 0, 0.016, 3)
    else: 
        def getFile(name):
            string = ""
            with open(name, 'r') as f:
                string = f.read()
            return string

        string = getFile(sys.argv[-1])

        #full args, times and file
        if len(sys.argv) == 3:
            times = int(sys.argv[1])
            if times == -1:
                #update from file each time
                name = sys.argv[-1]
                while True:
                    string = getFile(name) 
                    curses.wrapper(tick, string, times = 1)
            else:
                #file and positive times
                curses.wrapper(tick, string, times = int(times))
        else:
            #just the file, run forever
            curses.wrapper(tick, string)
        
