# _*_ MakeFile _*_

CC = gcc

CFLAGS = -Wall \
	 -Werror \
	 -g \
	 -O0 \
	 -Iutils/include/

vpath %.c utils/src

SRC := memalloc.c memfree.c memdisplay.c memwrite.c xorinvert.c main.c help.c exit.c global.c writepattern.c verifypattern.c

OBJ := $(SRC:.c=.o)

memory_util: $(OBJ)
	$(CC) -o memory_util $(OBJ) $(CFLAGS)

test: memory_util test.txt
	./memory_util < test.txt

clean:
	rm -f *.o memory_util
