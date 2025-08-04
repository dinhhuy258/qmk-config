#include "secrets.h"
#include "definitions/keycodes.h"

// Replace these example values with your actual secrets
const char secret_1[] PROGMEM = "secret_1";

bool process_secret_macro(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    const char *secret_string = NULL;

    switch (keycode) {
        case SECRET_1:
            secret_string = secret_1;
            break;
    }

    // Send the secret string with a small delay between characters
    // This helps prevent detection and ensures reliable transmission
    send_string_with_delay_P(secret_string, 10);

    return false; // Consume the keycode
}
