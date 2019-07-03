CFLAGS=-Wall -Wextra -g -std=c11 -DDEBUG

all: annotations_demo

%.o: %.c annotations.h
	gcc  $(CFLAGS) -c $< -o $@

annotations_demo: annotations_demo.o annotations.h
	gcc  $(CFLAGS) annotations_demo.o -o annotations_demo

.phony: clean

clean:
	rm -f annotations_demo *.o


