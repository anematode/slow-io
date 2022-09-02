
main: test.cc perf.h slowio.h
	g++ test.cc -o bin/test -O2 -g -march=native

skx: test.cc perf.h slowio.h
	g++ test.cc -o bin/test -O2 -g -march=skylake-server

.PHONY clean:
	rm bin/*
