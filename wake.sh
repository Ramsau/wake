#!/bin/bash
{
echo "2" > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio2/direction
}

cmd="`wget -qO- https://christophroyer.com/toys/remote-boot/9970eda7-6f3b-4fb1-9390-4a344feefcd6`"

if [[ $cmd = "Linux" ]]; then
	source "${BASH_SOURCE%/*}/linux.sh"
elif [[ $cmd = "LinuxVNC" ]]; then
	source "${BASH_SOURCE%/*}/linuxVNC.sh"
elif [[ $cmd = "Windows" ]]; then
	source "${BASH_SOURCE%/*}/windows.sh"
elif [[ $cmd = "TakeImage" ]]; then
	source "${BASH_SOURCE%/*}/takeImage.sh"
elif [[ $cmd = "ForceShutdown" ]]; then
	source "${BASH_SOURCE%/*}/forceShutdown.sh"
else
	echo "${BASH_SOURCE%/*}/forceShutdown.sh"
fi
