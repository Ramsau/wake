from Py_Keyboard.HID import Keyboard
import time

kbd = Keyboard()

kbd.press("ALT F2")
time.sleep(1)
kbd.write('teamviewer\n')
