include config.mk

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS)

%:
	$(CC) -o $@ $^


SRC = $(wildcard src/*/*.c)
OBJ = ${SRC:.c=.o}
BIN = hello fahr celsius fahr-rev iseof eof blank-count blank-dedup blank-vis\
	  word-per-line

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
fahr: src/ch1/fahr.o
celsius: src/ch1/celsius.o
fahr-rev: src/ch1/fahr-rev.o
iseof: src/ch1/iseof.o
eof: src/ch1/eof.o
blank-count: src/ch1/blank-count.o
blank-dedup: src/ch1/blank-dedup.o
blank-vis: src/ch1/blank-vis.o
word-per-line: src/ch1/word-per-line.o

.PHONY: all clean options
