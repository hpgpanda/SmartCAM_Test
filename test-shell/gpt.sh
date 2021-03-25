#!/bin/bash
while true
do
	echo -e "\n"
	echo -e "============================================================================================="
	echo "[1] IMX250C."
	echo "[2] IMX250M."
	echo "[3] IMX274C."
	echo "[4] IMX316."
	echo "[u] update."
	echo "[r] reboot."
	echo "[q] quit."
	echo -e "=============================================================================================\n"
	echo -e "\n"

	read com

	case $com in
	1)
		cp /sdcard/pvt/test-shell/250c.gptx /data/output.gptx
		sync
		sync
		;;
	2)
		cp /sdcard/pvt/test-shell/250m.gptx /data/output.gptx
		sync
		sync
		;;
	3)	
		cp /sdcard/pvt/test-shell/274c.gptx /data/output.gptx
		sync
		sync
		;;
	4)
		cp /sdcard/pvt/test-shell/316.gptx /data/output.gptx
		sync
		sync
		;;
	u)
		cp /sdcard/pvt/test-shell/libGPTRuntime.so /data/
		cp /sdcard/pvt/test-shell/qtPainter /data/
		sync
		;;
	r)	
		reboot
		;;
	q)	
		exit 0
		;;
	esac
done

