export ROOT = $(shell pwd)
include common.make

.PHONY: all clean

all: prebuild $(BIN)

prebuild:
	mkdir -p $(BIN_DIR)

clean:
	make -C $(LIB_DIR) clean
	make -C $(SRC_DIR) clean
	rm -rf $(BIN_DIR)
tags:
	ctags -R $(SRC_DIR) $(INC_DIR)

$(BIN): libs objs

libs: prebuild
	make -C $(LIB_DIR)

objs: prebuild
	make -C $(SRC_DIR)
