#!/bin/bash
md5sums=
md5sums=`md5sum /sdcard/edge_upgrade.bin | awk '{print $1}'`
echo $md5sums
case $md5sums in 
b4908fa76538706e7ab9e262cb9abb54)
	echo AR0144-PVT-2.0.2.2
	;;
cdea83d8d7bc94fbe34244063fc234b9)
	echo IMX250C-PVT-2.0.2.2
	;;
c7d7ae664c6a590d8c347c542590a4da)
	echo IMX250M-PVT-2.0.2.2
	;;
20c1abd09d2886a5f24ed8743f7c88e6)
	echo IMX274C-PVT-2.0.2.2
	;;
1e250c8e47389635c196cb3958a540e6)
	echo AR0144-PVT-2.0.2.1
	;;
c8ff3ceb99d89d789775e5bf5b0eb02d)
	echo IMX250C-PVT-2.0.2.1
	;;
22787e5d4dee044f1720f71e6b256191)
	echo IMX250M-PVT-2.0.2.1
	;;
f40a279cd2981f350db011df6e6ba516)
	echo IMX274C-PVT-2.0.2.1
	;;
f3cf3b61b0e5f0bcae0f874ecb62283a)
	echo AR0144-DVT
	;;
f1d113f77d1b518dfc1bc7e5c8547766)
	echo IMX250C-DVT
	;;
33dbc3a1935a1c285308670703f7e1bd)
	echo IMX250M-DVT
	;;
71de68d52461813bc1e3dca88f2c620b)
	echo IMX274C-DVT
	;;
*)
	echo Error
	;;
esac
