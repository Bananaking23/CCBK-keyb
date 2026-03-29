#include "Adafruit_TinyUSB.h"

// ================= USB HID =================
Adafruit_USBD_HID usb_hid;

uint8_t const desc_hid_report[] = {
  TUD_HID_REPORT_DESC_KEYBOARD()
};

// ================= PINS =================
const int ROW_PINS[6]  = {17, 18, 19, 20, 21, 22};
const int COL_PINS[15] = {
  0, 1, 4, 5, 6, 7, 8,
  9, 10, 11, 12, 13,
  16, 15, 14
};

// ================= CONFIG =================
#define NUM_ROWS 6
#define NUM_COLS 15
#define NUM_LAYERS 2

#define KT_KB 0
#define KT_FN 1
#define KT_NONE 2

struct Key { uint8_t type; uint8_t code; };

// ================= KEYMAP =================
Key keyMap[NUM_LAYERS][NUM_ROWS][NUM_COLS] = {

  // ===== BASE =====
  {
    {
      {KT_KB,HID_KEY_ESCAPE},{KT_KB,HID_KEY_F1},{KT_KB,HID_KEY_F2},{KT_KB,HID_KEY_F3},
      {KT_KB,HID_KEY_F4},{KT_KB,HID_KEY_F5},{KT_KB,HID_KEY_F6},{KT_KB,HID_KEY_F7},
      {KT_KB,HID_KEY_F8},{KT_KB,HID_KEY_F9},{KT_KB,HID_KEY_F10},{KT_KB,HID_KEY_F11},
      {KT_KB,HID_KEY_F12},{KT_NONE,0},{KT_NONE,0}
    },

    {
      {KT_KB,HID_KEY_GRAVE},{KT_KB,HID_KEY_1},{KT_KB,HID_KEY_2},{KT_KB,HID_KEY_3},
      {KT_KB,HID_KEY_4},{KT_KB,HID_KEY_5},{KT_KB,HID_KEY_6},{KT_KB,HID_KEY_7},
      {KT_KB,HID_KEY_8},{KT_KB,HID_KEY_9},{KT_KB,HID_KEY_0},{KT_KB,HID_KEY_MINUS},
      {KT_KB,HID_KEY_EQUAL},{KT_KB,HID_KEY_BACKSPACE},{KT_KB,HID_KEY_DELETE}
    },

    {
      {KT_KB,HID_KEY_TAB},{KT_KB,HID_KEY_Q},{KT_KB,HID_KEY_W},{KT_KB,HID_KEY_E},
      {KT_KB,HID_KEY_R},{KT_KB,HID_KEY_T},{KT_KB,HID_KEY_Y},{KT_KB,HID_KEY_U},
      {KT_KB,HID_KEY_I},{KT_KB,HID_KEY_O},{KT_KB,HID_KEY_P},{KT_KB,HID_KEY_BRACKET_LEFT},
      {KT_KB,HID_KEY_BRACKET_RIGHT},{KT_KB,HID_KEY_BACKSLASH},{KT_KB,HID_KEY_PAGE_UP}
    },

    {
      {KT_KB,HID_KEY_CAPS_LOCK},{KT_KB,HID_KEY_A},{KT_KB,HID_KEY_S},{KT_KB,HID_KEY_D},
      {KT_KB,HID_KEY_F},{KT_KB,HID_KEY_G},{KT_KB,HID_KEY_H},{KT_KB,HID_KEY_J},
      {KT_KB,HID_KEY_K},{KT_KB,HID_KEY_L},{KT_KB,HID_KEY_SEMICOLON},{KT_KB,HID_KEY_APOSTROPHE},
      {KT_KB,HID_KEY_ENTER},{KT_KB,HID_KEY_PAGE_DOWN},{KT_NONE,0}
    },

    {
      {KT_KB,HID_KEY_SHIFT_LEFT},{KT_KB,HID_KEY_Z},{KT_KB,HID_KEY_X},{KT_KB,HID_KEY_C},
      {KT_KB,HID_KEY_V},{KT_KB,HID_KEY_B},{KT_KB,HID_KEY_N},{KT_KB,HID_KEY_M},
      {KT_KB,HID_KEY_COMMA},{KT_KB,HID_KEY_PERIOD},{KT_KB,HID_KEY_SLASH},{KT_KB,HID_KEY_SHIFT_RIGHT},
      {KT_KB,HID_KEY_ARROW_UP},{KT_KB,HID_KEY_END},{KT_NONE,0}
    },

    {
      {KT_KB,HID_KEY_CONTROL_LEFT},
      {KT_KB,HID_KEY_GUI_LEFT},
      {KT_KB,HID_KEY_ALT_LEFT},
      {KT_KB,HID_KEY_SPACE},

      {KT_NONE,0},{KT_NONE,0},{KT_NONE,0},

      {KT_FN,0},

      {KT_KB,HID_KEY_CONTROL_RIGHT},

      {KT_NONE,0},

      {KT_KB,HID_KEY_ARROW_LEFT},
      {KT_KB,HID_KEY_ARROW_DOWN},
      {KT_KB,HID_KEY_ARROW_RIGHT},

      {KT_NONE,0},{KT_NONE,0}
    }
  },

  // ===== FN =====
  {
    {
      {KT_KB,HID_KEY_ESCAPE},{KT_KB,HID_KEY_F1},{KT_KB,HID_KEY_F2},{KT_KB,HID_KEY_F3},
      {KT_KB,HID_KEY_F4},{KT_KB,HID_KEY_F5},{KT_KB,HID_KEY_F6},{KT_KB,HID_KEY_F7},
      {KT_KB,HID_KEY_F8},{KT_KB,HID_KEY_F9},{KT_KB,HID_KEY_F10},{KT_KB,HID_KEY_F11},
      {KT_KB,HID_KEY_F12},{KT_NONE,0},{KT_NONE,0}
    },

    {
      {KT_KB,HID_KEY_GRAVE},{KT_KB,HID_KEY_1},{KT_KB,HID_KEY_2},{KT_KB,HID_KEY_3},
      {KT_KB,HID_KEY_4},{KT_KB,HID_KEY_5},{KT_KB,HID_KEY_6},{KT_KB,HID_KEY_7},
      {KT_KB,HID_KEY_8},{KT_KB,HID_KEY_9},{KT_KB,HID_KEY_0},{KT_KB,HID_KEY_MINUS},
      {KT_KB,HID_KEY_EQUAL},{KT_KB,HID_KEY_BACKSPACE},{KT_KB,HID_KEY_DELETE}
    },

    {
      {KT_KB,HID_KEY_TAB},{KT_KB,HID_KEY_Q},{KT_KB,HID_KEY_W},{KT_KB,HID_KEY_E},
      {KT_KB,HID_KEY_R},{KT_KB,HID_KEY_T},{KT_KB,HID_KEY_Y},{KT_KB,HID_KEY_U},
      {KT_KB,HID_KEY_I},{KT_KB,HID_KEY_O},{KT_KB,HID_KEY_P},{KT_KB,HID_KEY_BRACKET_LEFT},
      {KT_KB,HID_KEY_BRACKET_RIGHT},{KT_KB,HID_KEY_BACKSLASH},{KT_KB,HID_KEY_HOME}
    },

    {
      {KT_KB,HID_KEY_CAPS_LOCK},{KT_KB,HID_KEY_A},{KT_KB,HID_KEY_S},{KT_KB,HID_KEY_D},
      {KT_KB,HID_KEY_F},{KT_KB,HID_KEY_G},{KT_KB,HID_KEY_H},{KT_KB,HID_KEY_J},
      {KT_KB,HID_KEY_K},{KT_KB,HID_KEY_L},{KT_KB,HID_KEY_SEMICOLON},{KT_KB,HID_KEY_APOSTROPHE},
      {KT_KB,HID_KEY_ENTER},{KT_KB,HID_KEY_END},{KT_NONE,0}
    },

    {
      {KT_KB,HID_KEY_SHIFT_LEFT},{KT_KB,HID_KEY_Z},{KT_KB,HID_KEY_X},{KT_KB,HID_KEY_C},
      {KT_KB,HID_KEY_V},{KT_KB,HID_KEY_B},{KT_KB,HID_KEY_N},{KT_KB,HID_KEY_M},
      {KT_KB,HID_KEY_COMMA},{KT_KB,HID_KEY_PERIOD},{KT_KB,HID_KEY_SLASH},{KT_KB,HID_KEY_SHIFT_RIGHT},
      {KT_KB,HID_KEY_PAGE_UP},{KT_KB,HID_KEY_END},{KT_NONE,0}
    },

    {
      {KT_KB,HID_KEY_CONTROL_LEFT},
      {KT_KB,HID_KEY_GUI_LEFT},
      {KT_KB,HID_KEY_ALT_LEFT},
      {KT_KB,HID_KEY_SPACE},

      {KT_NONE,0},{KT_NONE,0},{KT_NONE,0},

      {KT_FN,0},

      {KT_KB,HID_KEY_CONTROL_RIGHT},

      {KT_NONE,0},

      {KT_KB,HID_KEY_HOME},
      {KT_KB,HID_KEY_PAGE_DOWN},
      {KT_KB,HID_KEY_END},

      {KT_NONE,0},{KT_NONE,0}
    }
  }
};

