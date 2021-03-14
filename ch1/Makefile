# See LICENSE for details
.POSIX:

include ../config.mk

SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}
BIN =\
	hello\
	fahr-to-celsius\
	celsius-to-fahr\
	rev-fahr-to-celsius\
	getchar-is-eof\
	eof\
	count-btn\
	trim-blanks\
	list-tbs\
	word-per-line

all: ${BIN}
	@echo "all built"

clean:
	@echo cleaning
	@rm -rf ${OBJ} ${DEP} ${BIN} *.tar.gz

lint:
	cpplint ${SRC}


hello: hello.o
fahr-to-celsius: fahr-to-celsius.o
celsius-to-fahr: celsius-to-fahr.o
rev-fahr-to-celsius: rev-fahr-to-celsius.o
getchar-is-eof: getchar-is-eof.o
eof: eof.o
count-btn: count-btn.o
trim-blanks: trim-blanks.o
list-tbs: list-tbs.o
word-per-line: word-per-line.o

-include ${DEP}
