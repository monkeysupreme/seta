#ifndef SETA_VM_H
#define SETA_VM_H

#include "opcode.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define STACK_MAX 256

struct VM {
    uint8_t *code;
    int pc; // program counter
    char *stack[STACK_MAX];
    int sp; // stack pointer (index of top)
};

typedef struct VM vm_t;

// Push a value onto stack
void vm_push(vm_t *vm, char *value);

// Pop value from stack
char *vm_pop(vm_t *vm);

// Delete a file
int vm_delete_file(char *filename);

// Run the bytecode (VM)
void vm_run(vm_t *vm);

#endif // SETA_VM_H
