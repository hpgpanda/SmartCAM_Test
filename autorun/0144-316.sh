#!/bin/sh
export PATH="$PATH:/bin:/sbin"

init.sh --yuv480p
modprobe imx316_mipi bus_id=0x3 vinc_id=0x1
modprobe ar0144_mipi bus_id=0x0 vinc_id=0x0
rmmod ambarella_fb
modprobe ambarella_fb mode=clut8bpp resolution=240x180
test_tuning -a &
test_encode --resource-cfg /data/cv22_vin2_240x180_linear_raw_encode.lua --hdmi 720p --ors 720x480 --of hv --raw 1 --enc-raw-yuv 1 --enc-mode 0
test_tof -r --clut-start 25 --clut-end 150 --fb 1 --imx316 -z
