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
	
}

void Push(element item,int *top) {
	
}

void Path() {
	
}
void PrintExitPath(int found, int row, int col) {
	
}
