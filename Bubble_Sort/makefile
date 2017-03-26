all : clean
	g++ bubblesort.cpp -c
	g++ test.cpp -c
	g++ bubblesort.o test.o -o test
	./test

clean :
	rm -f *.o
	rm -f test
