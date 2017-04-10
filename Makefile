CC = gcc
TARGET = minesweeper
OBJS = conio.o minesweeper.o
HEAD = conio.h

all : $(TARGET)

$(TARGET) : $(OBJS)

$(OBJS) : $(HEAD)

.PHONY : clean

clean :
	rm $(OBJS) $(TARGET)

