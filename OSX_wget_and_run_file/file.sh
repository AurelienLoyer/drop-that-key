#!/bin/sh

RED='\033[0;31m'
NC='\033[0m' # No Color
printf "I ${RED}love${NC} 🍌\n"

osascript -e 'set volume 7'

sleep 2 # wait 2 second
ffmpeg -f avfoundation -video_size 1280x720 -framerate 30 -i "0" -vframes 1 /tmp/me.jpg

uuencode /tmp/me.jpg me.jpg | mail -s "Photo test" aur.loy@gmail.com
