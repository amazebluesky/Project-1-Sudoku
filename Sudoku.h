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
		bool Sudoku1(int c1[N][N]);
		bool Sudoku2(int c[N][N]);
		bool FUL(int c[N][N], int &row, int &col);
		bool originRow(int c[N][N],int row,int num1);
		bool originCol(int c[N][N],int col ,int num1);
		bool Row(int c[N][N], int row, int num);
		bool Col(int c[N][N], int col, int num);
		bool Box(int c[N][N], int SR, int SC, int num);
		bool Safe(int c[N][N], int row, int col, int num);
		void print(int c[N][N]);
	private:
};

