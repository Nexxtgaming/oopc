# List your *.h files here:
headers = Matrix.h Exceptions.h

# List your *.c files here:
sources = Matrix.cpp TestMatrix.cpp Exceptions.cpp

program: $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o program

.PHONY: clean check debug

clean:
	-rm program

check: program
	valgrind --leak-check=full --show-leak-kinds=all ./program

debug: program
	gdb program
