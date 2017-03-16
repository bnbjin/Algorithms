all : clean
	g++ sign.cpp -c
	g++ squash.cpp -c
	g++ sign.o -o sign
	g++ squash.cpp -o squash

clean : 
	rm -f *.o
	rm -f sign
	rm -f squash
