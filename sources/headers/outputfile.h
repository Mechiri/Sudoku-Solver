/*
	Project: Sudoku
		File: outputfile.h
	
	Author:  Mechiri Vinod Kumar
	Email:   mvk046@gmail.com
	Created: 29-Oct-2014
*/

#ifndef OUTPUTFILE_H
#define OUTPUTFILE_H
#include<fstream>

using namespace std;

class outputfile
{
	private:
		mutable ofstream ofile;

		void write_file( const int sudoku_matrix[9][9]) const throw();
	public:
		outputfile() throw();
		~outputfile() throw();
		
		void write_sudoku_input(const int sudoku_matrix[9][9]) const throw() ;
		void write_sudoku_result(const int sudoku_matrix[9][9]) const throw() ;
		void write_sudoku_details(const int number_of_sudoku_results,const float total_time) const throw();
};

#endif
