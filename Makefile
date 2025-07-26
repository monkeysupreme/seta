# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -std=c17
LDFLAGS =
TARGET = build/seta

# Source and object files
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=build/%.o)

# Default rule
all: $(TARGET)

# Link the final executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

# Compile source files to object files
build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build directory exists
build:
	mkdir -p build

# Clean up
clean:
	rm -rf build

# Phony targets
.PHONY: all clean
