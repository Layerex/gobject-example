CC = clang
CFLAGS = `pkg-config --cflags glib-2.0 gobject-2.0`
CFLAGS += -std=c11 -Wall -Wextra -Wno-unused-parameter -O3
LDFLAGS = `pkg-config --libs glib-2.0 gobject-2.0`
EXEC = animal

SRC =  main.c animal_cat.c animal_tiger.c animal_predator.c
OBJ =  main.o animal_cat.o animal_tiger.o animal_predator.o

$(EXEC): $(OBJ)
	 $(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.c
	 $(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	 rm -f $(OBJ) $(EXEC)
