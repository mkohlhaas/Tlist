binaries = $(subst .c,,$(wildcard *.c))

.PHONY: all clean

all: $(binaries)

clean:
	@-rm -f $(binaries)
