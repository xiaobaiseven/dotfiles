import os
import time
filepath = os.environ['HOME']+"/Pictures/wallpapers/"
cmd = "feh --recursive --bg-fill "
files = os.listdir(filepath)
while True:
    for file in files:
        wppwd = cmd+filepath+file
        os.system(f"{wppwd}")
        time.sleep(60)
