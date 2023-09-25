IDIR = header
SDIR = src
ODIR = obj

CC = g++
CFLAGS=-I$(IDIR)


all: create assign1dfo301 clean
_DEPS = node.h stack.h expressiontree.h conversions.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o node.o stack.o conversions.o expressiontree.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
create:
	mkdir $(ODIR)

assign1dfo301: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	mv assign1dfo301 ../

clean:
	rm -r $(ODIR)
