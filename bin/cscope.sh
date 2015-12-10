#!/bin/sh

cd ~/gfiber-3.3
/usr/bin/find /usr/local/google/home/abf/gfiber-3.3/out/build -type f -regex '.*\.[hc]\|.*\.cpp\|.*\.cc' > cscope.files
cscope -b -q -k
ctags -L cscope.files
notify-send "~/bin/cscope.sh: done" -t 5
