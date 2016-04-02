#include<iostream>
#include<cstdio>
#include<ctime>
#include<string>
#include<cstdlib>
#include "Sudoku.h"
#define UNASSIGNED 0
using namespace std;
bool Sudoku::SolveSudoku(int c[N][N])
{
	int row;
	int col;
	int num1;
	if (originRow(c,row,num1)==false||originCol(c,col,num1)==false){
		cout<<"0"<<endl;
		exit(1);
	}
	if (!FindUnassignedLocation(c, row, col))
		return true;
	for (int num = 1; num <= 9; num++)
	{
		if (isSafe(c, row, col, num))
		{
			c[row][col] = num;
			if (SolveSudoku(c))
				return true;
			c[row][col] = UNASSIGNED;
		}
	}
	return false;
}
bool Sudoku::SolveSudoku1(int c1[N][N])
{
	int row;
	int col;
	if (!FindUnassignedLocation(c1, row, col))
		return true;
	for (int num = 9; num >=1; num--)
	{
		if (isSafe(c1, row, col, num))
		{
			c1[row][col] = num;
			if (SolveSudoku1(c1))
				return true;
			c1[row][col] = UNASSIGNED;
		}
	}
	return false;
}

bool Sudoku::FindUnassignedLocation(int c[N][N], int &row, int &col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (c[row][col] == UNASSIGNED)
				return true;
	return false;
}
bool Sudoku::originRow(int c[N][N], int row, int num1)
{	for (int row=0;row<N;row++){
		for (int col=0;col<N;col++){
			for(int ocol=0;ocol<col;ocol++){
				if (c[row][col]!=0&&c[row][ocol]!=0){
				if 	(c[row][col]==c[row][ocol]){
					return false;
				}
				}
			}
		}		
		}
							   
	return true;
}
bool Sudoku::originCol(int c[N][N], int col, int num1)
{
	for (int col=0;col<N;col++){
		for (int row=0;row<N;row++){
			for(int orow=0;orow<row;orow++){
				if (c[row][col]!=0&&c[orow][col]!=0){
				 if  (c[row][col]==c[orow][col]){
					 return false;
				 }
			 }
		}
	}
	}
	return true;
}

bool Sudoku::UsedInRow(int c[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (c[row][col] == num)
			return true;
	return false;
}
bool Sudoku::UsedInCol(int c[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (c[row][col] == num)
			return true;
	return false;
}
bool Sudoku::UsedInBox(int c[N][N], int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (c[row+boxStartRow][col+boxStartCol] == num)
				return true;
	return false;
}
bool Sudoku::isSafe(int c[N][N], int row, int col, int num)
{
	return !UsedInRow(c, row, num) && !UsedInCol(c, col, num) &&
		!UsedInBox(c, row - row % 3 , col - col % 3, num);
}

void Sudoku::printGrid(int c[N][N])
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
			cout<<c[row][col]<<" ";
		cout<<endl;
	}
}

