all: link_test
CFLAGS += -g -MD -Os
weak2.o: weak3.o
weak1.o: weak2.o
link_test: main.o weak2.o weak1.o weak3.o
	$(CC) -o $@ main.o weak2.o weak3.o weak1.o
clean:
	rm -f *.o link_test
-include *.d
