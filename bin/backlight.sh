#!/bin/sh

# xbacklight will show usage if it doesn't like our arguments
xbacklight -time 0 $@ || exit 1

level=$(xbacklight -get)

width=250
height=35
yoff=150

res=$(xdpyinfo | awk '/dimensions:/ {print $2}')
xres=$(echo $res | cut -dx -f1)
yres=$(echo $res | cut -dx -f2)

xpos=$((($xres - $width) / 2))
ypos=$(($yres - $yoff))

echo $level 100 | gdbar -bg black -w 200 | dzen2 -bg '#333333' -tw $width -x $xpos -y $ypos -h $height -p 1 &
