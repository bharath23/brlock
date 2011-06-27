/*
 * Copyright (c) 2011 Bharath Ramesh <bramesh.dev@gmail.com>
 *
 * Distributed under the terms of GNU LGPL, version 2.1
 */

#include <errno.h>
#include "chrono.h"
#include "semlock.h"

int
semlock_init (semlock_t *lock)
{
	lock->t = 0;
	if (sem_init (&lock->s, 0, 1) != 0)
		return -1;

	return 0;
}

int
semlock_lock (semlock_t *lock)
{
	int ret;

	while (1) {
		ret = sem_wait (&lock->s);
		if ((ret == -1) && (errno == EINTR))
			continue;

		break;
	}

	if (ret < 0)
		return -1;

	return 0;
}

int
semlock_timedlock (semlock_t *lock, uint64_t timeout)
{
	int ret;
	uint64_t t0, t1;
	struct timespec ts;

	t0 = get_time (&lock->t);
	t0 += timeout;
	while (1) {
		ts.tv_sec = t0 / 1000000;
		ts.tv_nsec = (t0 % 1000000) * 1000;
		ret = sem_timedwait (&lock->s, &ts);
		if (ret == 0)
			return 0;

		if ((errno == ETIMEDOUT) || (errno != EINTR))
			return -1;

		t1 = get_time (&lock->t);
		if (t1 > t0)
			return -1;
	}

	return -1;
}

int
semlock_trylock (semlock_t *lock)
{
	int ret;

	while (1) {
		ret = sem_trywait (&lock->s);
		if ((ret == -1) && (errno == EINTR))
			continue;

		break;
	}

	if (ret < 0)
		return -1;

	return 0;
}

int
semlock_unlock (semlock_t *lock)
{
	if (sem_post (&lock->s) != 0)
		return -1;

	return 0;
}
