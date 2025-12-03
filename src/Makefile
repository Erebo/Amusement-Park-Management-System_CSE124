# Compiler
CC = gcc

# Compilation flags
CFLAGS = -Wall

# Output executable name
TARGET = park

# Automatically include ALL .c files in this folder
SRC = $(wildcard *.c)

# Build target (compile everything)
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Run the program after building
run: $(TARGET)
	./$(TARGET)

# Remove compiled files
clean:
	del *.exe 2>nul || true
	del *.o 2>nul || true
