INC_DIR = ../../DataStructure/

all : clean
	g++ heap_sort.cpp -I$(INC_DIR) -c
	g++ test.cpp -c
	g++ test.o heap_sort.o -o test

clean :
	rm -f *.o
	rm -f test
