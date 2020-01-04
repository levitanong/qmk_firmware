#include QMK_KEYBOARD_H
#define _LAYER0 0
#define _LAYER1 1
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[_LAYER0] = LAYOUT_65_ansi( /* Base */
			KC_GESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_GRAVE,\
		    KC_TAB,        KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLASH, KC_HOME,\
			KC_LCTL,       KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_AUDIO_VOL_UP,\
		    KC_LSFT,       KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     KC_AUDIO_VOL_DOWN,\
		    MO(1),         KC_LALT,  KC_LGUI,                KC_SPC,                KC_RGUI, MO(1),    MO(2),    KC_LEFT,           KC_DOWN,   KC_RIGHT),
		[_LAYER1] = LAYOUT_65_ansi( /* FN */
			KC_GESC,       KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,   KC_HOME,\
		    KC_TRNS,       RGB_TOG,  RGB_MOD, RGB_HUI,RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_PSCR, KC_SLCK,  KC_PAUS, RESET,    KC_PGUP,\
			KC_CAPS,       RGB_SPI,  RGB_SPD, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          EEP_RST,  KC_PGDN,\
		    KC_LSFT,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_VOLU,  KC_MUTE,\
		    KC_TRNS,       KC_TRNS,  KC_TRNS,                  KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS,  KC_MPRV,          KC_VOLD,  KC_MNXT),
};

void rgb_matrix_indicators_user(void) {
    if (IS_LED_ON(host_keyboard_leds(), USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(8, 0xFF, 0xFF, 0xFF);
    }
}

void matrix_init_user(void) {
  //user initialization
}

LEADER_EXTERNS();

// Declare a boolean variable to keep track of whether any sequence
// will have been matched.
bool did_leader_succeed;

void matrix_scan_user(void) {
  //user matrix
    LEADER_DICTIONARY() {
        did_leader_succeed = leading = false;

        SEQ_ONE_KEY(KC_F) {
            // Anything you can do in a macro.
            SEND_STRING("QMK is awesome.");
            did_leader_succeed = true;
        }
        SEQ_TWO_KEYS(KC_G, KC_G) {
            SEND_STRING("ggwp");
            did_leader_succeed = true;
        }
        SEQ_TWO_KEYS(KC_D, KC_D) {
            SEND_STRING(SS_LCTRL("a")SS_LCTRL("c"));
            did_leader_succeed = true;
        }
        SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
            SEND_STRING("https://start.duckduckgo.com"SS_TAP(X_ENTER));
            did_leader_succeed = true;
        }
        SEQ_TWO_KEYS(KC_A, KC_S) {
            register_code(KC_LGUI);
            register_code(KC_S);
            unregister_code(KC_S);
            unregister_code(KC_LGUI);
            did_leader_succeed = true;
        }
        leader_end();
    }
}

void leader_start(void) {

}

void leader_end(void) {
  if (did_leader_succeed) {
    // If any sequence was matched, did_leader_succeed will have
    // been set to true up in the matrix_scan_user function.
    // Put your code for a matched leader key sequence here.
  } else {
    // If no sequence was matched, did_leader_succeed will not
    // have been set to true anywhere, so we'll end up here.
    // Put your code for an unmatched leader key sequence here.

  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	  return true;
}
