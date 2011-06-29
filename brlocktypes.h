/*
 * Copyright (c) 2011 Bharath Ramesh <bramesh.dev@gmail.com>
 *
 * Distributed under the terms of GNU LGPL, version 2.1
 */

#ifndef __BRLOCKTYPES_H__
#define __BRLOCKTYPES_H__

#include <semaphore.h>
#include <stdint.h>

struct __semlock_type {
	sem_t s;
	uint64_t t;
};

typedef struct __semlock_type semlock_t;

struct __spinlock_type {
	volatile int32_t l;
	uint64_t t;
};

typedef struct __spinlock_type spinlock_t;

#endif /* __BRLOCKTYPES_H__ */
