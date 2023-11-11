// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "potentiometer.h"
#include "gpio.h"
#include "util.h"
#include "timer.h"
#include "analog.h"

#ifndef POTENTIOMETER_THROTTLE_MS
#    define POTENTIOMETER_THROTTLE_MS 1
#endif

static pin_t potentiometer_pads[] = POTENTIOMETER_PINS;
#define NUM_POTENTIOMETERS (ARRAY_SIZE(potentiometer_pads))

static bool potentiometer_state[NUM_POTENTIOMETERS] = {0};

__attribute__((weak)) bool potentiometer_update_user(uint8_t index, uint16_t value) {
    return true;
}

__attribute__((weak)) bool potentiometer_update_kb(uint8_t index, uint16_t value) {
    return potentiometer_update_user(index, value);
}

__attribute__((weak)) bool potentiometer_throttle_task(void) {
#if (POTENTIOMETER_THROTTLE_MS > 0)
    static uint32_t last_exec = 0;
    if (timer_elapsed32(last_exec) < POTENTIOMETER_THROTTLE_MS) {
        return false;
    }
    last_exec = timer_read32();
#endif
    return true;
}

bool potentiometer_task(void) {
    if (!potentiometer_throttle_task()) {
        return false;
    }

    bool changed = false;
    for (uint8_t index = 0; index < NUM_POTENTIOMETERS; index++) {
        uint16_t value = analogReadPin(potentiometer_pads[index]);
        if (value != potentiometer_state[index]) {
            potentiometer_state[index] = value;
            changed |= true;

            potentiometer_update_kb(index, value);
        }
    }

    return changed;
}