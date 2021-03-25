#!/bin/sh
export PATH="$PATH:/bin:/sbin"
Model=`cat /proc/edge_version | grep H/W | cut -d: -f2 | cut -d- -f2`


init.sh --na
case $Model in 
I05C)
	modprobe imx250 bus_addr=0x10 color=1
	;;
I05M)
	modprobe imx250 bus_addr=0x10 color=0
	;;
I08C)
	modprobe imx274_mipi
	;;
R01TH)
	modprobe ar0144_mipi
	;;
esac

test_tuning -a &

modprobe cavalry
cavalry_load -f /lib/firmware/cavalry.bin -r
rmmod ambarella_fb
modprobe ambarella_fb resolution=720x480 mode=clut8bpp

case $Model in
I05C|I05M)
	test_encode -i 2432x2048 --hdmi 720p --ors 1280x720 -X --bsize 2432x2048 --bmaxsize 2432x2048
	;;
I08C)
	test_encode -i 3840x2160 --hdmi 720p --ors 1280x720 -X --bsize 3840x2160 --bmaxsize 3840x2160
	;;
R01TH)
	test_encode -i 0 --hdmi 720p --ors 1280x720
	;;
esac

osd_server_yolov3 -p 27182 -t 0.15 &
test_nnctrl_live -b /root/yolo_v3_cavalry_fix8_sp50.bin --in data --out conv59 --out conv67 --out conv75 -p 27182 -s 0 -i 0 -t 1 -r 0.00390625
sleep 1
