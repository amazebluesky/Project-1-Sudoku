project1:sudoku.o main.o
	g++ -o project1 main.o sudoku.o

sudoku.o:sudoku.cpp sudoku.h
	g++ -c sudoku.cpp

main.o:main.cpp sudoku.h
	g++ -c main.cpp

clean:
	rm sudoku.o main.o project1

