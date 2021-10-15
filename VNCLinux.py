from Py_Keyboard.HID import Keyboard

kbd = Keyboard()

kbd.press("CONTROL ALT T")
kbd.write('/home/christoph/Documents/vncRemote.sh\n')
