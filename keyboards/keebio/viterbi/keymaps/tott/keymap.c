#include QMK_KEYBOARD_H
extern rgblight_config_t rgblight_config;

#define _QWERTY 0
#define _FN     1
#define _MEDIA  2
#define _SYS    3

// Macro
enum {
    M_VWQ = SAFE_RANGE,   // vim <esc>:wq<enter>
    M_VW,                 // vim <esc>:w<enter>
};


// unicode / umlauts
enum unicode_names {
    AE,
    AE_U,
    UE,
    UE_U,
    OE,
    OE_U,
    SZ,
    EURO,
};

const uint32_t PROGMEM unicode_map[] = {
    [AE]   = 0x00E4,  // ae
    [AE_U] = 0x00C4,  // Ae
    [UE]   = 0x00FC,  // ue
    [UE_U] = 0x00DC,  // Ue
    [OE]   = 0x00F6,  // oe
    [OE_U] = 0x00D6,  // Oe
    [SZ]   = 0x00DF,  // ae
    [EURO] = 0x20AC,  // euro sign
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ortho_5x14(
KC_GRV,   KC_1,         KC_2,     KC_3,     KC_4,      KC_5,      KC_6,         KC_7,     KC_8,      KC_9,         KC_0,     KC_MINS,      KC_EQL,   KC_BSPC,
KC_TAB,   KC_Q,         KC_W,     KC_E,     KC_R,      KC_T,      KC_LBRC,      KC_RBRC,  KC_Y,      KC_U,         KC_I,     KC_O,         KC_P,     KC_BSLS,
KC_ESC,   KC_A,         KC_S,     KC_D,     KC_F,      KC_G,      KC_HOME,      KC_DEL,   KC_H,      KC_J,         KC_K,     KC_L,         KC_SCLN,  KC_QUOT,
KC_LSFT,  KC_Z,         KC_X,     KC_C,     KC_V,      KC_B,      KC_END,       KC_RSFT,  KC_N,      KC_M,         KC_COMM,  KC_DOT,       KC_SLSH,  KC_ENT,
KC_LCTL,  KC_LGUI,      MO(1),    MO(2),    TO(1),     KC_LALT,   KC_SPC,       KC_SPC,   MO(1),     TO(3),        KC_LEFT,  KC_DOWN,      KC_UP,    KC_RGHT),

	[_FN] = LAYOUT_ortho_5x14(
KC_TRNS,  KC_F1,        KC_F2,    KC_F3,    KC_F4,     KC_F5,     KC_F6,        KC_F7,    KC_F8,     KC_F9,        KC_F10,   KC_F11,       KC_F12,   KC_TRNS,
KC_TRNS,  M_VWQ,        M_VW,     X(EURO),  KC_TRNS,   KC_TRNS,   KC_TRNS,      KC_TRNS,  KC_TRNS,   XP(UE,UE_U),  KC_TRNS,  XP(OE,OE_U),  KC_PSCR,  KC_TRNS,
KC_TRNS,  XP(AE,AE_U),  X(SZ),    KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,      KC_TRNS,  KC_LEFT,   KC_DOWN,      KC_UP,    KC_RGHT,      KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,      KC_TRNS,  KC_TRNS,   KC_TRNS,      KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  TO(2),     KC_TRNS,   KC_TRNS,      KC_TRNS,  KC_TRNS,   TO(0),        KC_TRNS,  KC_PGDN,      KC_PGUP,  KC_TRNS),

    [_MEDIA] = LAYOUT_ortho_5x14(
KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,      KC_TRNS,  KC_TRNS,   KC_LBRC,      KC_RBRC,  KC_VOLD,      KC_VOLU,  KC_MUTE,
KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,      KC_TRNS,  KC_TRNS,   KC_TRNS,      KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,      KC_TRNS,  KC_MS_L,   KC_MS_D,      KC_MS_U,  KC_MS_R,      KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,      KC_TRNS,  KC_TRNS,   KC_TRNS,      KC_BTN1,  KC_BTN2,      KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  TO(3),     KC_TRNS,   KC_TRNS,      KC_MPLY,  KC_TRNS,   TO(1),        KC_TRNS,  KC_MRWD,      KC_MFFD,  KC_TRNS),

	[_SYS] = LAYOUT_ortho_5x14(
KC_TRNS,  RGB_M_P,      RGB_M_B,  RGB_M_R,  RGB_M_SW,  RGB_M_SN,  RGB_M_K,      RGB_M_X,  RGB_M_G,   KC_TRNS,      BL_TOGG,  BL_DEC,       BL_INC,   BL_BRTG,
KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  RESET,     KC_TRNS,   KC_TRNS,      KC_TRNS,  KC_TRNS,   KC_TRNS,      KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,      KC_TRNS,  DEBUG,    KC_TRNS,   KC_TRNS,   KC_TRNS,      RGB_TOG,  RGB_HUD,   RGB_SAD,      RGB_SAI,  RGB_HUI,      KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,      KC_TRNS,  RGB_RMOD,  RGB_MOD,      RGB_SPD,  RGB_SPI,      KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  TO(0),     KC_TRNS,   KC_TRNS,      KC_TRNS,  KC_TRNS,   TO(2),        KC_TRNS,  KC_TRNS,      RGB_VAI,  RGB_VAD)
};

// RGB
// RGB Modes
// 1 = Static
// 2-5 = Breathing
// 6-8 = Rainbow
// 9-14 = Swirl
// 15-20 = Snake
// 21-24 = Nightrider
// 25 = Christmas
// 26-30 = Static Gradient
const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {60, 255, 255, 20};

uint8_t preview = 0;
uint32_t desiredEffect = 1;


void matrix_init_user() {
	set_unicode_input_mode(UC_LNX);
};

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_BLUE);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(record->event.pressed) {
        switch(keycode) {
            case M_VWQ:
                SEND_STRING(SS_TAP(X_ESCAPE) ":wq" SS_TAP(X_ENTER));
                return false; break;
            case M_VW:
                SEND_STRING(SS_TAP(X_ESCAPE) ":w" SS_TAP(X_ENTER));
                return false; break;
        }
    }
    return true;
}

layer_state_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);

    switch (layer) {
      case _QWERTY:
        if(preview != 1) {
            rgblight_mode_noeeprom(desiredEffect);
        }
        rgblight_sethsv_noeeprom(HSV_BLUE);
        preview = 0;
        break;
      case _FN:
        desiredEffect = rgblight_config.mode;
        rgblight_sethsv_noeeprom(HSV_GREEN);
        rgblight_mode_noeeprom(1);
        break;
      case _MEDIA:
        desiredEffect = rgblight_config.mode;
        rgblight_sethsv_noeeprom(HSV_ORANGE);
        rgblight_mode_noeeprom(1);
        break;
      case _SYS:
        rgblight_sethsv_noeeprom(HSV_RED);
        rgblight_mode_noeeprom(1);
        preview = 1;
        break;
    }
    return state;
}


