/*
	Project: Sudoku
		File: sudoku.h
	
	Author:  Mechiri Vinod Kumar
	Email:   mvk046@gmail.com
	Created: 29-Oct-2014
*/

#if !defined _SUDOKU_H
#define _SUDOKU_H

class sudoku
{
	private:
		int sudoku_matrix[9][9];
		
	
		class empty_space
		{
			public:
			static int current_index;			
			
			int pos_r;
			int pos_c;
			int possible_numbers[9];
			int total_possible_numbers_length;
			
		} *es;
	
		
		int number_of_sudoku_results; //the number states how many sudoku results generated 
		
		void create();  //to create sudoko matrix
		int check();    // to check sudoku(rows, columns, 9 blocks)....
		

		void calculate_empty_spaces(); //to calculate empty spaces and fill the empty space details in empty space variable
		void calculate_possible_values(int index); //calculate possible values for empty spaces
		void row_details(int row, int* values); // calualte row elements and enter in to values
		void col_details(int col, int* values); // calualte row elements and enter in to values
		void block_details(int row, int col, int* values); // calualte row elements and enter in to values
		void sort_empty_spaces(); //sort empty_space with respect to total_possible_numbers_length
		
		void recursively_fill_update_onelength_emptyspace(); //fill all empty spaces which have only one possible value and repeat
		void recursively_fill_emptyspace(int index);  //fill all empty spaces which have greater than one possible values and repeat
		void fill_one_length_empty_spaces();          // fill all empty spaces which have only one possible value
		
		int check_rows();   //to check all 9 rows
		int check_columns();//to check all 9 columns
		int check_blocks(); //to check all 9 blocks

		
		int check_row(int,int);    //to check a row
		int check_column(int,int); //to check a column
		int check_block(int,int);  //to check a block
	
		/* debugger
		void display_empty_spaces();
		/ debugger */
		
	public:
		sudoku(); //constructor
		~sudoku();//destructor
		
		int total_empty_spaces;    //total number of empty spaces
		void solve();              // to solve sudoku
		void display() const;      // to display sudoku....
		void display_thenumber();  //to display the number of sudoku results generated
};

#endif
