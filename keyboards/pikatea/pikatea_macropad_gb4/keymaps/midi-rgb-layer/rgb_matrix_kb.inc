RGB_MATRIX_EFFECT(LAYER_INDICATOR)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool LAYER_INDICATOR(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB rgb = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);
    int currentLayer = get_highest_layer(layer_state);

    rgb_matrix_set_color_all(RGB_OFF);
    rgb_matrix_set_color(currentLayer, rgb.r, rgb.g, rgb.b);

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
