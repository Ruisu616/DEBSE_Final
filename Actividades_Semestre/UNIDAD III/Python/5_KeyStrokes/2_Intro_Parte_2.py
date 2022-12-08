from pynput import keyboard
from pynput.keyboard import Key, Controller

keyboard = Controller()

import time as t
keyboard.press('a')

t.sleep(2)

keyboard.release('a')