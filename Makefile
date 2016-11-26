CC=gcc
CFLAGS=-Wall -fPIC
DFLAGS=
LD_FLAGS=
INCLUDES=

#gcc -o Helloworld hellogtk.c `pkg-config --cflags --libs gtk+-3.0`

SOURCES=$(wildcard *.c)
TARGETS=$(patsubst %.c, %,$(SOURCES))
quiet-command = $(if $(v),$1,$(if $(2),@echo $2 && $1, @$1))

all:$(TARGETS)

%: %.c
	$(CC) $(INCLUDES) $(CFLAGS) $(DFLAGS) -o $@ $@.c `pkg-config --cflags --libs gtk+-3.0`

.PHONY:all clean
clean:
	@rm -f $(TARGETS)
