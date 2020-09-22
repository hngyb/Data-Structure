// Purpose: Linked list로 구현된 Stack을 사용하여 Infix 수식을 Postfix 수식으로 변경하기.
// Requirement:
//  1. Make input data file (Infix.txt) and get the input using file I/O.
//  2. All of students have to program on provided skeleton code.
//  3. Implementing the following functions (described in cousrework book):
//		1. getToken(): Get the next token in expression.
//		2. postfix(): Actually convert expression into postfix-manner.
//		3. Pop() and Push(): Stack operation implemented by Linked list.
//		(Parameters of function can be manipulated by student.)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_SIZE 1000

typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;

/* Global Variables */
typedef struct stack* stack_pointer;
typedef struct stack {
	precedence item;
	stack_pointer link;
};
stack_pointer top;
/* expression */
char expr[MAX_EXPR_SIZE];
/* isp, icp */
static int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
static int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };


/* Functions already implemented by MDH */
void readExpr(FILE* _fp, char* _expr);

/* Functions to be implemented by student */
precedence getToken(char*, int*);
void postfix();
void printToken(precedence);
precedence pop();
void push(precedence);

int main()
{
	/* Local variables */
	FILE* readfp = fopen("Infix.txt", "r");

	readExpr(readfp, expr);

	postfix();
	
	return 0;
}
void readExpr(FILE* _fp, char* _expr)
{

	/* File Existence Check */
	if (!_fp) {
		fprintf(stderr, "Input file doesn't exist\n");
		fprintf(stderr, "Program will be shuts down\n");
		exit(0);
	}

	/* Scanning Input */
	fscanf(_fp, "%s", _expr);

	fclose(_fp);
}

precedence getToken(char* symbol, int* n) {
	*symbol = expr[(*n)++];
	switch (*symbol) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%':return mod;
	case '\0':return eos;
	default: return operand;
	}
}
void postfix() {
	char symbol;
	precedence token;
	int n = 0;

	top = (stack_pointer)malloc(sizeof(struct stack));
	top->item = eos;
	top->link = NULL;

	for (token = getToken(&symbol, &n);token != eos;token = getToken(&symbol, &n)) {
		if (token == operand) {
			printf("%c", symbol);
		}
		else if (token == rparen) {
			while (top->item != lparen) {
				printToken(pop());
			}
			// discard left paranthesis
			pop();
		}
		else {
			while (isp[top->item] >= icp[token]) {
				printToken(pop());
			}
			push(token);
		}
	}
	while ((token = pop()) != eos) {
		printToken(token);
	}
	printf("\n");
}
precedence pop() {
	stack_pointer temp = top;
	precedence item;
	item = temp->item;
	top = temp->link;
	free(temp);
	return item;
}
void push(precedence item) {
	stack_pointer temp;
	temp = (stack_pointer)malloc(sizeof(struct stack));
	temp->item = item;
	temp->link = top;
	top = temp;
}
void printToken(precedence item) {
	switch (item) {
	case lparen: printf("%c", '(');
		break;
	case rparen: printf("%c", ')');
		break;
	case plus: printf("%c", '+');
		break;
	case minus: printf("%c", '-');
		break;
	case divide: printf("%c", '/');
		break;
	case times: printf("%c", '*');
		break;
	case mod:printf("%c", '%');
		break;
	}
}
