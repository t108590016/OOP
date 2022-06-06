.PHONY: all
all: target
all: test

target: src/ConvString.cpp src/ConvStringMain.cpp directories
	g++ src/ConvString.cpp src/ConvStringMain.cpp -o bin/ConvString

test: src/ConvString.cpp test/ut_all.cpp directories
	g++ test/ut_all.cpp src/ConvString.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin obj

.PHONY: clean
clean:
	rm -f bin/*
	rm -f obj/*
