#include "builtin.h"
#include "common.h"

static int pack_from_string(git_repository *repo, const char *str, git_packbuilder *pb)
{
	git_oid oid;
	git_object *obj;
	int err_code = 0;

	err_code = git_oid_fromstr(&oid, str);
	if (err_code != 0) {
		fprintf(stderr, "fatal: expected sha1, got garbage:\n%s\n", str);
		goto cleanup;
	}

	err_code = git_object_lookup(&obj, repo, &oid, GIT_OBJ_ANY);
	if (err_code != 0) {
		fprintf(stderr, "fatal: unable to read %s\n", str);
		goto cleanup;
	}

	err_code = git_packbuilder_insert(pb, &oid, NULL);

cleanup:
	git_object_free(obj);
	return err_code;

}

int cmd_pack_objects(int argc, const char **argv, const char *prefix)
{
	if (argc < 3) {
		print_usage();
	}
	git_libgit2_init();

	git_repository *repo = NULL;

	int err_open = git_repository_open_ext(&repo, ".", 0, NULL);

	if (err_open != 0) {
		fprintf(stderr, "error when opening repository\n");
	}

	git_packbuilder *pb = NULL;
	int init_builder = git_packbuilder_new(&pb, repo);

	if (init_builder != 0) {
		fprintf(stderr, "Error initialising pack builder\n");
	}

	int i;
	for (i = 2; i < argc; i++) {
		int err_pack = pack_from_string(repo, argv[i], pb);
		if (err_pack != 0) {
			break;
		}
	}

	char *line = NULL;
	size_t size;
	while (1) {
		int err_getline = getline(&line, &size, stdin);
		if (err_getline == -1) break;

		int err_pack = pack_from_string(repo, line, pb);
		if (err_pack != 0) break;
	}

	git_packbuilder_write(pb, ".", 0, NULL, NULL);

	git_packbuilder_free(pb);
	git_repository_free(repo);
	git_libgit2_shutdown();

	return 0;
}
