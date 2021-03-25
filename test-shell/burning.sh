#!/bin/bash
export CNN_PATH=/sdcard/pvt/cnn_test

#echo $CNN_PATH
while true
do
	echo -e "\n"
	echo -e "============================================================================================="
#	echo "[1] burning IMX250C."
#	echo "[2] burning IMX250M."
#	echo "[3] burning IMX274C."
#	echo "[4] burning IMX316."
#	echo "[5] copy data."
	echo "[b] burning."
	echo "[d] default setting."
	echo "[r] reboot."
	echo "[q] quit."
	echo -e "=============================================================================================\n"
	echo -e "\n"

	read com

	case $com in
	1)
#		systemctl mask autorun_welcome.service
#       	cp /sdcard/pvt/autorun/test.service /usr/lib/systemd/system/
#       	cp /sdcard/cnn/cnn_test/imx250c.sh /root/test-edge.sh
#		cp /sdcard/cnn/cnn_test/yolo_v3_cavalry_fix8_sp50.bin /root/
#		systemctl enable test.service
		;;
	2)
#		systemctl mask autorun_welcome.service
#		cp /sdcard/pvt/autorun/test.service /usr/lib/systemd/system/
#		cp /sdcard/cnn/cnn_test/imx250m.sh /root/test-edge.sh
#		cp /sdcard/cnn/cnn_test/yolo_v3_cavalry_fix8_sp50.bin /root/
#		systemctl enable test.service
		;;
	3)	
#		systemctl mask autorun_welcome.service
#		cp $CNN_PATH/test.service /usr/lib/systemd/system/
#		cp $CNN_PATH/imx274_cnn.sh /root/test-edge.sh
#		cp $CNN_PATH/yolo_v3_cavalry_fix8_sp50.bin /root/
#		systemctl enable test.service
		;;
	4)
#		systemctl mask autorun_welcome.service
#		cp /sdcard/pvt/autorun/test.service /usr/lib/systemd/system/
#		cp /sdcard/cnn/cnn_test/ar0144.sh /root/test-edge.sh
#		cp /sdcard/cnn/cnn_test/yolo_v3_cavalry_fix8_sp50.bin /root/
#		systemctl enable test.service
		;;
	b)
		systemctl mask autorun_welcome.service
		cp $CNN_PATH/test.service /usr/lib/systemd/system/
		cp $CNN_PATH/cnn_test.sh /root/test-edge.sh
		cp $CNN_PATH/yolo_v3_cavalry_fix8_sp50.bin /root/
		systemctl enable test.service
		;;
	d)
		systemctl disable test.service
		systemctl unmask autorun_welcome.service
		rm /root/test-edge.sh
		rm /usr/lib/systemd/system/test.service
		rm /root/yolo_v3_cavalry_fix8_sp50.bin
		reboot
		;;
	r)	
		reboot
		;;
	q)	
		exit 0
		;;
	esac
done

