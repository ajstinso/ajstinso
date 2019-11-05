/*
 * C++ Program to Implement Floyd-Warshall Algorithm
 */
#include <iostream>

//global row and column variables
int r = 0; 
int c = 0;

void floyds(int b[][7])//floyds algorithm function
{

    for (int k = 0; k < r; k++)//for loop that loops the total number of times as there are D matrices
    {
        for (int i = 0; i < r; i++)//loop over all the rows in the matrix
        {
            for (int j = 0; j < c; j++)//while looping over all the rows each time loop through all the columns
            {
                if ((b[i][k] * b[k][j] != 0) && (i != j))//checks to see if the two referenced row and column are not the same number
                {
                    if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))//if checks to see if the current matrix place 
																		//is better than the previous one
                    {
                        b[i][j] = b[i][k] + b[k][j];//if it is then set the matrix location to this new path length
                    }
                }
            }
        }
    }
    for (int i = 0; i < r; i++)//once the above loop is done loop as many times as there are rows
    {
        std::cout<<"Shorest path for row " << (i+1) << ": ";
        for (int j = 0; j < c; j++)//loop through all of the columns 
        {
            std::cout<<b[i][j]<<"\t";//print out the shortest path for each matrix place
        }
		
		std::cout << "\n";//blank line of space
    }
}
int main()//main function
{	
	std::cout << "Enter the size of the matrix you would like to calculate:" << std::endl;
	
	std::cout << "Size of the rows and columns: ";
	std::cin >> r;//collect user input for the size of the matrix
	std::cout << "\n"; //blank line of space
	
	c=r;//set the numbers of columns equal to the number of rows 
	
    int b[7][7];//establish the matrix b as a max of 7X7
    std::cout<<"Enter the values for the matrix" << std::endl;
	
    for (int i = 0; i < r; i++)//loop through the number of rows there are
    {
        std::cout << "enter values for " << "row number " << (i+1) << std::endl;
        for (int j = 0; j < c; j++)
        {
            std::cin>>b[i][j];//collect user input for all the matrix locations
        }
    }
	
	std::cout << "\n";//blank line of space
    floyds(b);//run floyds algorithm using the matrix b

}