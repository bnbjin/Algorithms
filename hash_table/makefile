all : clean linked_mul

linked_div :
	gcc -g -c *.c 	
	gcc *.o -lm -o test

linked_mul : 
	gcc -g -c *.c 	
	gcc *.o -lm -o test

clean :
	rm -f *.o
	rm -f test
