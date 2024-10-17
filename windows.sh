#!/bin/bash

python "${BASH_SOURCE%/*}/pressButton.py"
sleep 8
python3 "${BASH_SOURCE%/*}/switchBootWin.py"
sleep 60
python3 "${BASH_SOURCE%/*}/sendSpace.py"
sleep 1
python3 "${BASH_SOURCE%/*}/sendPW.py"
sleep 5
python3 "${BASH_SOURCE%/*}/teamviewerWindows.py"
