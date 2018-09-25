# _*_ MakeFile _*_

CC = gcc

CFLAGS = -Wall \
        -Werror \
	-g \
	-Iutils/include/

INC_PATH = utils/include

vpath %.c utils/src

SRC := memalloc.c memfree.c memdisplay.c memwrite.c xorinvert.c main.c help.c

OBJ := $(SRC:.c=.o)

main: $(OBJ)
	$(CC) -o main $(OBJ) $(CFLAGS)

main.o: $(INC_PATH)/memalloc.h $(INC_PATH)/memdisplay.h

memalloc.o: $(INC_PATH)/memalloc.h

memfree.o: $(INC_PATH)/memfree.h

memdisplay.o: $(INC_PATH)/memdisplay.h

memwrite.o: $(INC_PATH)/memwrite.h

xorinvert.o: $(INC_PATH)/xorinvert.h

help.o: $(INC_PATH)/help.h

clean:
	rm -f *.o main

