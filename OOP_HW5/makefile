.PHONY: all

all: test

test: src/vector.h src/shape.h src/circle.h src/polygon.h test/ut_main.cpp directories
	g++ test/ut_main.cpp src/vector.h src/shape.h src/circle.h src/polygon.h -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin obj

.PHONY: clean
clean:
	rm -f bin/*
	rm -f obj/*
