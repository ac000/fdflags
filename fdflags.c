/*
 * fdflags,c - Simple utility to show the open(2) flags for a file/dir
 *
 * Copyright (C) 2013		Andrew Clayton <andrew@digital-domain.net>
 *
 * Licensed under the GNU General Public License Version 2
 * See COPYING
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define pflag(flags, flag, name) \
	do { \
		if (flags & flag) \
			printf("%s\n", name); \
	} while (0)

#define NR_FLAGS	17

static unsigned long flags_i[] = {
		O_RDONLY,
		O_WRONLY,
		O_RDWR,
		O_APPEND,
		O_ASYNC,
		O_CLOEXEC,
		O_CREAT,
		O_DIRECT,
		O_DIRECTORY,
		O_EXCL,
		O_LARGEFILE,
		O_NOATIME,
		O_NOCTTY,
		O_NOFOLLOW,
		O_NONBLOCK,
		O_SYNC,
		O_TRUNC
		};
static char *flags_s[] = {
		"O_RDONLY",
		"O_WRONLY",
		"O_RDWR",
		"O_APPEND",
		"O_ASYNC",
		"O_CLOEXEC",
		"O_CREAT",
		"O_DIRECT",
		"O_DIRECTORY",
		"O_EXCL",
		"O_LARGEFILE",
		"O_NOATIME",
		"O_NOCTTY",
		"O_NOFOLLOW",
		"O_NONBLOCK",
		"O_SYNC",
		"O_TRUNC"
		};

int main(int argc, char *argv[])
{
	int i;
	unsigned long flags;

	if (argc < 2)
		exit(EXIT_FAILURE);

	flags = strtoul(argv[1], NULL, 8);
	for (i = 0; i < NR_FLAGS; i++)
		pflag(flags, flags_i[i], flags_s[i]);

	exit(EXIT_SUCCESS);
}
