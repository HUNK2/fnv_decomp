
// src/fallout_shared/bgsimpactdata_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsimpactdata.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "bgsimpactdata.h"
#include "string.h"
#include <malloc.h>
static const char s_textureSetWarning[] = "MASTERFILE: Unable to find texture set (%08X) on impact data %s (%08X).";
static const char s_soundWarning[] = "MASTERFILE: Unable to find sound (%08X) on impact data %s (%08X).";
