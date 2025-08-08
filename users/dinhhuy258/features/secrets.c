#include "secrets.h"
#include "definitions/constants.h"
#include "definitions/keycodes.h"
#include "definitions/layers.h"

#if __has_include("secrets_config.h")
#    include "secrets_config.h"
#endif

#ifndef SECRET_SS_VALUE
#    define SECRET_SS_VALUE ""
#endif
#ifndef SECRET_SA_VALUE
#    define SECRET_SA_VALUE ""
#endif
#ifndef SECRET_SD_VALUE
#    define SECRET_SD_VALUE ""
#endif
#ifndef SECRET_SP_VALUE
#    define SECRET_SP_VALUE ""
#endif
#ifndef SECRET_SG_VALUE
#    define SECRET_SG_VALUE ""
#endif
#ifndef SECRET_SM_VALUE
#    define SECRET_SM_VALUE ""
#endif

bool process_secrets(void) {
    static const struct {
        uint16_t    key;
        const char* value;
    } secret_mappings[] = {{KC_S, SECRET_SS_VALUE}, {KC_A, SECRET_SA_VALUE}, {KC_D, SECRET_SD_VALUE}, {KC_P, SECRET_SP_VALUE}, {KC_G, SECRET_SG_VALUE}, {KC_M, SECRET_SM_VALUE}};

    for (int i = 0; i < sizeof(secret_mappings) / sizeof(secret_mappings[0]); i++) {
        if (leader_sequence_two_keys(KC_S, secret_mappings[i].key)) {
            send_string_with_delay(secret_mappings[i].value, TAP_CODE_DELAY);

            return true;
        }
    }

    return false;
}
