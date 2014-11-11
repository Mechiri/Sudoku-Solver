/*
	Project: Sudoku
		File: sudoku.cpp
	
	Author:  Mechiri Vinod Kumar
	Email:   mvk046@gmail.com
	Created: 29-Oct-2014
*/

#include"sudoku.h"
#include<iostream>

using namespace std;

int sudoku::empty_space::current_index = 0;

/* debugger
void sudoku::display_empty_spaces()
{
	for(int loop=0; loop<total_empty_spaces; loop++)
	{
		cout<<"pos: r:"<<es[loop].pos_r<<" c:"<<es[loop].pos_c<<" total:"<<es[loop].total_possible_numbers_length<<" values:";
		for(int n=0; n<es[loop].total_possible_numbers_length; n++)
			cout<<es[loop].possible_numbers[n]<<" ";
		cout<<endl;
	}
}
debugger */

void sudoku::solve()
{
	calculate_empty_spaces();
	recursively_fill_update_onelength_emptyspace();
	if( empty_space::current_index < total_empty_spaces )
		recursively_fill_emptyspace( empty_space::current_index );
	else
		display();
}

void sudoku::recursively_fill_emptyspace(int index)
{
	if(index >= total_empty_spaces)
	{
		display();
		return;
	}
	for(int loop=0; loop<es[index].total_possible_numbers_length; loop++)
	{
		sudoku_matrix[ es[index].pos_r ][ es[index].pos_c ] = es[index].possible_numbers[loop];
		if( check() )
			recursively_fill_emptyspace( index+1 );
	}
	sudoku_matrix[ es[index].pos_r ][ es[index].pos_c ] = 0;
}

void sudoku::fill_one_length_empty_spaces()
{
	int index = empty_space::current_index;
	
	while( es[index].total_possible_numbers_length == 1 && index<total_empty_spaces)
	{
		sudoku_matrix[ es[index].pos_r ][ es[index].pos_c ] = es[index].possible_numbers[0];
		es[index].total_possible_numbers_length = 0;
		++index;
	}
	
	empty_space::current_index = index;
}

void sudoku::recursively_fill_update_onelength_emptyspace()
{
	if( !(es[empty_space::current_index].total_possible_numbers_length == 1) || empty_space::current_index>=total_empty_spaces )
		return;
	
	fill_one_length_empty_spaces();
	for( int index = empty_space::current_index; index<total_empty_spaces; ++index )
		calculate_possible_values(index);
	sort_empty_spaces();
	
	recursively_fill_update_onelength_emptyspace();
}

void sudoku::calculate_empty_spaces()
{
	int index = 0;
	
	for(int row=0; row<9; row++)
		for(int col=0; col<9; col++)
		{
			if( !sudoku_matrix[row][col] )
			{
				es[index].pos_r = row;
				es[index].pos_c = col;
				
				calculate_possible_values( index );
				++index;
			}	
		}
	
	sort_empty_spaces();
	/* debugger
	if(index == total_empty_spaces)
		cout<<endl<<"YES PERFECT EMTY SPACES"<<endl;
	/ debugger */
}

void sudoku::sort_empty_spaces()
{
	empty_space temp_es;
	int temp_index;

	for(int loop1=1; loop1<total_empty_spaces; loop1++)
	{
		if( es[loop1-1].total_possible_numbers_length > es[loop1].total_possible_numbers_length )
		{
			temp_es = es[loop1];
			int loop2;
			for(loop2=loop1-1; loop2>=0 && (es[loop2].total_possible_numbers_length > temp_es.total_possible_numbers_length); loop2--)
			{
					es[loop2+1] = es[loop2];
			}
			es[loop2+1] = temp_es;
		}
	}
}

void sudoku::calculate_possible_values(int index)
{
	int possible_values[10] = {0};

	es[index].total_possible_numbers_length = 0;
	row_details( es[index].pos_r , possible_values );
	col_details( es[index].pos_c , possible_values );
	block_details( es[index].pos_r/3 * 3,  es[index].pos_c/3 * 3, possible_values);
	
	for(int number = 1; number < 10; number++)
	{
		if( !*(possible_values+number) )
		{
			es[index].possible_numbers[ es[index].total_possible_numbers_length ] = number;
			++es[index].total_possible_numbers_length;
		}
	}
}