void Sudoku::giveQuestion(){
	int c[9][9]=
	   {
	   {0,0,0,0,6,4,0,9,0},
	   {0,2,0,0,0,0,5,0,0},
	   {0,0,0,0,0,9,0,0,0},
	   {9,0,1,0,0,0,0,0,0},
	   {0,0,4,0,0,0,2,0,0},
	   {0,0,0,0,0,0,7,0,3},
	   {0,0,0,3,0,0,0,0,0},
	   {0,0,8,0,0,0,0,4,0},
	   {0,6,0,2,7,0,0,0,0},
		};
	for (int i=0;i<9;i++){
		for(int j=0;j<9;j++){
		cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Sudoku::readIn(){
	for (int i=0;i<9;i++){
		for(int j=0;j<9;j++){
		cin >> c[i][j];
		}
	}
	for (int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			c1[i][j]=c[i][j];
			}
		}
}
void Sudoku::solve(){

	if (SolveSudoku(c)==true && SolveSudoku1(c1)==true){
			 for(int i=0;i<9;i++){
				 for(int j=0;j<9;j++){
					 if(c[i][j]!=c1[i][j]){
					 cout<<"2"<<endl;
					 exit(1);
					 }
					}
				}
			 cout<<"1"<<endl;
			printGrid(c);
	}
	else{ 
		cout<<"0"<<endl;
	}
}

void Sudoku::changeNum(int a , int b){
		int tmp1;
		int tmp2;
	for(int i=0; i<9; i++){
		for (int j=0;j<9;j++){
		if (c[i][j]==a){
			tmp1=b;
			c[i][j]=tmp1;
			}
		else if(c[i][j]==b){
			tmp2=a;
			c[i][j]=tmp2;
		}
		}
	}
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			c1[i][j]=c[i][j];
		}
	}
}
void Sudoku::changeRow(int a , int b){
	int temp1[9];
	int temp2[9];
	int temp3[9];
	int i;
	if (a==0&&b==1){
			for(i=0;i<9;i++){
			temp1[i]=c[0][i];
			temp2[i]=c[1][i];
			temp3[i]=c[2][i];
			c[0][i]=c[3][i];
			c[1][i]=c[4][i];
			c[2][i]=c[5][i];
	  		c[3][i]=temp1[i];
			c[4][i]=temp2[i];
			c[5][i]=temp3[i];		
			}
	}
	else if (a==0&&b==2){
		for(i=0;i<9;i++){
			temp1[i]=c[0][i];
			temp2[i]=c[1][i];
			temp3[i]=c[2][i];
			c[0][i]=c[6][i];
			c[1][i]=c[7][i];
			c[2][i]=c[8][i];
			c[6][i]=temp1[i];
			c[7][i]=temp2[i];
			c[8][i]=temp3[i];
		}
	}
	else if (a==1&&b==2){
		for(i=0;i<9;i++){
			temp1[i]=c[3][i];
			temp2[i]=c[4][i];
			temp3[i]=c[5][i];
			c[3][i]=c[6][i];
			c[4][i]=c[7][i];
			c[5][i]=c[8][i];
			c[6][i]=temp1[i];
			c[7][i]=temp2[i];
			c[8][i]=temp3[i];
		}
	}
	else if (a==1&&b==0){
		for(i=0;i<9;i++){
			temp1[i]=c[3][i];
			temp2[i]=c[4][i];
			temp3[i]=c[5][i];
			c[3][i]=c[0][i];
			c[4][i]=c[1][i];
			c[5][i]=c[2][i];
			c[0][i]=temp1[i];
			c[1][i]=temp2[i];
			c[2][i]=temp3[i];
		}
	}
	else if (a==2&&b==1){
		for(i=0;i<9;i++){
			temp1[i]=c[6][i];
			temp2[i]=c[7][i];
			temp3[i]=c[8][i];
			c[6][i]=c[3][i];
			c[7][i]=c[4][i];
			c[8][i]=c[5][i];
			c[3][i]=temp1[i];
			c[4][i]=temp2[i];
			c[5][i]=temp3[i];
		}
	}
	else if (a==2&&b==0){
		for(i=0;i<9;i++){
			temp1[i]=c[6][i];
			temp2[i]=c[7][i];
			temp3[i]=c[8][i];
			c[6][i]=c[0][i];
			c[7][i]=c[1][i];
			c[8][i]=c[2][i];
			c[0][i]=temp1[i];
			c[1][i]=temp2[i];
			c[2][i]=temp3[i];
		}
	}
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			c1[i][j]=c[i][j];
		}
	}
	}