// ================= STATE =================
bool keyStates[NUM_ROWS * NUM_COLS] = {false};
unsigned long lastPress[NUM_ROWS * NUM_COLS] = {0};
const unsigned long DEBOUNCE_MS = 10;

int currentLayer = 0;

// ================= SETUP =================
void setup() {
  usb_hid.setReportDescriptor(desc_hid_report, sizeof(desc_hid_report));
  usb_hid.begin();

  for (int r = 0; r < NUM_ROWS; r++) {
    pinMode(ROW_PINS[r], OUTPUT);
    digitalWrite(ROW_PINS[r], HIGH);
  }

  for (int c = 0; c < NUM_COLS; c++) {
    pinMode(COL_PINS[c], INPUT_PULLUP);
  }
}

// ================= LOOP =================
void loop() {
  scanMatrix();
}

// ================= MATRIX =================
void scanMatrix() {
  unsigned long now = millis();

  for (int r = 0; r < NUM_ROWS; r++) {
    digitalWrite(ROW_PINS[r], LOW);
    delayMicroseconds(5);

    for (int c = 0; c < NUM_COLS; c++) {
      int idx = r * NUM_COLS + c;
      bool pressed = (digitalRead(COL_PINS[c]) == LOW);

      if (pressed && !keyStates[idx] && (now - lastPress[idx] > DEBOUNCE_MS)) {
        keyStates[idx] = true;
        lastPress[idx] = now;
        pressKey(r, c);
      }
      else if (!pressed && keyStates[idx]) {
        keyStates[idx] = false;
        releaseKey(r, c);
      }
    }

    digitalWrite(ROW_PINS[r], HIGH);
  }
}

// ================= HID =================
uint8_t keyReport[6] = {0};

void sendReport() {
  usb_hid.keyboardReport(0, 0, keyReport);
}

void pressKey(int r, int c) {
  Key k = keyMap[currentLayer][r][c];

  if (k.type == KT_FN) {
    currentLayer = 1;
    return;
  }

  if (k.type == KT_NONE) return;

  for (int i = 0; i < 6; i++) {
    if (keyReport[i] == 0) {
      keyReport[i] = k.code;
      break;
    }
  }

  sendReport();
}

void releaseKey(int r, int c) {
  Key k = keyMap[currentLayer][r][c];

  if (k.type == KT_FN) {
    currentLayer = 0;
    return;
  }

  if (k.type == KT_NONE) return;
  for (int i = 0; i < 6; i++) {
    if (keyReport[i] == k.code) {
      keyReport[i] = 0;
    }
  }
  
  sendReport();
}