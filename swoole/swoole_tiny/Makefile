CC = gcc
CFLAGS = -I./src

CFILES = $(shell find ./ -name "*.c")
OBJS = $(CFILES:.c=.o)

tiny_swoole:$(OBJS)
	gcc $^ -o $@
clean:
	rm $(OBJS) tiny_swoole

