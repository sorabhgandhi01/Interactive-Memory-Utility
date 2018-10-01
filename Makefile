# _*_ MakeFile _*_

CC = gcc

CFLAGS = -Wall \
	 -Werror \
	 -g \
	 -Iutils/include/

INC_PATH = utils/include

vpath %.c utils/src

SRC := memalloc.c memfree.c memdisplay.c memwrite.c xorinvert.c main.c help.c exit.c global.c

OBJ := $(SRC:.c=.o)

main: $(OBJ)
	$(CC) -o main $(OBJ) $(CFLAGS)

clean:
	rm -f *.o main

