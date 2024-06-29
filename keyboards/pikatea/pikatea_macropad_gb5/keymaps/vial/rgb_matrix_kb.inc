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

    // Define the brightness level (0 to 255)
    uint8_t brightness = 128;

    uint8_t scale_color(uint8_t color, uint8_t brightness) {
        return (color * brightness) / 255;
    }

    uint8_t cyan_r = 0, cyan_g = 255, cyan_b = 255;
    uint8_t blue_r = 0, blue_g = 0, blue_b = 255;
    uint8_t yellow_r = 255, yellow_g = 255, yellow_b = 0;
    uint8_t purple_r = 128, purple_g = 0, purple_b = 128;
    uint8_t red_r = 255, red_g = 0, red_b = 0;

    // Set the colors with the desired brightness
    rgb_matrix_set_color(4, scale_color(cyan_r, brightness), scale_color(cyan_g, brightness), scale_color(cyan_b, brightness));
    rgb_matrix_set_color(3, scale_color(blue_r, brightness), scale_color(blue_g, brightness), scale_color(blue_b, brightness));
    rgb_matrix_set_color(2, scale_color(yellow_r, brightness), scale_color(yellow_g, brightness), scale_color(yellow_b, brightness));
    rgb_matrix_set_color(1, scale_color(purple_r, brightness), scale_color(purple_g, brightness), scale_color(purple_b, brightness));
    rgb_matrix_set_color(0, scale_color(red_r, brightness), scale_color(red_g, brightness), scale_color(red_b, brightness));

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
