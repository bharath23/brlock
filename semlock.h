/*
 * Copyright (c) 2011 Bharath Ramesh <bramesh.dev@gmail.com>
 *
 * Distributed under the terms of GNU LGPL, version 2.1
 */

#ifndef __SEMLOCK_H__
#define __SEMLOCK_H__

#include <semaphore.h>
#include <stdint.h>

struct __semlock_type {
	sem_t s;
	uint64_t t;
};

typedef struct __semlock_type semlock_t;

/*
 * Initialize the referenced semlock.
 *
 * @lock: semlock to initialize.
 *
 * Returns:	0 on success.
 * 		-1 on failure.
 */

int semlock_init (semlock_t *lock);

/*
 * Acquires the referenced semlock.
 * This function blocks till the semlock can be acquired successfully.
 *
 * @lock: semlock to lock.
 *
 * Returns:	0 on success.
 * 		-1 on failure.
 */

int semlock_lock (semlock_t *lock);

/*
 * Acquires the referenced semlock.
 * If the lock is already acquired, the calling thread blocks until the lock
 * is available to be re-acquired. If the lock cannot be acquired, this wait
 * will be terminated after timeout expires.
 *
 * @lock: semlock to lock.
 * @timeout: amount of time that call shall block in microseconds if the lock
 * 	cannot be acquired.
 *
 * Returns:	0 if the lock is acquired.
 * 		-1 if the lock cannot be acquired.
 */

int semlock_timedlock (semlock_t *lock, uint64_t timeout);

/*
 * Acquires the referenced semlock.
 * If the lock is open, it is equivalent to semlock_lock. If the lock cannot
 * be acquired the function shall return immediately with failure.
 *
 * @lock: semlock to lock.
 *
 * Returns:	0 if the lock is acquired.
 * 		-1 if the lock cannot be acquired.
 */

int semlock_trylock (semlock_t *lock);

/*
 * Releases the referenced semlock.
 *
 * @lock: semlock to unlock.
 *
 * Returns:	0 on success.
 * 		-1 on failure.
 */

int semlock_unlock (semlock_t *lock);

#endif /* __SEMLOCK_H__ */
