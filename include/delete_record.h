#ifndef SETA_DELETE_RECORD_H
#define SETA_DELETE_RECORD_H

#include <stdio.h>
#include <stdlib.h>

// DeleteRecord will eventually be used to restore files
// to the system in some way
struct DeleteRecord {
    char *filename;
    char *data;
    int unix_time;
};

typedef struct DeleteRecord delete_record_t;

// Create a new delete record
delete_record_t *delete_record_new(char *filename, int unix_time);

// Release a delete record in memory
void delete_record_free(delete_record_t *dr);

#endif // SETA_DELETE_RECORD_H
