objects = inputfile.o main.o sudoku_error.o

output: $(objects)
	g++ $^ -o $@

sudoku_error.o: sudoku_error.cpp sudoku_error.h
	g++ -c -std=c++11 $< -o $@

%.o: %.cpp inputfile.h
	g++ -c -std=c++11 $< -o $@

.PHONY: clean
clean:
	rm output $(objects) 
