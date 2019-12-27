/*
 * Copyright © 2019 The Crust Firmware Authors.
 * SPDX-License-Identifier: BSD-3-Clause OR GPL-2.0-only
 */

#include <bitfield.h>
#include <stdint.h>
#include <util.h>

#include "ccu.h"

uint32_t
ccu_calc_rate_mp(uint32_t val, uint32_t rate,
                 uint32_t m_start, uint32_t m_width,
                 uint32_t p_start, uint32_t p_width)
{
	rate  /= bitfield_get(val, m_start, m_width) + 1;
	rate >>= bitfield_get(val, p_start, p_width);

	return rate;
}

uint32_t
ccu_calc_rate_p(uint32_t val, uint32_t rate,
                uint32_t p_start, uint32_t p_width)
{
	rate >>= bitfield_get(val, p_start, p_width);

	return rate;
}
