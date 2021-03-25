#!/bin/bash
while true
do
	echo -e "\n"
	echo -e "============================================================================================="
	echo "[0] update firmware."
	echo "[1] read version."
	echo "[2] test the GPIO."
	echo "[3] test LED function."
	echo "[4] test ttyS1 send function."
	echo "[5] test ttyS1 receive function."
	echo "[6] test usb device."
	echo "[7] test imx316."
	echo "[8] disable autorun_welcome.service."
	echo "[9] enable autorun_welcome.service"
	echo "[b] burning test"
	echo "[f] format /data"
	echo "[g] run gpt test."
	echo "[r] reboot."
	echo "[q] quit."
	echo -e "=============================================================================================\n"
	echo -e "\n"

	read com

	case $com in
	0)
		/sdcard/pvt/test-shell/update.sh
		;;
	1)
		cat /proc/edge_version 
		mount | grep /data
		;;
	2)
		/sdcard/pvt/test-shell/gpio.sh
		;;
	3)
		/sdcard/pvt/test-shell/led.sh
		;;
	4)	
		/sdcard/pvt/test-shell/tty.sh
		;;
	5)
		cat /dev/ttyS1 &
		;;
	6)
		printf "\033[1;31;40m"
		lsusb
		printf "\033[0m"
		;;
	8)	
		systemctl mask autorun_welcome.service
		;;
	7)
		/sdcard/pvt/test-shell/0144-316.sh
		;;
	9)	
		systemctl unmask autorun_welcome.service
		;;
	b)
		/sdcard/pvt/test-shell/burning.sh
		;;
	f)
		pkill /data/easyToolQml
		umount /data
		mkfs.ext4 /dev/mmcbl0p8
		;;
	g)	
		/sdcard/pvt/test-shell/gpt.sh
		;;
	r)	
		reboot
		;;
	q)	
		exit 0
		;;
	esac
done

