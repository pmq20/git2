/* hash-object.c for the "Hash-Object" suite */
#include "clar_test.h"

static const char* sample_file = "sample_file";

static const char* repo_dir = "/tmp/testrepo";

static const char* content = "Hello, World!";

static const char* obj_path = "/tmp/testrepo/.git/objects/8a/b686eafeb1f44702738c8b0f24f2567c36da6d";

FILE *f = NULL;

git_repository *repo = NULL;

void test_hash_object__initialize(void)
{	
	mkdir(repo_dir, 0755);
	chdir(repo_dir);

	git_repository_init_options opts = GIT_REPOSITORY_INIT_OPTIONS_INIT;
	opts.flags |= GIT_REPOSITORY_INIT_MKPATH;
	int err_init = git_repository_init_ext(&repo, repo_dir, &opts);
	if (err_init != 0) {
		printf("%d\n", err_init);
		fprintf(stderr, "error init repository\n");
	}

	f = fopen(sample_file, "wb+");
	fprintf(f, "Hello, World!\n");

cleanup:
	if (f != NULL) fclose(f);
}

void test_hash_object__verify_checksum(void)
{
	printf("test hash object\n");

	char *cwd = malloc(sizeof(char) * 1024);
	if (getcwd(cwd, sizeof(cwd)) != NULL) return;
	
	int num_command = 3;
	const char **argv = (const char *[]){"git2", "hash-object", sample_file};

	cl_assert_(cmd_hash_object(num_command, argv, NULL) == 0, "hash object does not return error code.");

	FILE *obj_file = fopen(obj_path, "r");
	cl_assert_(obj_file != NULL, "a blob has been created by hash_object.");

	if (cwd != NULL) free(cwd);
	if (obj_file != NULL) fclose(obj_file);

}

void test_hash_object__cleanup(void)
{
	if (repo != NULL) git_repository_free(repo);
	remove(repo_dir);
}
