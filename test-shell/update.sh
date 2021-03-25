#!/bin/bash
while true
do
	echo -e "\n"
	echo -e "============================================================================================="
	echo "[1] cp & update IMX250C."
	echo "[2] cp & update IMX250M."
	echo "[3] cp & update IMX274C."
	echo "[4] cp & update IMX316."
	echo "[5] copy data."
	echo "[6] check firmware."
	echo "[7] update firmware."
	echo "[r] reboot."
	echo "[q] quit."
	echo -e "=============================================================================================\n"
	echo -e "\n"

	read com

	case $com in
	1)
		cp /sdcard/firmware/2.0.2.2-rc1-p/250C-image/bst_bld_kernel_lnx_release.bin /sdcard/edge_upgrade.bin
		sync
		sync
		rm /sdcard/upgraded
		reboot
		;;
	2)
		cp /sdcard/firmware/2.0.2.2-rc1-p/250M-image/bst_bld_kernel_lnx_release.bin /sdcard/edge_upgrade.bin
		sync
		sync
		rm /sdcard/upgraded
		reboot
		;;
	3)	
		cp /sdcard/firmware/2.0.2.2-rc1-p/274-image/bst_bld_kernel_lnx_release.bin /sdcard/edge_upgrade.bin
		sync
		sync
		rm /sdcard/upgraded
		reboot
		;;
	4)
		cp /sdcard/firmware/2.0.2.2-rc1-p/0144-image/bst_bld_kernel_lnx_release.bin /sdcard/edge_upgrade.bin
		sync
		sync
		rm /sdcard/upgraded
		reboot
		;;
	5)
		umount /dev/mmcblk0p8
		mkfs.ext4 /dev/mmcblk0p8
		mount /dev/mmcblk0p8 /data
		cp /sdcard/data/* /data/
		rm -rf /data/lost\+found/
		reboot
		;;
	6)
		/sdcard/pvt/test-shell/md5.sh
		;;
	7)
		rm /sdcard/upgraded
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

