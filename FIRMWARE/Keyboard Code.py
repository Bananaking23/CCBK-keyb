from kmk.kmk_keyboard import KMKKeyboard
from kmk.keys import KC
from kmk.scanners import DiodeOrientation, DiodeScanner, MCP23017Scanner
from kmk.extensions.rgb import RGB
from kmk.extensions.encoder import RotaryEncoder
from kmk.extensions.media_keys import MediaKeys
import board

keyboard = KMKKeyboard()

# -----------------------
# MATRIX SETUP
# -----------------------

# Rows (GPIO pins on microcontroller)
rows = [board.GP16, board.GP17, board.GP18, board.GP19, board.GP20, board.GP21]

# MCP23017 Columns
# Using GPB0-7, GPA0-6 → 14 columns total
cols = {
    "i2c": board.I2C(scl=board.GP5, sda=board.GP4),  # I2C shared with OLED
    "col_pins": [
        "GPB0", "GPB1", "GPB2", "GPB3", "GPB4", "GPB5", "GPB6", "GPB7",
        "GPA0", "GPA1", "GPA2", "GPA3", "GPA4", "GPA5", "GPA6"
    ]
}

# Use MCP23017 scanner
scanner = MCP23017Scanner(rows=rows, cols=cols, diode_orientation=DiodeOrientation.COL2ROW)
keyboard.scanner = scanner

# -----------------------
# LED SETUP
# -----------------------
keyboard.rgb = RGB(
    pixel_pin=board.GP9,  # LED pin
    num_pixels=1,          # 1 LED
    val_limit=0.3,         # optional brightness limit
)

keyboard.rgb.pixels[0] = (255, 0, 0)  # red as default

# -----------------------
# ROTARY ENCODER SETUP
# -----------------------
encoder_pins = {"switch": board.GP29, "A": board.GP6, "B": board.GP7}
encoder = RotaryEncoder(encoder_pins["A"], encoder_pins["B"], encoder_pins["switch"])

keyboard.extensions.append(encoder)

# -----------------------
# MEDIA KEYS (optional)
# -----------------------
keyboard.extensions.append(MediaKeys())

# -----------------------
# LAYERS AND KEYMAP
# -----------------------
keyboard.keymap = [
    # Layer 0
    [
        KC.A, KC.B, KC.C, KC.D, KC.E, KC.F, KC.G,
        KC.H, KC.I, KC.J, KC.K, KC.L, KC.M, KC.N
    ],
]

# -----------------------
# OLED SETUP (optional)
# -----------------------
# You can add OLED extension here later

# -----------------------
# START KEYBOARD
# -----------------------
if __name__ == "__main__":
    keyboard.go()
