# List your *.h files here:
headers = Employee.h Map.h Book.h

# List your *.c files here:
sources = Employee.cpp TestMap.cpp Book.cpp

program: $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o program

.PHONY: clean check debug

clean:
	-rm program

check: program
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./program

debug: program
	gdb program
