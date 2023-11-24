#include "mousekey.h"
#include "quantum_keycodes.h"
#include "song_list.h"

#ifdef AUDIO_ENABLE
#include "muse.h"
#include "song_vars.c"
#endif

#include "keycodes_user.h"
#include "layers_and_keycodes.c"
#include "eeprom.c"
#include "layouts.c"

#define OVERRIDE_MAX 100

static bool false_const = false;
