#!/bin/sh

if [ $UID != 0 ]; then
    echo "to be run as root"
else
    losetup /dev/loop0 floppy.img
    mount /dev/loop0 mnt
    cp kernel.bin mnt/
    umount /dev/loop0
    losetup -d /dev/loop0
fi

