#
# Copyright (c) 2011 Bharath Ramesh <bramesh.dev@gmail.com>
#

# set compiler to be used
CC = gcc

# set compile time flags
ARCH = -m64
C99 = -std=c99
CFLAGS = -g -Wall -Wextra -O3
SOCFLAGS = -fPIC
GNU = -D_GNU_SOURCE
LIBRARY = -lpthread

OBJECTS = semlock.o spinlock.o

# compilation step
.c.o:
	$(CC) $(ARCH) $(C99) $(CFLAGS) $(SOCFLAGS) $(GNU) -c $<

all: lib

clean:
	rm -f libbrlock.so
	rm -f *.o

lib: $(OBJECTS)
	$(CC) -shared -Wl,-soname,libbrlock.so -o libbrlock.so $< $(LIBRARY)
