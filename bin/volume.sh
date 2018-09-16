#!/bin/sh
show_osd() {
  amixer=$(amixer sget Master | awk -F"[][]" '/dB/ { print $2, $6 }' | tr -d '%')
  level=$(echo $amixer | cut -d' ' -f 1)
  state=$(echo $amixer | cut -d' ' -f 2)

  if [ $state = "off" ]; then
    level=0
  fi

  width=250
  height=35
  yoff=150

  xres=$(xdpyinfo | grep 'dimensions:' | awk '{print $2}' | cut -dx -f1)
  xpos=$((($xres - $width) / 2))
  yres=$(xdpyinfo | grep 'dimensions:' | awk '{print $2}' | cut -dx -f2)
  ypos=$(($yres - $yoff))

  echo $level 100 | gdbar -bg black -w 200 | dzen2 -bg '#333333' -tw $width -x $xpos -y $ypos -h $height -p 1 &
}

# Explicitly unmute if we're changing the volume
if [ ! $1 = "toggle" ]; then
  amixer set Master on
fi

amixer set Master $1
killall -s USR1 slstatus
show_osd
