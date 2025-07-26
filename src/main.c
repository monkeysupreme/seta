#include <stdio.h>

#include "file_parser.h"
#include "delete_file.h"
#include "vm.h"

void create_and_run_vm(uint8_t *code)
{
    vm_t vm = {
        .code = code,
        .pc = 0,
        .sp = 0
    };

    vm_run(&vm);

    free(code);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "CLI: Not enough arguments\n");
        fprintf(stderr, "Usage: ./seta <prog>.seta");
        exit(1);
    }

    char *filename = argv[1];
    size_t prog_size;

    uint8_t *bytecode = parse_program(filename, &prog_size);
    if (!bytecode) return 1;

    create_and_run_vm(bytecode);
}
