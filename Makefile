PHONY: lib

PREFIX ?= /usr/local

lib:
	${CC} -Wall -fPIC -shared -Wl,-soname,libroha.so.1 -o libroha.so.1.0 src/*.c
	ln -sf libroha.so.1.0 libroha.so
	ln -sf libroha.so.1.0 libroha.so.1

test: lib
	${CC} -Wall -Wl,-rpath,. -L. -o test-adler-32 test/adler-32.c -lroha
	./test-adler-32

clean:
	rm libroha.so*
	rm test-*

install: lib
	install -m 0644 libroha.so ${PREFIX}/lib/libroha.so
	install -m 0644 libroha.so.1 ${PREFIX}/lib/libroha.so.1
	install -m 0644 libroha.so.1.0 ${PREFIX}/lib/libroha.so.1.0
	install -m 0644 src/adler-32.h ${PREFIX}/include/adler-32.h

uninstall:
	rm -rf ${PREFIX}/lib/libroha.so \
		${PREFIX}/lib/libroha.so.1 \
		${PREFIX}/lib/libroha.so.1.0 \
		${PREFIX}/include/adler-32.h
