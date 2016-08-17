#include "builtin.h"
#include "common.h"

int main (int argc, char const *argv[])
{
	/* code */
	int i;
	if (argc < 2) {
		print_usage();
	}

	char command[128];
	strcpy(command, argv[1]);

	if (strcmp(command, "hash-object") == 0) {
		cmd_hash_object(argc, argv, "");
	} else if (strcmp(command, "pack-objects") == 0) {
		cmd_pack_objects(argc, argv, "");
	} else {
		fprintf(stderr, "Unknown command %s.\n", command);
		print_usage();
	}

	return 0;
}
