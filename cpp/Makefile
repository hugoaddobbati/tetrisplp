CC = g++
CFLAGS = -std=c++14
LIBS = -lncurses

DEPS = *.h
SRCS = colors.cpp gamestate.cpp gui.cpp menu.cpp point.cpp point.cpp tetris.cpp tetromino.cpp
OBJS = colors.o gamestate.o gui.o menu.o point.o point.o tetris.o tetromino.o

all: run

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

run: $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -rf *.o
	rm run