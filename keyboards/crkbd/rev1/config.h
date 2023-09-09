#pragma once

// home-row mod trigger threshold
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200

// need it for LGUI(Backspace)
#define TAPPING_TERM_PER_KEY

// prevent roll-over
#define BILATERAL_COMBINATIONS

// higher if `jk` doesn't get triggered
#define COMBO_TERM 150
#define COMBO_MUST_PRESS_IN_ORDER
