from pynput import keyboard
from pynput.keyboard import Key, Controller

keyboard = Controller()

import time as t
keyboard.press('a')
keyboard.press('a')
keyboard.press('a')


keyboard.release('a')
keyboard.release('a')
keyboard.release('a')

