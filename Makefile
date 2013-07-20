CC = gcc
DEBUG = -g
CFLAGS = -Wall -Werror -c -std=c99 $(DEBUG)
LDFLAGS = -Wall $(DEBUG)
MAKE = make

INC_DIR = ./inc/
SRC_DIR = ./src/
BIN_DIR = ./bin/

INC = $(shell find . -name *.h)
SRC = $(shell find . -name *.c)
OBJ = $(strip $(subst $(SRC_DIR), $(BIN_DIR), $(SRC:.c=.o)))
BIN = tinygrind

.PHONY: all clean

all: prebuild $(BIN)

prebuild:
	@mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BIN)
	rm -rf $(BIN_DIR)
	rm -rf tags
	@echo "Done cleaning!"

tags:
	ctags -R $(SRC_DIR) $(INC_DIR)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(BIN_DIR)/$(BIN)

$(BIN_DIR)%.o: $(SRC_DIR)%.c $(INC)
	$(CC) $(CFLAGS) -I $(INC_DIR) $< -o $@
