#include "secrets.h"
#include "definitions/keycodes.h"

// Replace these example values with your actual secrets
const char secret_1[] PROGMEM = "secret_1";

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
