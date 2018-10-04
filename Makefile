# _*_ MakeFile _*_

CC = gcc

CFLAGS = -Wall \
	 -Werror \
	 -g \
	 -O0 \
	 -Iutils/include/

INC_PATH = utils/include

vpath %.c utils/src

SRC := memalloc.c memfree.c memdisplay.c memwrite.c xorinvert.c main.c help.c exit.c global.c writepattern.c verifypattern.c

OBJ := $(SRC:.c=.o)

memory_util: $(OBJ)
	$(CC) -o memory_util $(OBJ) $(CFLAGS)

clean:
	rm -f *.o memory_util

