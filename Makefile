PHONY: lib

lib:
	${CC} -Wall -fPIC -shared -Wl,-soname,libroha.so.1 -o libroha.so.1.0 src/*.c

test: lib
	${CC} -Wall -Wl,-rpath,`pwd` -L. -lroha -o check-adler-32 test/adler-32.c
	./check-adler-32

clean:
	rm libroha.so.*
	rm check-*
