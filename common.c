#include "common.h"

void print_usage(void)
{
	fprintf(stderr, "Usage: \n");
	fprintf(stderr, "\tgit2 hash-object [file-spec] [...]\n");
	fprintf(stderr, "\tgit2 pack-objects [object-list] < object-list\n");
	exit(1);
}
