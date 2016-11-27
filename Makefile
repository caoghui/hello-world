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

$(TARGETS): $(SOURCES)
	$(CC) $(INCLUDES) $(CFLAGS) $(DFLAGS) -o $@ $^ $(LD_FLAGS)

.PHONY:all clean
clean:
	@rm -f $(TARGETS)
