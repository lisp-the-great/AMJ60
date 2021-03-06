#include "keymap_common.h"

// Default
#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[KEYMAPS_COUNT][MATRIX_ROWS][MATRIX_COLS] __attribute__((section(".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
    /* Keymap 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| Bksp|
     * |-----------------------------------------------------------|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|     Shift|
     * |-----------------------------------------------------------|
     * |Fn0 |Gui |Alt |      Space             |Fn0 |Alt |Gui |Ctrl|
     * `-----------------------------------------------------------'
     */
    KEYMAP(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,  GRV,\
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,\
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  ENT, \
        LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,NO,  RSFT,\
        FN0, LGUI,LALT,          SPC,                     FN0, RALT,RGUI,RCTL),
    /* Keymap 1: Fn0 Layer
     * ,-----------------------------------------------------------.
     * |  `| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   |   |
     * |-----------------------------------------------------------|
     * |     |   | Up|   |   |   |Cal|   |Ins|   |Psc|Slk|   |  Del|
     * |-----------------------------------------------------------|
     * |Caps  |Lef|Dow|Rig|   |   |Hom|PgD|PgU|End|   |Pau|        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |VoD|VoU|Mut|          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     */
    KEYMAP(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,TRNS, \
        TRNS,TRNS,UP  ,TRNS,TRNS,TRNS,CALC,TRNS,INS, TRNS,PSCR,SLCK,TRNS,DEL, \
        CAPS,LEFT,DOWN,RGHT,TRNS,TRNS,HOME,PGDN,PGUP,END, TRNS,PAUS,NO,  TRNS,\
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,VOLD,VOLU,MUTE,NO,  TRNS,\
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
};

/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const uint16_t fn_actions[FN_ACTIONS_COUNT] __attribute__((section(".keymap.fn_actions"))) = {
#else
const uint16_t fn_actions[] PROGMEM = {
#endif
    [0] = ACTION_LAYER_MOMENTARY(1),
    // [1] = ACTION_BACKLIGHT_DECREASE(),
    // [2] = ACTION_BACKLIGHT_TOGGLE(),
    // [3] = ACTION_BACKLIGHT_INCREASE()
};

#ifdef KEYMAP_IN_EEPROM_ENABLE
uint16_t keys_count(void)
{
    return sizeof(keymaps) / sizeof(keymaps[0]) * MATRIX_ROWS * MATRIX_COLS;
}

uint16_t fn_actions_count(void)
{
    return sizeof(fn_actions) / sizeof(fn_actions[0]);
}
#endif

/*
 * Action macro definition
 */
enum macro_id
{
    KEYPAD_00 = 0,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id)
    {
    case KEYPAD_00:
        return (record->event.pressed ? MACRO(T(P0), T(P0), END) : MACRO_NONE);
    }
    return MACRO_NONE;
}
