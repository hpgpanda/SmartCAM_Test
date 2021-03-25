#!/bin/sh
export PATH="$PATH:/bin:/sbin"

init.sh --na
modprobe imx250 bus_addr=0x10 color=0
test_tuning -a &

modprobe cavalry
cavalry_load -f /lib/firmware/cavalry.bin -r
rmmod ambarella_fb
modprobe ambarella_fb resolution=720x480 mode=clut8bpp

test_encode -i 2432x2048 --hdmi 720p --ors 1280x720 -X --bsize 2432x2048 --bmaxsize 2432x2048

osd_server_yolov3 -p 27182 -t 0.15 &
test_nnctrl_live -b /root/yolo_v3_cavalry_fix8_sp50.bin --in data --out conv59 --out conv67 --out conv75 -p 27182 -s 0 -i 0 -t 1 -r 0.00390625
sleep 1
