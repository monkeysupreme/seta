#include "vm.h"

#include "delete_file.h"
#include <string.h>

void vm_push(vm_t *vm, char *value)
{
    if (vm->sp >= STACK_MAX) {
        fprintf(stderr, "VM: Stack overflow\n");
        exit(1);
    }
    vm->stack[vm->sp++] = value;
}

char *vm_pop(vm_t *vm)
{
    if (vm->sp <= 0) {
        fprintf(stderr, "VM: Stack underflow\n");
        exit(1);
    }
    return vm->stack[--vm->sp];
}

int vm_delete_file(char *filename)
{
    return delete_file(filename);
}

void vm_run(vm_t *vm) {
    while (1) {
        uint8_t instr = vm->code[vm->pc++];

//        printf("PC: %zu, OPCODE: 0x%02X\n", vm->pc - 1, instr);  // Debug print

        switch (instr) {
        case OP_PUSH: {
            char *start = (char *)&vm->code[vm->pc];
            size_t len = strlen(start);
            char *copied = malloc(len + 1);
            if (!copied) {
                fprintf(stderr, "VM: Out of memory\n");
                exit(1);
            }
            strcpy(copied, start);
            vm_push(vm, copied);
            vm->pc += len + 1;
            break;
        }
        case OP_DEL_FILE: {
            uint8_t length = vm->code[vm->pc++];
            char *str = malloc(length + 1);
            if (!str) {
                fprintf(stderr, "VM: Out of memory\n");
                exit(1);
            }

            memcpy(str, &vm->code[vm->pc], length);
            str[length] = '\0';
            vm->pc += length;

            int result = vm_delete_file(str);
            if (result != 0) {
               fprintf(stderr, "VM: Failed to delete file\n");
               exit(1);
            }
            free(str);
            break;
        }
        case OP_PRINT: {
            char *str = vm_pop(vm);
            printf("%s\n", str);
            free(str);
            break;
        }
        case OP_END: {
            printf("OP_END\n");
            return;
        }
        default:
            fprintf(stderr, "VM: Unknown opcode: 0x%02X\n", instr);
            return;
        }
    }
}
