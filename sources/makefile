objects = main.o sudoku.o

sudoku_solver: $(objects)
	g++ $(objects) -o sudoku_solver

main.o: main.cpp sudoku.h
	g++ -c -std=c++11 main.cpp -o main.o

sudoku.o: sudoku.cpp sudoku.h
	g++ -c -std=c++11 sudoku.cpp -o sudoku.o

.PHONY: clean
clean:
	rm sudoku_solver $(objects)
