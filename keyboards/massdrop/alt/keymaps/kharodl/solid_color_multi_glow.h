RGB_MATRIX_EFFECT(SOLID_COLOR_MULTI_GLOW)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// alphas = color1, mods = color2
bool SOLID_COLOR_MULTI_GLOW(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv  = rgb_matrix_config.hsv;
    RGB rgb1 = hsv_to_rgb(hsv);
    hsv.h += rgb_matrix_config.speed;
    hsv.s = 0;
    RGB rgb2 = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, rgb1.r, rgb1.g, rgb1.b);
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            rgb_matrix_set_color(i, rgb2.r, rgb2.g, rgb2.b);
        } else {
            rgb_matrix_set_color(i, rgb2.r, rgb2.g, rgb2.b);
        }
    }
    return led_max < DRIVER_LED_TOTAL;
}

#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
