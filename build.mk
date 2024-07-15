SRC = $(wildcard *.c)
OBJ = ${SRC:.c=.o}

all: ${BIN}
	@echo all built

options:
	@echo "SRC: ${SRC}"
	@echo "OBJ: ${OBJ}"
	@echo "BIN: ${BIN}"

clean:
	@rm -rf ${OBJ} ${BIN}

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

${BIN}:
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: all clean options
