.PHONY: all clean run Cmr
# Flags And Compiler 
CC= gcc
CFLAGS= -Wall -Wextra -std=c11

# Directories  
INC_DIR = include/*.h
OBJ_DIR = Object 
BIN_DIR = build
SRC_DIR = src 
source = main.c 
# Target  executable 
TARGET = $(BIN_DIR)/setup.exe  
# source and Object  File

#all 
all: $(TARGET) 


$(TARGET): Object/cmr.o
	$(CC) $(CFLAGS) -o $@ $< 
Cmr:  $(source) $(INC_DIR)
	$(CC) -c $(source)  -o Object/cmr.o
# Clean Folder 
clean:

	rm -rf $(TARGET) Object/cmr.o


run: 
	cd build && ./setup.exe && cd ..