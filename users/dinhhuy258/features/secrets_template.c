// Template for secrets.c
// Copy this file to secrets.c and modify with your actual secrets
// DO NOT commit secrets.c to version control!

#include "secrets.h"
#include "definitions/keycodes.h"

// Define your secret strings here
// These are stored in program memory for better security
// Replace these example values with your actual secrets
const char secret_1[] PROGMEM = "your_password_here";
const char secret_2[] PROGMEM = "your_second_password_here";
const char secret_3[] PROGMEM = "your_username_here";

bool process_secret_macro(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    // Clear any held modifiers before sending secrets
    uint8_t saved_mods = get_mods();
    clear_mods();
    clear_weak_mods();

    const char *secret_string = NULL;

    switch (keycode) {
        case SECRET_1:
            secret_string = secret_1;
            break;
        case SECRET_2:
            secret_string = secret_2;
            break;
        case SECRET_3:
            secret_string = secret_3;
            break;
        default:
            set_mods(saved_mods); // Restore modifiers
            return false;
    }

    if (secret_string != NULL) {
        // Send the secret string with a small delay between characters
        // This helps prevent detection and ensures reliable transmission
        send_string_with_delay_P(secret_string, 10);
    }

    // Restore previous modifier state
    set_mods(saved_mods);

    return false; // Consume the keycode
}
