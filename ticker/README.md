#Ticker
This is the project repository for the 1331 TA lab and help desk new ticker. It smoothly scrolls any pattern of text across a terminal window. We use it to automatically display the on duty TAs as well as making announcements. 

<a href="http://marcmarone.com/taing.html" target="_blank"><img src="http://marcmarone.com/images/ticker.png" 
alt="ticker" width="600" height="320" border="10" /></a>
<a href="http://marcmarone.com/taing.html" target="_blank"><img src="http://marcmarone.com/images/onduty.png" 
alt="ticker" width="600" height="320" border="10" /></a>
##Usage
This is a general purpose script that will cause a given block of text to scroll smoothly across the terminal, if possible.

Running:
```
python ticker.py <num> <filename>
```
Will cause the text in \<filename\> to scroll across the terminal. If \<num\> is not included, the script will scroll until manually stopped. If \<num\> is -1, the script will attempt to reload the file contents after each cycle. This lets you change output on the fly, without restarting the script.

Default scroll rate is around 60fps.
Tabs can cause issues, but blocks of text wider than the terminal will be handled gracefully.

