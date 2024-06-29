// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(my_green_effect)
RGB_MATRIX_EFFECT(my_red_effect)
RGB_MATRIX_EFFECT(my_blue_effect)
RGB_MATRIX_EFFECT(my_white_effect)
RGB_MATRIX_EFFECT(my_yellow_effect)
RGB_MATRIX_EFFECT(my_orange_effect)
RGB_MATRIX_EFFECT(my_cyan_effect)
RGB_MATRIX_EFFECT(my_purple_effect)
RGB_MATRIX_EFFECT(my_effect)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// e.g: A simple effect, self-contained within a single method
static bool my_green_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    rgb_matrix_set_color_all(RGB_GREEN);
    return rgb_matrix_check_finished_leds(led_max);
}

static bool my_red_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    rgb_matrix_set_color_all(RGB_RED);
    return rgb_matrix_check_finished_leds(led_max);
}

static bool my_blue_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    rgb_matrix_set_color_all(RGB_BLUE);
    return rgb_matrix_check_finished_leds(led_max);
}

static bool my_white_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    rgb_matrix_set_color_all(RGB_WHITE);
    return rgb_matrix_check_finished_leds(led_max);
}

static bool my_yellow_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    rgb_matrix_set_color_all(RGB_YELLOW);
    return rgb_matrix_check_finished_leds(led_max);
}

static bool my_orange_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    rgb_matrix_set_color_all(RGB_ORANGE);
    return rgb_matrix_check_finished_leds(led_max);
}

static bool my_cyan_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    rgb_matrix_set_color_all(RGB_CYAN);
    return rgb_matrix_check_finished_leds(led_max);
}

static bool my_purple_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    rgb_matrix_set_color_all(RGB_PURPLE);
    return rgb_matrix_check_finished_leds(led_max);
}

static bool my_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    rgb_matrix_set_color(4, RGB_CYAN);
    rgb_matrix_set_color(3, RGB_BLUE);
    rgb_matrix_set_color(2, RGB_YELLOW);
    rgb_matrix_set_color(1, RGB_PURPLE);
    rgb_matrix_set_color(0, RGB_RED);
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
