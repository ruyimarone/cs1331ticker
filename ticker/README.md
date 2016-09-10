#Ticker
This is a general purpose script that will cause a given block of text to scroll smoothly across the terminal, if possible.

Running:
```
python ticker.py <num> <filename>
```
Will cause the text in \<filename\> to scroll across the terminal. If \<num\> is not included, the script will scroll until manually stopped. Default scroll rate is around 60fps.
Tabs can cause issues, but blocks of text wider than the terminal will be handled gracefully.

