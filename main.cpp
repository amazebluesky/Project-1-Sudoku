#include<iostream>
#include"Sudoku.h"
using namespace std;
int main(){
	int a1;
	int b1;
	Sudoku Sudoku1;
	Sudoku1.giveQuestion();
	Sudoku1.readIn();
	Sudoku1.solve();
return 0;
}
