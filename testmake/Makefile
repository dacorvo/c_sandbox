all: foo.o

%.o: %.c compiler.flags
	@echo "Cflags: $(CC_FLAGS)"
	gcc -c -o $@ $<

#compiler.flags: build_compiler.flags

compiler.flags: FORCE
	echo '$(CC_FLAGS)' | cmp -s - compiler.flags || echo '$(CC_FLAGS)' > compiler.flags

clean:
	rm -f *.o

.PHONY: FORCE
