include config.mk

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS)

%:
	$(CC) -o $@ $^


SRC = $(wildcard src/*/*.c)
OBJ = ${SRC:.c=.o}
BIN = hello

all: ${BIN}
	@echo all built

options:
	@echo "SRC: ${SRC}"
	@echo "OBJ: ${OBJ}"
	@echo "BIN: ${BIN}"

clean:
	@rm -rf ${OBJ} ${BIN}

# ch1
hello: src/ch1/hello.o

.PHONY: all clean options
