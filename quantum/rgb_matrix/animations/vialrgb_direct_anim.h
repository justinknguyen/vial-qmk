#if defined(VIALRGB_ENABLE) && !defined(VIALRGB_NO_DIRECT)
#define RGB_MATRIX_EFFECT_VIALRGB_DIRECT
RGB_MATRIX_EFFECT(VIALRGB_DIRECT)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

extern HSV g_direct_mode_colors[RGB_MATRIX_LED_COUNT];

bool VIALRGB_DIRECT(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv_colors[5] = {
        {0, 255, rgb_matrix_config.hsv.v},   // Red
        {191, 255, rgb_matrix_config.hsv.v}, // Purple
        {43, 255, rgb_matrix_config.hsv.v},  // Yellow
        {180, 255, rgb_matrix_config.hsv.v}, // Blue
        {150, 255, rgb_matrix_config.hsv.v}  // Cyan
    };

    for (uint8_t i = 0; i < 5; i++) {
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv_colors[i]);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    return rgb_matrix_check_finished_leds(led_max);
}
#    endif
#endif
