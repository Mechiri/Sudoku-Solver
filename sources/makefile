#
#	Project: Sudoku
#		File: makefile
#	
#	Author:  Mechiri Vinod Kumar
#	Email:   mvk046@gmail.com
#	Created: 29-Oct-2014
#

FILE_OPERATOINS_DIR := FilesOperations

CPP_DIR_PATH := . ./sudoku ./sudoku_error ./$(FILE_OPERATOINS_DIR)/f_input/ ./$(FILE_OPERATOINS_DIR)/f_output/
HEADERS_PATH := ./headers

vpath %.h $(HEADERS_PATH)
vpath %.cpp $(CPP_DIR_PATH)

INCL_HEDER_SEARCH_PATH := -I./headers

objects = main.o sudoku.o sudoku_error.o inputfile.o outputfile.o

sudoku_solver: $(objects)
	g++ $(objects) -o $@

sudoku_error.o: sudoku_error.cpp 
	g++ $(INCL_HEDER_SEARCH_PATH) -c -std=c++11 $< -o $@ 

main.o: main.cpp sudoku.h sudoku_error.h
	g++ $(INCL_HEDER_SEARCH_PATH) -c -std=c++11 $< -o $@

%.o: %.cpp %.h 
	g++ $(INCL_HEDER_SEARCH_PATH) -c -std=c++11 $< -o $@
	

.PHONY: clean
clean:
	rm sudoku_solver $(objects)
