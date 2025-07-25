#include "delete_file.h"

#include <time.h>

int delete_file(char *filename)
{
    delete_record_t *record = NULL;

    if (remove(filename) == 0) {
        printf("SETA: Deleted file %s\n", filename);
        record = delete_record_new(filename, (int)time(NULL));
        return 0;
    } else {
        return 1;
    }

    delete_record_free(record);
}
