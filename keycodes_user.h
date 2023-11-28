// user defined keycodes
#define CMD_SPC LGUI_T(KC_SPC)
#define ALT_SPC RALT_T(KC_SPC)

#define LOWER MO(_LOWER)
#define LWRFNC LT(_LOWER, KC_F18)
#define RAISE MO(_RAISE)
#define RISFNC LT(_RAISE, KC_F19)
//#define RAISE LM(_RAISE, MOD_MASK_SHIFT)
#define FNCTN OSL(_FNCTN)
#define MODS  OSL(_MODS)
#define ORS   OSL(_ORS)
#define MOUSE MO(_MOUSE)

#define MOD_CAG LM(0, MOD_MASK_CAG)

#define SC_TAB (QK_LCTL | QK_RSFT | KC_TAB)
#define SA_TAB (QK_RALT | QK_RSFT | KC_TAB)
#define EISU KC_LNG2
#define KANA KC_LNG1

#define HSV_ADJUST  HSV_PURPLE
#define HSV_BACKLIT HSV_BLUE
