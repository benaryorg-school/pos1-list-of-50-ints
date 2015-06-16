SRCPATH:=src

SRCS=$(shell find $(SRCPATH) -regextype posix-extended -regex '^.+\.(c)$$')
OBJS=$(addprefix build,$(addsuffix .o,$(basename $(SRCS:$(SRCPATH)%=%))))

CC:=gcc
LD:=gcc

LDFLAGS:=
CFLAGS:=$(addprefix -I,$(SRCPATH))

default: main

all: clean main

main: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

build/%.o: $(SRCPATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJS)
	rm -f main

.PHONY: clean

