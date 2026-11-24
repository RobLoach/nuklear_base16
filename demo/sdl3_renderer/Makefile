BIN = nuklear_base16_sdl3_renderer

PKG_CONFIG ?= pkg-config

CFLAGS += -std=c99 -Wall -Wextra -pedantic -O0 -g
CFLAGS += $(shell $(PKG_CONFIG) --cflags sdl3)
LIBS += $(shell $(PKG_CONFIG) --libs sdl3) -lm

SRC = main.c

ifeq ($(OS),Windows_NT)
	BIN := $(BIN).exe
endif

.PHONY: clean test

$(BIN): $(SRC) ../common/nuklear_base16_demo.c ../../nuklear_base16.h
	$(CC) $(SRC) $(CFLAGS) -o $(BIN) $(LIBS)

clean:
	rm -f $(BIN)

test: clean $(BIN)
	./$(BIN)
