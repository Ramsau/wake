from Py_Keyboard.HID import Keyboard
import time

kbd = Keyboard()

kbd.keysdown('DELETE')
time.sleep(5)
kbd.release_all()
kbd.press('LEFT DOWN')
kbd.press('LEFT_ARROW DOWN_ARROW')
kbd.press('DOWN_ARROW')
kbd.press('DOWN_ARROW')
time.sleep(1)
kbd.press('ENTER')