void sudoku::row_details(int row, int* values)
{
	for(int col=0; col<9; col++)
		if( sudoku_matrix[row][col] )
			++values[ sudoku_matrix[row][col] ];
}

void sudoku::col_details(int col, int* values)
{
	for(int row=0; row<9; row++)
		if( sudoku_matrix[row][col] )
			++values[ sudoku_matrix[row][col] ];
}	

void sudoku::block_details(int row, int col, int* values)
{
	for(int r=0; r<3; r++)
		for(int c=0; c<3; c++)
			if( sudoku_matrix[row+r][col+c] )
				++values[ sudoku_matrix[row+r][col+c] ];
}


sudoku::sudoku() : sudoku_matrix{{0}}, total_empty_spaces(0), number_of_sudoku_results(0)
{ 
	create();
	
	if(total_empty_spaces)
		es = new empty_space[total_empty_spaces];
}

sudoku::~sudoku()
{
	delete[] es;
}

int get_number()
{
	int num;
	
	do
	{
		cin>>num;
		if( num>-1 && num<10 )
			return num;
		else
		{
			num = 99;
			cout<<"error: the number should be between 1 and 9 inclusive..."<<endl;
		}
	}while( num );
}

void sudoku::create()
{
	cout<<"\n\n\n\nPlease enter the numbers between 1 and 9 inclusive in (9x9) sudoku. Enter the numbers row by row.\n And for empty spaces please enter \"0\".\n\nENTER THE NUMBERS IN SUDOKO(9X9):\n";
	for(int row = 0; row < 9; row++)
		for(int col = 0; col < 9; col++)
		{
			bool flag = 0;
			do
			{
				if( flag )
					cout<<"error: the number is repititive may be in row or col or block..."<<endl;
				flag = 1;
				if( !(sudoku_matrix[row][col] = ::get_number()) )
					++total_empty_spaces;
				
			}while( !check() );
		}
}

int sudoku::check()
{
	if(check_blocks())
		if(check_rows())
			if(check_columns())
				return 1;
	return 0;
}

int sudoku::check_blocks()
{
	for(int row = 0; row <= 6; row += 3)
		for(int col = 0; col <= 6; col += 3)
			if( !check_block(row,col) )
				return 0;
	return 1;
}

int sudoku::check_block(int row, int col)
{
	unsigned int block[10] = {0};
		
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
		{
			if( sudoku_matrix[row+i][col+j] )
			{
				if( block[ sudoku_matrix[row+i][col+j] ] )
					return 0;
				else
					++block[ *( *(sudoku_matrix + (row+i) ) + (col+j) ) ];
			}
		}
	
	return 1;
}

int sudoku::check_rows()
{
	for(int row=0; row < 9; row++)
		if( !check_row(row,0) )
			return 0;
	return 1;
}

int sudoku::check_row(int row, int col)
{
	unsigned int row_data[10] = {0};
	
	while( col < 9 )
	{
		if( sudoku_matrix[row][col] )
		{
			if( row_data[ sudoku_matrix[row][col] ] )
				return 0;
			else
				++row_data[ *( *(sudoku_matrix+row )+ col) ];
		}
		++col;
	}
	return 1;
}

int sudoku::check_columns()
{
	for(int col = 0; col < 9; ++col)
		if( !check_column(0,col) )
			return 0;
	return 1;
}

int sudoku::check_column(int row, int col)
{
	unsigned int col_data[10] = {0};
	
	while( row < 9 )
	{
		if( sudoku_matrix[row][col] )
		{
			if( col_data[ sudoku_matrix[row][col] ] )
				return 0;
			else
				++col_data[ *( *(sudoku_matrix+row) + col ) ];
		}
		++row;
	}
	return 1;
}

void sudoku::display() const
{
	++const_cast<sudoku*>(this)->number_of_sudoku_results;
	cout<<"The content of sudoku:\n\n";
	
	for(int row = 0; row < 9; row++)
	{
		cout<<"\t";
		for(int col = 0; col < 9; col++)
		{
			printf("%-2d ",sudoku_matrix[row][col]);
		}
		cout<<endl;
	}
	cout<<endl<<endl;		
}
void sudoku::display_thenumber() const
{
	cout<<"The number of sudoku results generated are: "<<number_of_sudoku_results-1<<endl<<endl<<endl;
	cout<<"                                                  BYE TAKE CARE :)                                                   "<<endl;
}
