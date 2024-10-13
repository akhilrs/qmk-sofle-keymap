
/* Encoder functionality */
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {  // Left encoder
        if (clockwise) {
            tap_code(KC_VOLU);  // Volume up
        } else {
            tap_code(KC_VOLD);  // Volume down
        }
    } else if (index == 1) {  // Right encoder
        if (clockwise) {
            tap_code(KC_RIGHT);  // Right arrow
        } else {
            tap_code(KC_LEFT);  // Left arrow
        }
    }
    return true;
}

void encoder_action_custom(uint8_t index, bool clockwise) {
    if (index == 0 && !clockwise) {
        tap_code(KC_MUTE);  // Mute audio on left encoder press
    } else if (index == 1 && !clockwise) {
        tap_code(KC_MUTE);
    }
}

#endif

