#include "file_parser.h"
#include "opcode.h"

#include <string.h>
#include <ctype.h>

uint8_t *parse_program(const char *filename, size_t *out_size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open program file");
        return NULL;
    }

    // Dynamically allocate a buffer for the bytecode (we'll resize it as we read)
    uint8_t *code = malloc(1024);
    if (!code) {
        fprintf(stderr, "Out of memory\n");
        fclose(file);
        return NULL;
    }
    size_t code_size = 0;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Trim trailing whitespace and newlines
        size_t len = strlen(line);
        while (len > 0 && isspace((unsigned char)line[len - 1])) {
            line[--len] = '\0';
        }

        if (line[0] == '\0') continue; // Skip empty lines

        // Parse opcode and arguments
        char *opcode_str = strtok(line, " ");
        char *arg = strtok(NULL, "");

        if (strcmp(opcode_str, "PUSH") == 0) {
            // OP_PUSH: First byte is the opcode, followed by the string data
            code[code_size++] = OP_PUSH;
            size_t arg_len = strlen(arg);
            memcpy(&code[code_size], arg, arg_len);
            code_size += arg_len;
            code[code_size++] = '\0'; // Null-terminate the string
        }
        else if (strcmp(opcode_str, "DEL_FILE") == 0) {
            // OP_DEL_FILE: First byte is the opcode, then length of string, then the string
            code[code_size++] = OP_DEL_FILE;
            size_t arg_len = strlen(arg);
            code[code_size++] = (uint8_t)arg_len;
            memcpy(&code[code_size], arg, arg_len);
            code_size += arg_len;
        }
        else if (strcmp(opcode_str, "PRINT") == 0) {
            // OP_PRINT: Just the opcode
            code[code_size++] = OP_PRINT;
        }
        else if (strcmp(opcode_str, "END") == 0) {
            // OP_END: End of program
            code[code_size++] = OP_END;
        }
        else {
            fprintf(stderr, "Unknown instruction: %s\n", opcode_str);
            free(code);
            fclose(file);
            return NULL;
        }
    }

    fclose(file);
    *out_size = code_size;
    return code;
}