void Sudoku::changeCol(int a , int b){
	int temp1[9][1];
	int temp2[9][1];
	int temp3[9][1];
	int i;
	if (a==0&&b==1){
		for(i=0;i<9;i++){
			temp1[i][1]=c[i][0];
			temp2[i][1]=c[i][1];
			temp3[i][1]=c[i][2];
			c[i][0]=c[i][3];
			c[i][1]=c[i][4];
			c[i][2]=c[i][5];
			c[i][3]=temp1[i][1];
			c[i][4]=temp2[i][1];
			c[i][5]=temp3[i][1];
		}
	}
	else if (a==0&&b==2){
		for(i=0;i<9;i++){
			temp1[i][1]=c[i][0];
			temp2[i][1]=c[i][1];
			temp3[i][1]=c[i][2];
			c[i][0]=c[i][6];
			c[i][1]=c[i][7];
			c[i][2]=c[i][8];
			c[i][6]=temp1[i][1];
			c[i][7]=temp2[i][1];
			c[i][8]=temp3[i][1];
		}
	}
	else if (a==1&&b==2){
		for(i=0;i<9;i++){
			temp1[i][1]=c[i][3];
			temp2[i][1]=c[i][4];
			temp3[i][1]=c[i][5];
			c[i][3]=c[i][6];
			c[i][4]=c[i][7];
			c[i][5]=c[i][8];
			c[i][6]=temp1[i][1];
			c[i][7]=temp2[i][1];
			c[i][8]=temp3[i][1];
		}
	}
	else if (a==1&&b==0){
		for(i=0;i<9;i++){
			temp1[i][1]=c[i][3];
			temp2[i][1]=c[i][4];
			temp3[i][1]=c[i][5];
			c[i][3]=c[i][0];
			c[i][4]=c[i][1];
			c[i][5]=c[i][2];
			c[i][0]=temp1[i][1];
			c[i][1]=temp2[i][1];
			c[i][2]=temp3[i][1];
		}
	}
	else if (a==2&&b==1){
		for(i=0;i<9;i++){
			temp1[i][1]=c[i][6];
			temp2[i][1]=c[i][7];
			temp3[i][1]=c[i][8];
			c[i][6]=c[i][3];
			c[i][7]=c[i][4];
			c[i][8]=c[i][5];
			c[i][3]=temp1[i][1];
			c[i][4]=temp2[i][1];
			c[i][5]=temp3[i][1];
		}
	}
	else if (a==2&&b==0){
		for(i=0;i<9;i++){
			temp1[i][1]=c[i][6];
			temp2[i][1]=c[i][7];
			temp3[i][1]=c[i][8];
			c[i][6]=c[i][0];
			c[i][7]=c[i][1];
			c[i][8]=c[i][2];
			c[i][0]=temp1[i][1];
			c[i][1]=temp2[i][1];
			c[i][2]=temp3[i][1];
		}
	}
	for (int i=0;i<9;i++){
		for (int j=0;j<9;j++){
			c1[i][j]=c[i][j];
	}
	}
}
void Sudoku::rotate(int n){
	int i;
	int j;
	int b[9][9];
		if (n%4==0){
			b[i][j]=c[i][j];
		}
		if (n%4==1){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				b[i][j]=c[9-j-1][i];
		}
		}
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				c[i][j]=b[i][j];
			}
		}	
		}
		if (n%4==2){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				b[9-i-1][j]=c[i][9-j-1];
		}
		}
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				c[i][j]=b[i][j];
			}
		}
		}
		if (n%4==3){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				b[j][i]=c[i][9-j-1];
		}
		}
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				c[i][j]=b[i][j];
			}
		}
		}
		for (int i=0;i<9;i++){
			for (int j=0;j<9;j++)
			{
				c1[i][j]=c[i][j];
			}
		}
}
void Sudoku::flip(int n){
	int i;
   	int j;
	int b[9][9];
	if (n==1){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				b[9-j-1][i]=c[j][i];
			}
		}
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				c[i][j]=b[i][j];
			}
		}
	}
	if (n==0){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				b[j][9-i-1]=c[j][i];
			}
		}
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				c[i][j]=b[i][j];
			}
		}
	}
	for (int i=0;i<9;i++){
		 for (int j=0;j<9;j++)
		 {
			  c1[i][j]=c[i][j];
		 }}
}
void Sudoku::change(){
	srand(time(NULL));
	changeNum(rand()%8+1,rand()%8+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}
void Sudoku::transform(){
	readIn();
	change();
	printGrid(c);
}
