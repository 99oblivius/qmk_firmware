#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  BASE = SAFE_RANGE,
  BACKLIT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_4x12(
    LALT(LCTL(LSFT(KC_F1))),LALT(LCTL(LSFT( KC_F2))),LALT(LCTL(LSFT( KC_F3))),LALT(LCTL(LSFT( KC_F4))), LALT(LCTL(KC_F1)),LALT(LCTL( KC_F2)),LALT(LCTL( KC_F3)),LALT(LCTL( KC_F4)),    KC_KP_PLUS,KC_KP_7,KC_KP_8,KC_KP_9,    
    LALT(LCTL(LSFT(KC_F5))),LALT(LCTL(LSFT( KC_F6))),LALT(LCTL(LSFT( KC_F7))),LALT(LCTL(LSFT( KC_F8))), LALT(LCTL(KC_F5)),LALT(LCTL( KC_F6)),LALT(LCTL( KC_F7)),LALT(LCTL( KC_F8)),    KC_KP_MINUS,KC_KP_4,KC_KP_5,KC_KP_6,    
    LALT(LCTL(LSFT(KC_F9))),LALT(LCTL(LSFT(KC_F10))),LALT(LCTL(LSFT(KC_F11))),LALT(LCTL(LSFT(KC_F12))), LALT(LCTL(KC_F9)),LALT(LCTL(KC_F10)),LALT(LCTL(KC_F11)),LALT(LCTL(KC_F12)),    KC_KP_ASTERISK,KC_KP_1,KC_KP_2,KC_KP_3,
    LCTL(LSFT(KC_F13)),     LCTL(LSFT(KC_F14)),      LCTL(LSFT(KC_F15)),      LCTL(LSFT(KC_F16)),       RAISE,         KC_SPACE,          KC_NO,             KC_NUM,               KC_KP_SLASH,KC_KP_0,KC_KP_DOT,KC_KP_ENTER),

  [_LOWER] = LAYOUT_ortho_4x12(KC_TILD,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_MINUS,KC_PLUS,KC_TRNS,KC_GRV,KC_PIPE,KC_TILD,KC_LPRN,KC_RPRN,KC_LEFT_ANGLE_BRACKET,KC_RIGHT_ANGLE_BRACKET,KC_LCBR,KC_RCBR,KC_COLN,KC_EQUAL,KC_TRNS,KC_CAPS,KC_TRNS,KC_TRNS,KC_LCBR,KC_RCBR,KC_SLSH,KC_BSLS,KC_LBRC,KC_RBRC,KC_UNDS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_NO,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),
  
  [_RAISE] = LAYOUT_ortho_4x12(
    LCTL(LSFT(KC_F1)),LCTL(LSFT( KC_F2)),LCTL(LSFT( KC_F3)),LCTL(LSFT( KC_F4)),                         LALT(LSFT(KC_F1)),LALT(LSFT( KC_F2)),LALT(LSFT( KC_F3)),LALT(LSFT( KC_F4)),    KC_KP_PLUS,KC_KP_7,KC_KP_8,KC_KP_9,    
    LCTL(LSFT(KC_F5)),LCTL(LSFT( KC_F6)),LCTL(LSFT( KC_F7)),LCTL(LSFT( KC_F8)),                         LALT(LSFT(KC_F5)),LALT(LSFT( KC_F6)),LALT(LSFT( KC_F7)),LALT(LSFT( KC_F8)),    KC_KP_MINUS,KC_KP_4,KC_KP_5,KC_KP_6,    
    LCTL(LSFT(KC_F9)),LCTL(LSFT(KC_F10)),LCTL(LSFT(KC_F11)),LCTL(LSFT(KC_F12)),                         LALT(LSFT(KC_F9)),LALT(LSFT(KC_F10)),LALT(LSFT(KC_F11)),LALT(LSFT(KC_F12)),    KC_KP_ASTERISK,KC_KP_1,KC_KP_2,KC_KP_3,
    LCTL(LSFT(KC_F13)),     LCTL(LSFT(KC_F14)),      LCTL(LSFT(KC_F15)),      LCTL(LSFT(KC_F16)),       RAISE,         KC_SPACE,          KC_NO,             KC_NUM,               KC_KP_SLASH,KC_KP_0,KC_KP_DOT,KC_KP_ENTER),
  
  [_ADJUST] = LAYOUT_ortho_4x12(KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,KC_DEL,KC_TRNS,AU_ON,AU_OFF,AU_TOGG,KC_TRNS,KC_END,KC_PGUP,RM_VALU,RM_VALD,KC_TRNS,QK_BOOT,KC_TRNS,KC_TRNS,MU_ON,MU_OFF,MU_TOGG,KC_TRNS,KC_HOME,KC_PGDN,RM_HUEU,RM_HUED,KC_TRNS,KC_TRNS,KC_MPLY,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_NO,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_BASE);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(MS_WHLD);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(MS_WHLU);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
