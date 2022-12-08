from pynput import keyboard
from pynput.keyboard import Key, Controller

keyboard = Controller()
keyboard.press(Key.space)
keyboard.release(Key.space)


keyboard.press('a')
keyboard.release('a')

keyboard.press('A')
keyboard.release('A')

keyboard.type('Hello word')
