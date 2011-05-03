#!/bin/sh

if [ $UID != 0 ]; then
    echo "to be run as root"
else
umount /dev/loop0
losetup -d /dev/loop0
fi
