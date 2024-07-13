#if defined(VIALRGB_ENABLE) && !defined(VIALRGB_NO_DIRECT)
#define RGB_MATRIX_EFFECT_VIALRGB_DIRECT
RGB_MATRIX_EFFECT(VIALRGB_DIRECT)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

extern HSV g_direct_mode_colors[RGB_MATRIX_LED_COUNT];

bool VIALRGB_DIRECT(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    /*
    * HSV Colors
    *
    * All values (including hue) are scaled to 0-255
    */
    // #define HSV_AZURE       132, 102, 255
    // #define HSV_BLACK         0,   0,   0
    // #define HSV_BLUE        170, 255, 255
    // #define HSV_CHARTREUSE   64, 255, 255
    // #define HSV_CORAL        11, 176, 255
    // #define HSV_CYAN        128, 255, 255
    // #define HSV_GOLD         36, 255, 255
    // #define HSV_GOLDENROD    30, 218, 218
    // #define HSV_GREEN        85, 255, 255
    // #define HSV_MAGENTA     213, 255, 255
    // #define HSV_ORANGE       21, 255, 255
    // #define HSV_PINK        234, 128, 255
    // #define HSV_PURPLE      191, 255, 255
    // #define HSV_RED           0, 255, 255
    // #define HSV_SPRINGGREEN 106, 255, 255
    // #define HSV_TEAL        128, 255, 128
    // #define HSV_TURQUOISE   123,  90, 112
    // #define HSV_WHITE         0,   0, 255
    // #define HSV_YELLOW       43, 255, 255

    HSV hsv_colors[5] = {
        {0, 255, rgb_matrix_config.hsv.v},   // Red
        {191, 255, rgb_matrix_config.hsv.v}, // Purple
        {43, 255, rgb_matrix_config.hsv.v},  // Yellow
        {175, 255, rgb_matrix_config.hsv.v}, // Blue
        {128, 255, rgb_matrix_config.hsv.v}  // Cyan
    };

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv_colors[i]);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    return rgb_matrix_check_finished_leds(led_max);
}
#    endif
#endif
