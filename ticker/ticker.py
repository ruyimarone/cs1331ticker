import curses
import time
import sys
import os

test = """
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


        #user supplied full args, file and times to tick
        if len(sys.argv) == 3:
            times = int(sys.argv[1])
            if times == -1:
                name = sys.argv[-1]
                #update from dir mode
                if os.path.isdir(name):
                    while True:
                        _, _, filenames = os.walk(name).next()
                        for filename in filenames:
                            curses.wrapper(tick, getFile(name + "/" + filename), times = 1)


                #update single file mode
                else:
                    while True:
                        curses.wrapper(tick, getFile(name), times = 1)

            else:
                #read from file and tick for given times                
                curses.wrapper(tick, getFile(sys.argv[-1]), times = int(times))
        else:
            #read from file and tick for forever
            curses.wrapper(tick, getFile(sys.argv[-1]))

        
