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

void process_secrets(void) {
    if (leader_sequence_two_keys(KC_S, KC_S)) {
        send_string_with_delay(SECRET_SS_VALUE, TAP_CODE_DELAY);
    }
    if (leader_sequence_two_keys(KC_S, KC_A)) {
        send_string_with_delay(SECRET_SA_VALUE, TAP_CODE_DELAY);
    }
    if (leader_sequence_two_keys(KC_S, KC_D)) {
        send_string_with_delay(SECRET_SD_VALUE, TAP_CODE_DELAY);
    }
    if (leader_sequence_two_keys(KC_S, KC_P)) {
        send_string_with_delay(SECRET_SP_VALUE, TAP_CODE_DELAY);
    }
    if (leader_sequence_two_keys(KC_S, KC_G)) {
        send_string_with_delay(SECRET_SG_VALUE, TAP_CODE_DELAY);
    }
    if (leader_sequence_two_keys(KC_S, KC_M)) {
        send_string_with_delay(SECRET_SM_VALUE, TAP_CODE_DELAY);
    }
}
