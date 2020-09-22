// Purpose: 미로 문제에서 스택을 활용해 탈출구를 찾고 탈출 경로를 출력하기
// Requirement:
//  1. Make input data file (file name must be maze.txt) and get the input by using maze.txt open/read.
//  2. All of students have to program on provided skeleton code.
//  3. Implementing the following functions (described in cousrework book):
//      1. Pop() function: Remove one element from stack.
//      2. Push() function: Add one element into stack.
//		3. Path() function: Calculating maze exit path. (Refer to Program 3.12)
//			- Checking allowable path is Clockwise from N direction.
//			- Walking diagonal path is allowed.
//		4. PrintExitPath() function: Display the exit path on console.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

#define TRUE true
#define FALSE false

#define M 103
#define P 103
#define MAX_DIRECTION_SIZE 8
#define MAX_STACK_SIZE M * P

#define _MDH_DEBUG_

/* Structure definition  */
typedef struct {
	short int row;
	short int col;
	short int dir;
}element;

typedef struct {
	short int vert;
	short int horiz;
}offsets;

/* Maze-Related Variables Region */
// maze is variable for representing maze itself by using 0 or 1.
// 0 value means available path. On the otherhand, 1 value means wall so we cannot go this way.
char maze[M][P];
// mark is variable for presenting that you've already visited.
// 0 value means that you haven't been there and 1 value means that you have already visited.
char mark[M][P];
offsets move[MAX_DIRECTION_SIZE] = { {-1,0}, {-1,1}, {0,1}, {1,1},
	{1,0}, {1,-1}, {0,-1}, {-1,-1} };
// Coordinate (Row and Column of maze) of EXIT respectively.
int EXIT_ROW, EXIT_COL;

/* Stack-Related Variables Region */
element stack[MAX_STACK_SIZE];
int top;

/* Functions to be implemented by student */
element Pop(int* top);
void Push(element item, int* top);
void Path();
void PrintExitPath(int found, int row, int col);

/* Functions already implemented by MDH */
void PrintMaze();
void ReadMaze();

/* main Function */
int main()
{
	ReadMaze();
	//PrintMaze();

	Path();

	return 0;
}

void ReadMaze()
{
	FILE* _read_fp = fopen("maze.txt", "r");
	char _buf[M];
	int i;

	/* File Pointer Validation Check */
	if (!_read_fp) {
		fprintf(stderr, "Input file doesn't exist\n");
		fprintf(stderr, "Program will be Shutdown\n");
		exit(0);
	}

	/* Scanning Input */
	fscanf(_read_fp, "%d %d", &EXIT_ROW, &EXIT_COL);
	for (i = 1; i <= EXIT_ROW;i++) {
		fscanf(_read_fp, "%s", &maze[i][1]);
	}

	/* Enveloping maze in '1' which indicates artificial wall */
	for (i = 0; i <= EXIT_COL + 1; i++) {
		maze[0][i] = '1';
		maze[EXIT_ROW + 1][i] = '1';
	}
	for (i = 0; i <= EXIT_ROW + 1; i++) {
		maze[i][0] = '1';
		maze[i][EXIT_COL + 1] = '1';
	}
	fclose(_read_fp);

}
void PrintMaze()
{
	int i, j;
#ifdef _MDH_DEBUG_
	printf("Input Checking\n");
	printf("%d %d\n", EXIT_ROW, EXIT_COL);
#endif
	for (i = 0; i <= EXIT_ROW + 1; i++)
	{
		printf("%s\n", maze[i]);
	}

}

element Pop(int* top) {
	if(*top>=0){
		return stack[(*top)--];
	}
	else{
		printf("Stack is Empty");
		element position = {-1,-1,-1};
		return position;
	}
}

void Push(element item,int *top) {
	if(*top < MAX_STACK_SIZE -1){
		(*top)++;
		stack[*top] = item;
	}
}

void Path() {
	int i, row, col, next_row, next_col, dir;
	int found = FALSE;
	element position;
	top = 0;
	// Starting point
	mark[1][1] = 1;
	stack[0].row = 1;
	stack[0].col = 1;
	stack[0].dir = 1;

	while (top > -1 && !found){
		position = Pop(&top);
		row = position.row;
		col = position.col;
		dir = position.dir;
		while (dir < 8 && !found){
			next_row = row + move[dir].vert;
			next_col = col + move[dir].horiz;
			if (next_row == EXIT_ROW && next_col == EXIT_COL){
				found = TRUE;
				// Push current position
				position.row = row;
				position.col = col;
				Push(position, &top);
				
				// Push EXIT_ROW, EXIT_COL
				position.row = next_row;
				position.col = next_col;
				Push(position, &top);
			}
			else if(maze[next_row][next_col] == '0' && mark[next_row][next_col] == '\0'){
				mark[next_row][next_col] = 1; // 방문 표시
				position.row = row;
				position.col = col;
				position.dir = ++dir; // 다음 방문할 방향
				Push(position, &top);
				row = next_row;
				col = next_col;
				dir = 0;
			}
			else{
				++dir;
			}
		}
	}
	PrintExitPath(found,row,col);
}
void PrintExitPath(int found, int row, int col) {
	int i;
	if(found){
		for (i = 0; i < top; i++){
			printf("%d %d\n", stack[i].row, stack[i].col);
		}
		printf("%d %d", stack[top].row, stack[top].col);
	}
	else{
		printf("No exit: -1\n");
	}
}