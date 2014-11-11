objects = main.o sudoku.o

sudoku_solver: $(objects)
	g++ $(objects) -o $@

%.o: %.cpp sudoku.h
	g++ -c -std=c++11 $< -o $@

.PHONY: clean
clean:
	rm sudoku_solver $(objects)
