# git2

Git2 implement git commands in libgit2.

[![Travis Build Status](https://secure.travis-ci.org/pmq20/git2.svg?branch=master)](http://travis-ci.org/pmq20/git2)

## Usage

    git2 <command> [<args>]

Currently available commands are:

     upload-pack
         Send objects packed back to git-fetch-pack.
     receive-pack
         Receive what is pushed into the repository.
     pack-objects
         Create a packed archive of objects.
     unpack-objects
         Unpack objects from a packed archive.
