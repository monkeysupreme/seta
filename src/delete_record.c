#include "delete_record.h"

delete_record_t *delete_record_new(char *filename, int unix_time)
{
    delete_record_t *record = malloc(sizeof(delete_record_t));
    record->filename = filename;
    record->unix_time = unix_time;
    return record;
}

void delete_record_free(delete_record_t *dr)
{
    free(dr->filename);
    free(dr);
}
