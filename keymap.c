#include QMK_KEYBOARD_H
#include "quantum.h"
#include "layers.h"
#include "oled.c"

// Define Layer Names
// enum sofle_layers {
//     _COLEMAK,
//     _NAV,
//     _FUNC,
//     _SYM,
//     _NUM,
//     _MOUSE,
//     _SYS
// };

// Define custom keycodes for switching layouts
enum custom_keycodes {
    COMMA_MORPH = SAFE_RANGE,
    DOT_MORPH
};
// Tap Dance declarations
enum {
    TD_SHIFT_CAPS,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(OSM(MOD_LSFT), KC_CAPS),
};

// Left-hand home row mods
#define HOME_A MT(MOD_LGUI, KC_A)
#define HOME_R MT(MOD_LALT, KC_R)
#define HOME_S MT(MOD_LSFT, KC_S)
#define HOME_T MT(MOD_LCTL, KC_T)

// Right-hand home row mods
#define HOME_N MT(MOD_RCTL, KC_N)
#define HOME_E MT(MOD_RSFT, KC_E)
#define HOME_I MT(MOD_LALT, KC_I)
#define HOME_O MT(MOD_RGUI, KC_O)

// Layer-Tap definitions for thumb cluster
#define LT_NUM_SPC LT(_NUM, KC_SPC)     // Tap for Space, Hold for Num layer
#define LT_SYM_ENT LT(_SYM, KC_ENT)     // Tap for Enter, Hold for Sym layer
#define LT_TAB_NAV LT(_NAV, KC_TAB)     // Tap for Tab, Hold for Nav layer
#define LT_FUN_SYS LT(_FUNC, KC_LGUI)   // Tap for GUI, Hold for Func layer

#define DSK_PREV LGUI(KC_LBRC)  // LGUI + [
#define DSK_NEXT LGUI(KC_RBRC)  // LGUI + ]

#define SMART_CAPS TD(TD_SHIFT_CAPS)

// Define Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* COLEMAK Layer */
    [_COLEMAK] = LAYOUT(
    // ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,                          KC_J,     KC_L,     KC_U,     KC_Y,     KC_QUOT,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  HOME_A,   HOME_R,   HOME_S,   HOME_T,   KC_G,                          KC_M,     HOME_N,   HOME_E,   HOME_I,   HOME_O,   XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,     KC_MUTE,    XXXXXXX, KC_K,     KC_H,     COMMA_MORPH,DOT_MORPH,KC_SLSH,XXXXXXX,
    // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
                      XXXXXXX,  XXXXXXX,  LT_FUN_SYS, LT_TAB_NAV, LT_SYM_ENT,  LT_NUM_SPC, SMART_CAPS, MO(_MOUSE), XXXXXXX,  XXXXXXX
                                        // Left Thumb Cluster                                  // Right Thumb Cluster
    ),
    /* Navigation Layer */
    [_NAV] = LAYOUT(
    // ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  KC_ESC,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       KC_PGUP,  KC_BSPC,  KC_UP,    KC_DEL,   XXXXXXX,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL,  XXXXXXX,                       KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_ENT,   XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX, KC_INS,   KC_TAB,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
                              XXXXXXX,  XXXXXXX,  KC_LCTL, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    /* Function Layer */
    [_FUNC] = LAYOUT(
    // ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  KC_F12,   KC_F7,    KC_F8,    KC_F9,    XXXXXXX,                       XXXXXXX,  XXXXXXX,  KC_VOLU,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  KC_F11,   KC_F4,    KC_F5,    KC_F6,    XXXXXXX,                       XXXXXXX,  DSK_PREV, KC_VOLD,  DSK_NEXT, XXXXXXX,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  KC_F10,   KC_F1,    KC_F2,    KC_F3,    XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
                              XXXXXXX,  XXXXXXX,  XXXXXXX, KC_LCTL, XXXXXXX,     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    /* Symbol Layer */
    [_SYM] = LAYOUT(
    // ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  KC_DOT,   KC_LT,    KC_GT,    KC_DQUO,  KC_QUOT,                       KC_AMPR,  KC_DLR,   KC_LBRC,  KC_RBRC,  KC_PERC,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  KC_EXLM,  KC_MINS,  KC_PLUS,  KC_EQL,   KC_HASH,                       KC_PIPE,  KC_COLN,  KC_LPRN,  KC_RPRN,  KC_QUES,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  KC_GRV,   KC_SLSH,  KC_ASTR,  KC_BSLS,  KC_UNDS,  XXXXXXX,    XXXXXXX, KC_TILD,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_AT,  XXXXXXX,
    // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
                              XXXXXXX,  XXXXXXX, XXXXXXX,  KC_LCTL, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* Numeric Layer */
    [_NUM] = LAYOUT(
    // ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  XXXXXXX,  KC_7,     KC_8,     KC_9,     XXXXXXX,                       XXXXXXX,  KC_7,     KC_8,     KC_9,     XXXXXXX,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  KC_0,     KC_4,     KC_5,     KC_6,     XXXXXXX,                       XXXXXXX,  KC_4,     KC_5,     KC_6,     XXXXXXX,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  XXXXXXX,  KC_1,     KC_2,     KC_3,     XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX,  KC_1,     KC_2,     KC_3,     XXXXXXX,  XXXXXXX,
    // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
                              XXXXXXX,  XXXXXXX, XXXXXXX,  KC_LCTL, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    /* Mouse Layer */
    [_MOUSE] = LAYOUT(
    // ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       KC_WH_L,  KC_WH_D,  KC_MS_U,  KC_WH_U,  KC_WH_R,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_R,  XXXXXXX,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
                              XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,    KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    /* System Layer */
    [_SYS] = LAYOUT(
    // ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
                              XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool shift_held = false;

    switch (keycode) {
    case DOT_MORPH:
        if (record->event.pressed) {
            shift_held = get_mods() & MOD_MASK_SHIFT;
            if (shift_held) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code16(KC_COLON);  // This sends a colon
            } else {
                tap_code(KC_DOT);
            }
        }
        return false;
    case COMMA_MORPH:
        if (record->event.pressed) {
            shift_held = get_mods() & MOD_MASK_SHIFT;
            if (shift_held) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_SEMICOLON);  // This sends a semicolon
            } else {
                tap_code(KC_COMMA);
            }
        }
        return false;
    default:
        return true;
    }
}// #include "encoder.c"
