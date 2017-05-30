.PHONY: clean prepare functions test

bin/alphabet: prepare obj/main.o obj/functions.o obj/interface.o
	gcc -o bin/alphabet obj/main.o obj/functions.o obj/interface.o

bin/test: prepare obj/functions.o obj/functest.o obj/cmain.o
	gcc -Wall -o bin/test obj/functions.o obj/functest.o obj/cmain.o

obj/functest.o: prepare test/functest.c
	gcc -Wall -c test/functest.c -o obj/functest.o -Ithirdparty -Isrc

obj/cmain.o: prepare test/main.c
	gcc -Wall -c test/main.c -o obj/cmain.o -Ithirdparty


obj/main.o: prepare src/main.c
	gcc -c src/main.c -o obj/main.o

obj/functions.o: prepare src/functions.c
	gcc -c src/functions.c -o obj/functions.o

obj/interface.o: prepare src/interface.c
	gcc -c src/interface.c -o obj/interface.o
	
clean:
	rm -f bin/* 
	rm -f obj/*
	
functions: bin/alphabet 
	bin/alphabet 
	
prepare: bin obj

bin:
	mkdir bin

test: bin/test
	bin/test

obj:
	mkdir obj
