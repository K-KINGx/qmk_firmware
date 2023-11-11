// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include <stdbool.h>
#include <stdint.h>

bool potentiometer_update_kb(uint8_t index, uint16_t value);
bool potentiometer_update_user(uint8_t index, uint16_t value);

bool potentiometer_task(void);
