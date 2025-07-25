#include <stdio.h>

#include "filesys.h"
#include "file_parser.h"
#include "delete_file.h"
#include "vm.h"

int main(void)
{
    char *exile_filename = "test.seta";
    size_t prog_size;

    uint8_t *loaded_code = parse_program(exile_filename, &prog_size);
    if (!loaded_code) return 1;

    vm_t vm = {
        .code = loaded_code,
        .pc = 0,
        .sp = 0
    };

    vm_run(&vm);
    free(loaded_code);
}
