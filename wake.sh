#!/bin/bash

cmd="`wget -qO- https://christophroyer.com/toys/remote-boot/supersecrettoken`"

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
