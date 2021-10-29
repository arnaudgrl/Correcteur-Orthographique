# Compilateur
CC=gcc
# Options de compilation
CFLAGS=-std=c99 -Wall -Wextra -lm -g

# DÃ©finition des rÃ©pertoires de travail
SRC_DIR=src
BIN_DIR=bin
OBJ_DIR=obj
INC_DIR=./include


CFLAGS=-std=c99 -Wall -Wextra -lm -g -I$(INC_DIR)
# GÃ©nÃ©ration de la liste des exÃ©cutables
EXE_DIR= $(BIN_DIR)/implementation2

OBJ_FILES= $(OBJ_DIR)/arbreprefixe.o $(OBJ_DIR)/lecture.o $(OBJ_DIR)/implementation2.o



all: $(EXE_DIR)

$(BIN_DIR)/implementation2 : $(OBJ_FILES) $(OBJ_DIR)/implementation2.o
		$(CC) -o $@ $^



$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
			$(CC) $(CFLAGS) $^ -o $@



clean:
	rm -rf $(BIN_DIR)
	rm -f gmon.out
