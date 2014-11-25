#ifndef OUTPUTFILE_H
#define OUTPUTFILE_H
#include<fstream>

using namespace std;

class outputfile
{
	private:
		ofstream ofile;

		void write_file(int sudoku_matrix[9][9]);
	public:
		outputfile();
		~outputfile();
		
		void write_sudoku_input(int sudoku_matrix[9][9]);
		void write_sudoku_result(int sudoku_matrix[9][9]);
};

#endif
