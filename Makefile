# Makefile for monte_carlo_pi.cpp
LDFLAGS=-L/usr/local/opt/llvm/lib
CPPFLAGS=-I/usr/local/opt/llvm/include

.PHONY: clean

pi_estimate: monte_carlo_pi.cpp
	clang++ ${LDFLAGS} ${CPPFLAGS} -std=c++1y -o3 -march=native -flto -fopenmp -o $@ $^

clean:
	rm -rf *.o *.dSYM pi_estimate
