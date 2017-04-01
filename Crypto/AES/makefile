all : clean my_aes
	
my_aes:
	gcc my_aes.c -c -g
	gcc main.c -c -g
	gcc my_aes.o main.o libssl.a libcrypto.a -o test -lpthread -ldl

clean : 
	rm -f *.o
	rm -f test
