/*
 * Copyright (c) Vicent Marti. All rights reserved.
 *
 * This file is part of clar, distributed under the ISC license.
 * For full terms see the included COPYING file.
 */

#include "clar_test.h"

#ifdef _WIN32
int __cdecl main(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
        git_libgit2_init();

	int ret = clar_test(argc, argv);

        git_libgit2_shutdown();

        return ret;
}
