PHONY: lib

lib:
	${CC} -Wall -fPIC -shared -Wl,-soname,libroha.so.1 -o libroha.so.1.0 src/*.c
	ln -sf libroha.so.1.0 libroha.so
	ln -sf libroha.so.1.0 libroha.so.1

test: lib
	${CC} -Wall -Wl,-rpath,. -L. -o test-adler-32 test/adler-32.c -lroha
	./test-adler-32

clean:
	rm libroha.so*
	rm check-*
