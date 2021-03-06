#!/bin/bash
echo "set GPIO OUT1 low"
amba_debug -g 153 -d 0x0
#cat /sys/kernel/debug/gpio | grep gpio-143
cat /sys/kernel/debug/gpio | grep gpio-143 | awk '{if($6=="lo") print "\033[0;32m PASS"; else print "\033[1;31m FAIL"}'
printf "\033[1;37m"
sleep 1
echo "set GPIO OUT1 high"
amba_debug -g 153 -d 0x1
#cat /sys/kernel/debug/gpio | grep gpio-143
cat /sys/kernel/debug/gpio | grep gpio-143 | awk '{if($6=="hi") print "\033[0;32m PASS"; else print "\033[1;31m FAIL"}'
printf "\033[1;37m"
sleep 1

echo "set GPIO OUT2 low"
amba_debug -g 140 -d 0x0
#cat /sys/kernel/debug/gpio | grep gpio-143
cat /sys/kernel/debug/gpio | grep gpio-143 | awk '{if($6=="lo") print "\033[0;32m PASS"; else print "\033[1;31m FAIL"}'
printf "\033[1;37m"
sleep 1
echo "set GPIO OUT2 high"
amba_debug -g 140 -d 0x1
#cat /sys/kernel/debug/gpio | grep gpio-143
cat /sys/kernel/debug/gpio | grep gpio-143 | awk '{if($6=="hi") print "\033[0;32m PASS"; else print "\033[1;31m FAIL"}'
printf "\033[1;37m"
