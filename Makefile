CC=gcc
CFLAGS=-Wextra -Wall -pedantic -g
LDFLAGS=-lm

SRC=memoire.c lecture.c pile.c yforth.c
OBJ=${SRC:.c=.o}
EXE=yforth

all: $(EXE)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) $(LDFLAGS)

debug:
	lldb $(EXE)

run:
	./$(EXE)

clean:
	rm $(EXE) *.o
