all : clean test
	./test

test : test.o
	g++ test.o -o test

test.o: 
	g++ test.cpp -c -g

clean :
	rm -f *.o
	rm -f test
