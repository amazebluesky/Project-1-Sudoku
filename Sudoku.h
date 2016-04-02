#include<iostream>
class Sudoku{
	public:
		void giveQuestion();
		void readIn();
		void solve();
		void change();
		void printout(bool isAns);
		void changeNum(int a , int b);
		void changeRow(int a , int b);
		void changeCol(int a , int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		#define N 9
		int c[N][N];
		int c1[N][N];
		bool SolveSudoku1(int c1[N][N]);
		bool SolveSudoku(int c[N][N]);
		bool FindUnassignedLocation(int c[N][N], int &row, int &col);
		bool originRow(int c[N][N],int row,int num1);
		bool originCol(int c[N][N],int col ,int num1);
		bool UsedInRow(int c[N][N], int row, int num);
		bool UsedInCol(int c[N][N], int col, int num);
		bool UsedInBox(int c[N][N], int boxStartRow, int boxStartCol, int num);
		bool isSafe(int c[N][N], int row, int col, int num);
		void printGrid(int c[N][N]);
	private:
};

