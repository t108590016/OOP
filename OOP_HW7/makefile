.PHONY: all
CC = g++
SRC = ./src
BIN = ./bin
TEST = ./test
CFLAG = -Wfatal-errors
LIB = -lgtest -lpthread

#all: target
all: clean what $(BIN)/ut_all

#all: what $(BIN)/ut_all

#target: src/stringExample.cpp src/chk_string.cpp what
#	g++ src/stringExample.cpp src/chk_string.cpp -o bin/stringExample

karma: src/dot.cpp test/ut_main.cpp what
	g++ test/ut_main.cpp src/dot.cpp src/vector.cpp -o bin/ut_all -Wfatal-errors -lgtest -lpthread
	#$(CC) $(TEST) $(SRC) $(CFLAG) $(LIB) -o $(BIN)/ut_all
  # how to do ?

$(BIN)/ut_all : $(TEST)/ut_main.cpp $(SRC)/*.h
	$(CC) $(CFLAG) -o $@ $^ $(LIB)
	# $@ -> the name of target
	# $^ -> ALL dependenices of this target
	# $< -> the first dependenices of this target
what:
	mkdir -p bin obj

.PHONY: clean
clean:
	rm -f bin/*
	rm -f obj/*
