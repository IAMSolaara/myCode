SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	gcc `pkg-config --cflags ncurses` -o $@ $< `pkg-config --libs ncurses`
clean:
	rm -f $(PROGS)
