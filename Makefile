PHONY:
	${CC} -Wall -shared -o libroha.so src/*.c

check:
	${CC} -Wall -L. -lroha -o check-adler-32 test/adler-32.c
	LD_LIBRARY_PATH=`pwd` ./check-adler-32
