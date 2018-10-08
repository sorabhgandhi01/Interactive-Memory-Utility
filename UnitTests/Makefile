# _*_ MakeFile _*_

CC = gcc

CFLAGS = -Wall \
	-Werror \
	-DUNIT_TEST \
	-I../utils/include/

LIBS = -lcunit

vpath %.c ../utils/src

SRC := memalloc.c memfree.c memdisplay.c memwrite.c xorinvert.c help.c exit.c global.c writepattern.c verifypattern.c util_test.c

OBJ := $(SRC:.c=.o)

unittest: $(OBJ)
	$(CC) -o unittest $(OBJ) $(CFLAGS) $(LIBS)

clean:
	rm -f *.o *.xml unittest                        
