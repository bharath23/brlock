/*
 * Copyright (c) 2011 Bharath Ramesh <bramesh.dev@gmail.com>
 *
 * Distributed under the terms of GNU LGPL, version 2.1
 */

#ifndef __CHRONO_H__
#define __CHRONO_H__

#include <stdint.h>
#include <stdlib.h>
#include <sys/time.h>

#define CHRONO_INF UINT64_MAX
#define CHRONO_MSEC 1000
#define CHRONO_SEC 1000000

/*
 * Returns the current time in microseconds.
 * This function ensures that time progresses forward.
 * The user should initialize old_t to 0 before the first call to get_time.
 *
 * Returns	current time on success.
 * 		0 on failure.
 */

static inline uint64_t
get_time (uint64_t *old_t)
{
	uint64_t t;
	struct timeval tv;

	if (gettimeofday (&tv, NULL) != 0)
		return 0;

	t = tv.tv_sec * CHRONO_SEC + tv.tv_usec;
	if (t < *old_t)
		return *old_t;

	*old_t = t;
	return t;
}

#endif /* __CHRONO_H__ */
