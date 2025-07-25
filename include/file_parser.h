#ifndef SETA_FILE_PARSER_H
#define SETA_FILE_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t *parse_program(const char *filename, size_t *out_size);

#endif // SETA_FILE_PARSER_H
