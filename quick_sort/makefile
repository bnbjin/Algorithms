BIN_DIR = bin/
INC_DIR = inc/
SRC_DIR = src/
COM_OPT = -I$(INC_DIR)

all : 
	gcc $(SRC_DIR)/quick_sort.c -c -o $(BIN_DIR)/quick_sort.o $(COM_OPT)
	gcc $(SRC_DIR)/test.c -c -o $(BIN_DIR)/test.o $(COM_OPT)
	gcc $(BIN_DIR)/*.o -o $(BIN_DIR)/test

clean :
	rm -f $(BIN_DIR)/*.o
	rm -f $(BIN_DIR)/test
