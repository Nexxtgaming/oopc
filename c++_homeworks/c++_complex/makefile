# List your *.h files here:
headers =Complex.h 

# List your *.cpp files here:
sources = Complex.cpp TestComplex.cpp 

program: $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o program

.PHONY: clean check debug

clean:
	-rm program

check: program
	valgrind ./program

debug: program
	gdb program
