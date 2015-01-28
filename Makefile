PHONY:
	cc -Wall -o rolling-hashes src/*.c

check:
	cc -Wall -o check-adler-32 src/adler-32.c test/adler-32.c
	./check-adler-32
