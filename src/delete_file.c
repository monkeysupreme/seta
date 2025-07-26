#include "delete_file.h"

#include <time.h>

int delete_file(char *filename)
{
    delete_record_t *record = delete_record_new(filename, (int)time(NULL));

    if (remove(filename) == 0) {
        printf("SETA: Deleted file and created a delete record for %s\n", filename);
        return 0;
    } else {
        return 1;
    }

    delete_record_free(record);
}
