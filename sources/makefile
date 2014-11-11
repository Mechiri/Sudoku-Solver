objects = main.o sudoku.o

sudoku_solver: $(objects)
	g++ $(objects) -o $@

main.o: main.cpp sudoku.h
	g++ -c -std=c++11 $< -o $@

sudoku.o: sudoku.cpp sudoku.h
	g++ -c -std=c++11 $< -o $@

.PHONY: clean
clean:
	rm sudoku_solver $(objects)
