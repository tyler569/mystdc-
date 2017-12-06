
all: safe

safe:
	clang++ -std=c++11 -g -O0 test.cpp -fsanitize=address

fast:
	clang++ -std=c++11 -O3 test.cpp
