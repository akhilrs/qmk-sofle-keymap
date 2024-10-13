// OLED
// #define OLED_ENABLE
#ifdef OLED_ENABLE
#include "quantum.h"
#include "oled_driver.h"
// #include "ocean_dream.c"
static const char PROGMEM font_logo[16] = {
    0x80, 0x81, 0x82, 0x83,
    0x84, 0xa0, 0xa1, 0xa2,
    0xa3, 0xa4, 0xc0, 0xc1,
    0xc2, 0xc3, 0xc4, 0
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }    // return OLED_ROTATION_270;
    return OLED_ROTATION_0;
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR("Shift\n") : PSTR("     \n"), false);
    oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR("Ctrl\n") : PSTR("    \n"), false);
    oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR("Alt \n") : PSTR("    \n"), false);
    oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR("Super\n") : PSTR("     \n"), false);
}

void render_lock_status(led_t led_state) {
    oled_write_P(led_state.caps_lock ? PSTR("CAPS\n") : PSTR("    \n"), false);
}

void render_layer_status(void) {
    switch (get_highest_layer(layer_state)) {
        case _NUM:
            oled_write("NUM", false);
            break;
        case _SYM:
            oled_write("SYM", false);
            break;
        case _NAV:
            oled_write("NAV", false);
            break;
        case _FUNC:
            oled_write("FUNC", false);
            break;
        case _MOUSE:
            oled_write("MOUSE", false);
            break;
        case _SYS:
            oled_write("SYS", false);
            break;
        default:
            oled_write("COLE", false);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_lock_status(host_keyboard_led_state());
        render_mod_status(get_mods() | get_oneshot_mods());
        oled_set_cursor(0, 14);
        render_layer_status();
    } else {
        // render_stars();
        oled_set_cursor(8, 2);
        oled_write_P(PSTR("0"), false);
        oled_set_cursor(9, 2);
        oled_write_P(PSTR("x"), false);
        oled_set_cursor(10, 2);
        oled_write_P(PSTR("1"), false);
        oled_set_cursor(11, 2);
        oled_write_P(PSTR("2"), false);
        oled_set_cursor(12, 2);
        oled_write_P(PSTR("3"), false);
        oled_set_cursor(13, 2);
        oled_write_P(PSTR("5"), false);
}
    return false;
}

#endif
