/*
 * Copyright (c) 2011 Bharath Ramesh <bramesh.dev@gmail.com>
 *
 * Distributed under the terms of GNU LGPL, version 2.1
 */

#ifndef __BRLOCK_H__
#define __BRLOCK_H__

#include "brlocktypes.h"

/*
 * Initialize the referenced semlock.
 *
 * @lock: semlock to initialize.
 *
 * Returns:	0 on success.
 * 		-1 on failure.
 */

extern int semlock_init (semlock_t *lock);

/*
 * Acquires the referenced semlock.
 * This function blocks till the semlock can be acquired successfully.
 *
 * @lock: semlock to lock.
 *
 * Returns:	0 on success.
 * 		-1 on failure.
 */

extern int semlock_lock (semlock_t *lock);

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

extern int semlock_timedlock (semlock_t *lock, uint64_t timeout);

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

extern int semlock_trylock (semlock_t *lock);

/*
 * Releases the referenced semlock.
 *
 * @lock: semlock to unlock.
 *
 * Returns:	0 on success.
 * 		-1 on failure.
 */

extern int semlock_unlock (semlock_t *lock);

/*
 * Initialize the referenced spinlock.
 *
 * @lock: spinlock to initialize.
 *
 * Returns:	0 on success.
 * 		-1 on failure.
 */

extern int spinlock_init (spinlock_t *lock);

/*
 * Acquire the referenced spinlock.
 * This function spins till the spinlock can be sucessfully acquired.
 *
 * @lock: spinlock to acquire.
 *
 * Returns: 	0 on success.
 * 		-1 on failure.
 */

extern int spinlock_lock (spinlock_t *lock);

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

extern int spinlock_timedlock (spinlock_t *lock, uint64_t timeout);

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

extern int spinlock_trylock (spinlock_t *lock);

/*
 * Release the referenced spinlock.
 *
 * @lock: spinlock to release.
 *
 * Returns:	0 on success.
 * 		-1 on failure.
 */

extern int spinlock_unlock (spinlock_t *lock);

#endif /* __BRLOCK_H__ */
