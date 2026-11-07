//
// Copyright (c) 2026 robotcopper
//
// This program and the accompanying materials are made available under the
// terms of the Eclipse Public License 2.0 which is available at
// http://www.eclipse.org/legal/epl-2.0, or the Apache License, Version 2.0
// which is available at https://www.apache.org/licenses/LICENSE-2.0.
//
// SPDX-License-Identifier: EPL-2.0 OR Apache-2.0
//

#ifndef INCLUDE_ZENOH_PICO_SESSION_SUBSCRIPTION_TIMING_H
#define INCLUDE_ZENOH_PICO_SESSION_SUBSCRIPTION_TIMING_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Time that _z_trigger_subscriptions_impl spends finding the subscriptions of a
// sample and releasing them afterwards, the part that Z_FEATURE_RX_CACHE
// replaces, for samples of ordinary subscribers. The read task writes it
// without a lock; a reader resets max_us itself.
typedef struct {
    uint32_t count;
    uint32_t sum_us;
    uint32_t max_us;
} _z_subscription_timing_t;

extern volatile _z_subscription_timing_t _z_subscription_timing;

// Microseconds, defined by the application; the default returns 0.
uint32_t _z_subscription_clock_us(void);

#ifdef __cplusplus
}
#endif

#endif  // INCLUDE_ZENOH_PICO_SESSION_SUBSCRIPTION_TIMING_H
