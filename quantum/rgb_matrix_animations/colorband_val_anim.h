#ifndef DISABLE_RGB_MATRIX_BAND_VAL
RGB_MATRIX_EFFECT(BAND_VAL)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static void BAND_VAL_math(HSV* hsv, uint8_t i, uint8_t time) {
    int16_t v = rgb_matrix_config.val - abs(scale8(g_led_config.point[i].x, 228) + 28 - time) * 8;
    hsv->v = v < 0 ? 0 : v;
}

bool BAND_VAL(effect_params_t* params) {
    return effect_runner_i(params, &BAND_VAL_math);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif // DISABLE_RGB_MATRIX_BAND_VAL
