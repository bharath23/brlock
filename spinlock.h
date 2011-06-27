/*
 * Copyright (c) 2011 Bharath Ramesh <bramesh.dev@gmail.com>
 *
 * Distributed under the terms of GNU LGPL, version 2.1
 */

#ifndef __SPINLOCK_H__
#define __SPINLOCK_H__

#include <stdint.h>

struct __spinlock_type {
	int32_t l;
	uint64_t t;
};

typedef struct __spinlock_type spinlock_t;

/*
 * Initialize the referenced spinlock.
 *
 * @lock: spinlock to initialize.
 *
 * Returns:	0 on success.
 * 		-1 on failure.
 */

int spinlock_init (spinlock_t *lock);

/*
 * Acquire the referenced spinlock.
 * This function spins till the spinlock can be sucessfully acquired.
 *
 * @lock: spinlock to acquire.
 *
 * Returns: 	0 on success.
 * 		-1 on failure.
 */

int spinlock_lock (spinlock_t *lock);

/*
 * Acquire the referenced spinlock.
 * If the lock is alredy acquired, the calling thread spins until the lock is
 * available to be re-acquired. If the the lock cannot be acquired, the spining
 * will be terminated after timeout expires.
 *
 * @lock: spinlock to acquire.
 * @timeout: timeout in microseconds.
 *
 * Returns:	0 on success.
 * 		-1 on failure.
 */

int spinlock_timedlock (spinlock_t *lock, uint64_t timeout);

/*
 * Acquire the referenced spinlock.
 * If the lock is open, it is equivalent to spinlock_lock. If the lock cannot be
 * acquired the function shall return immediately with failure.
 *
 * @lock: spinlock to acquire.
 *
 * Returns:	0 on success.
 * 		-1 on failure.
 */

int spinlock_trylock (spinlock_t *lock);

/*
 * Release the referenced spinlock.
 *
 * @lock: spinlock to release.
 *
 * Returns:	0 on success.
 * 		-1 on failure.
 */

int spinlock_unlock (spinlock_t *lock);

#endif /* __SPINLOCK_H__ */
