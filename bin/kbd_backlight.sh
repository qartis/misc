#!/bin/sh
file=/sys/class/leds/tpacpi::kbd_backlight/brightness
maxval=3
val=$(cat $file)
newval=$((($val + 1) % $maxval))
echo $newval | sudo tee $file
