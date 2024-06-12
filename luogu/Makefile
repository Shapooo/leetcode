.PHONY:test
all:test
test: test.out
	cat testcase | ./test.out

test.out: test.cpp
	clang++ -fsanitize=address -fsanitize=undefined -ggdb test.cpp -o test.out
