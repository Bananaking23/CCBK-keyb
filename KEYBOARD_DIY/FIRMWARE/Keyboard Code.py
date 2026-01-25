from kmk.kmk_keyboard import KMKKeyboard
from kmk.keys import KC
from kmk.scanners import DiodeOrientation, DiodeScanner
from kmk.extensions.rgb import RGB
from kmk.modules.oled import OLED
import board

keyboard = KMKKeyboard()

# ------------------------
# MATRIX CONFIGURATION
# ------------------------
rows = [board.GP17, board.GP18, board.GP19, board.GP20, board.GP21, board.GP22]
cols = [
    board.GP0, board.GP1, board.GP4, board.GP5, board.GP6, board.GP7,
    board.GP8, board.GP9, board.GP10, board.GP11, board.GP12, board.GP13,
    board.GP14, board.GP15, board.GP16
]

scanner = DiodeScanner(rows=rows, cols=cols, diode_orientation=DiodeOrientation.COL2ROW)
keyboard.scanner = scanner

# ------------------------
# RGB CONFIGURATION
# ------------------------
keyboard.rgb = RGB(
    pixel_pin=board.GP26,    # SK6812 data pin
    num_pixels=80,           # Total number of LEDs
    val_limit=128            # Optional: lower brightness for power
)

keyboard.rgb.mode = 1  # simple breathing effect

# ------------------------
# OLED CONFIGURATION
# ------------------------
oled_ext = OLED(
    width=128,
    height=32,
    i2c_bus=0,
    i2c_sda=board.GP2,
    i2c_scl=board.GP3
)
keyboard.modules.append(oled_ext)

# ------------------------
# FULL KEYMAP
# ------------------------
keyboard.keymap = [
    [KC.ESC, KC.F1, KC.F2, KC.F3, KC.F4, KC.F5, KC.F6, KC.F7, KC.F8, KC.F9, KC.F10, KC.F11, KC.F12, KC.PRNT, KC.SCRL],
    [KC.GRAVE, KC.1, KC.2, KC.3, KC.4, KC.5, KC.6, KC.7, KC.8, KC.9, KC.0, KC.MINS, KC.EQL, KC.BSPC, KC.INS],
    [KC.TAB, KC.Q, KC.W, KC.E, KC.R, KC.T, KC.Y, KC.U, KC.I, KC.O, KC.P, KC.LBRC, KC.RBRC, KC.BSLS, KC.DEL],
    [KC.CAPS, KC.A, KC.S, KC.D, KC.F, KC.G, KC.H, KC.J, KC.K, KC.L, KC.SCLN, KC.QUOT, KC.ENTER, KC.HOME, KC.END],
    [KC.LSHIFT, KC.Z, KC.X, KC.C, KC.V, KC.B, KC.N, KC.M, KC.COMM, KC.DOT, KC.SLSH, KC.RSHIFT, KC.UP, KC.PGUP, KC.PGDN],
    [KC.LCTRL, KC.LGUI, KC.LALT, KC.SPC, KC.RALT, KC.RGUI, KC.MENU, KC.RCTRL, KC.LEFT, KC.DOWN, KC.RIGHT, KC.NO, KC.NO, KC.NO, KC.NO]
]

if __name__ == "__main__":
    keyboard.go()
