#!/bin/bash
echo "set LED red"
amba_debug -g 152 -d 0x0
amba_debug -g 3 -d 0x0
amba_debug -g 38 -d 0x1
sleep 1

echo "set LED blue"
amba_debug -g 152 -d 0x0
amba_debug -g 3 -d 0x1
amba_debug -g 38 -d 0x0
sleep 1

echo "set LED GREEN"
amba_debug -g 152 -d 0x1
amba_debug -g 3 -d 0x0
amba_debug -g 38 -d 0x0
sleep 1

echo "set LED White"
amba_debug -g 152 -d 0x1
amba_debug -g 3 -d 0x1
amba_debug -g 38 -d 0x1
sleep 1

echo "set LED OFF"
amba_debug -g 152 -d 0x0
amba_debug -g 3 -d 0x0
amba_debug -g 38 -d 0x0



