all: test testwa

libfoo.a: foo.o
	ar -rcT $@ $<

%.o: %.c
	gcc -c $<

testwa: main.o libfoo.a
	gcc -o $@ -Wl,--whole-archive $^ -Wl,--no-whole-archive

test: main.o libfoo.a
	gcc -o $@ $^

clean:
	rm -f test* *.o *.a
