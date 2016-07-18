PROJECT(GIT2)

FIND_PATH(LIBGIT2_INCLUDE_DIR NAMES git2.h)
FIND_LIBRARY(LIBGIT2_LIBRARIES NAMES git2)

SET(SRC_ALL receive-pack.c
            pack-objects.c
            unpack-objects.c)

ADD_EXECUTABLE(git2 git2.c ${SRC_ALL})
ADD_EXECUTABLE(git2-upload-pack upload-pack.c ${SRC_ALL})
