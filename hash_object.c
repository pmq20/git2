#include "builtin.h"
#include "common.h"

/*
 * Computes object ID and optionally creates a blob from a file
 * The blob will be created in the ODB
 */
int cmd_hash_object(int argc, const char **argv, const char *prefix)
{
	if (argc < 3) {
		print_usage();
	}
	git_repository *repo = NULL;
	
        git_libgit2_init();

	int err_open = git_repository_open_ext(&repo, ".", 0, NULL);
	if (err_open != 0) {
		printf("error code %d\n", err_open);
		fprintf(stderr, "error when opening repository\n");
	} else {
		int i;
		for (i = 2; i < argc; i++) {
			git_oid blob_id;
			int err_creation = git_blob_create_fromdisk(&blob_id, repo, argv[i]);
			if (err_creation != 0)
				continue;

			printf("%s\n", git_oid_tostr_s(&blob_id));
		}
	}

	if (repo != NULL) git_repository_free(repo);
	git_libgit2_shutdown();

	return 0;
}
