# See LICENSE for details
.POSIX:

include ../config.mk

SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}
BIN =\
	hello\
	fahr-to-celsius\
	celsius-to-fahr

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

-include ${DEP}
