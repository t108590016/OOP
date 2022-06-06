.PHONY: all
#all: target
all: test

target: src/dot.h directories
	g++ src/dot.h -o bin/dot

test: src/dot.h test/ut_main.cpp directories
	g++ test/ut_main.cpp src/dot.h -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin obj

.PHONY: clean
clean:
	rm -f bin/*
	rm -f obj/*
