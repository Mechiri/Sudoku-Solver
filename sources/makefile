DIR_PATH := . ./sudoku ./sudoku_error
HEADERS_PATH := ./headers

vpath %.h $(HEADERS_PATH)
vpath %.cpp $(DIR_PATH)

INCL_SEARCH_PATH := -I./headers

objects = main.o sudoku.o sudoku_error.o

sudoku_solver: $(objects)
	g++ $(objects) -o $@

sudoku_error.o: sudoku_error.cpp sudoku_error.h
	g++ $(INCL_SEARCH_PATH) -c -std=c++11 $< -o $@

%.o: %.cpp sudoku.h
	g++ $(INCL_SEARCH_PATH) -c -std=c++11 $< -o $@

.PHONY: clean
clean:
	rm sudoku_solver $(objects)
