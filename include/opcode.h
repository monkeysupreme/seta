#ifndef SETA_OPCODE_H
#define SETA_OPCODE_H

// We have 4 instructions
// 1. OP_PUSH: Push a file path
// 2. OP_PRINT: Print the path - verify the path is correct
// 3. OP_DEL_FILE: Delete a file (crucial for this program)
// 4. OP_END: End the program

#define OP_PUSH     0x01
#define OP_DEL_FILE 0x02
#define OP_PRINT    0x03
#define OP_END      0x04

#endif // SETA_OPCODE_H
