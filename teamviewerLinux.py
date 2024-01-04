from Py_Keyboard.HID import Keyboard
import time

kbd = Keyboard()

kbd.press("CONTROL ALT T")
time.sleep(1)
kbd.write('teamviewer\n')
