/*
 * Copyright (c) 2011 Bharath Ramesh <bramesh.dev@gmail.com>
 *
 * Distributed under the terms of GNU LGPL, version 2.1
 */

#include "chrono.h"
#include "spinlock.h"

int
spinlock_init (spinlock_t *lock)
{
	lock->l = 0;
	lock->t = 0;

	return 0;
}

int
spinlock_lock (spinlock_t *lock)
{
	do {
		while (lock->l);
	} while (!__sync_lock_test_and_set (&lock->l, 1));

	return 0;
}

int
spinlock_timedlock (spinlock_t *lock, uint64_t timeout)
{
	uint64_t te;

	te = get_time (&lock->t) + timeout;
	while (1) {
		if (get_time (&lock->t) > te)
			return -1;

		if (lock->l)
			continue;

		if (!__sync_lock_test_and_set (&lock->l, 1))
			return 0;
	}

	return -1;
}

int
spinlock_trylock (spinlock_t *lock)
{
	if (!__sync_lock_test_and_set (&lock->l, 1))
		return 0;

	return -1;
}

int
spinlock_unlock (spinlock_t *lock)
{
	__sync_lock_release (&lock->l);

	return 0;
}
