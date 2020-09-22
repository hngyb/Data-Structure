// Purpose: Implementing Polynomial Addition by using array data structure.
// Requirement:
//	1. Use dynamic memory allocation.
//	2. Make input data file and get the input by using file open/read
//	3. Understanding the array representation of polynomial.
//	4. Implementing the following operation:
//		1. Padd(): The function that adds the two polynomial.
//		2. attach(): The function that practically keeps added result in array.
//		3. readPoly(): The function that reads and stores a value of polynomial (coef, expon).
//		4. printPoly(): The function that prints the value of polynomial (coef, expon).
//		5. COMPARE macro
//			- #define COMPARE(x,y) (((x)>(y)) ? 1 : (((x)==(y))) ? 0 : -1 )

#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y) (((x)>(y)) ? 1 : (((x)==(y))) ? 0 : -1 )
#define MAX_TERMS 100
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
	float coef;
	int expon;
}polynomial;
polynomial terms[MAX_TERMS];

void readPoly(FILE* file, int* avail);
void attach(float coefficient, int exponent, int* avail);
void padd(int starta, int finisha, int startb, int finishb, int* avail);
void printPoly(polynomial* terms, int sumstart, int avail);

int main(int argc, char* argv[]) {
	int starta, finisha, startb, finishb;
	int avail = 0;
	int* startc = &avail;

	// A.txt에서 polynomial값 읽고 terms에 저장
	FILE* inputA = fopen("A.txt", "r");
	starta = 0;
	readPoly(inputA, startc);
	finisha = avail - 1;
	fclose(inputA);

	// B.txt에서 polynomial값 읽고 terms에 저장
	FILE* inputB = fopen("B.txt", "r");
	startb = avail;
	readPoly(inputB, startc);
	finishb = avail - 1;
	fclose(inputB);
	
	int sumstart = avail;
	
	padd(starta, finisha, startb, finishb, &avail);
	printPoly(terms, sumstart, avail);
}

// 파일에서 polynomial 읽고 terms에 저장
void readPoly(FILE* file, int* avail) {
	while (fscanf(file, "%f\t%d", &terms[*avail].coef, &terms[*avail].expon) != EOF) {
		*avail = *avail + 1;
	}
}

// Keeps added result in array.
void attach(float coefficient, int exponent, int* avail) {
	terms[*avail].coef = coefficient;
	terms[*avail].expon = exponent;
	*avail = *avail + 1;
}

// Adds the two polynomial
void padd(int starta, int finisha, int startb, int finishb, int* avail) {
	float coefficient;
	while (starta <= finisha && startb <= finishb) {
		switch (COMPARE(terms[starta].expon, terms[startb].expon)) {
		case -1: // a expon < b expon
			attach(terms[startb].coef, terms[startb].expon, avail);
			startb++;
			break;
		case 0: // equal exponents
			coefficient = terms[starta].coef + terms[startb].coef;
			if (coefficient) { // coefficient가 상쇄되지 않았을 경우
				attach(coefficient, terms[starta].expon, avail);
			}
			starta++, startb++;
			break;
		case 1: // a expon > b expon
			attach(terms[starta].coef, terms[starta].expon, avail);
			starta++;
		}
	}
	for (; starta <= finisha; starta++) {
		attach(terms[starta].coef, terms[starta].expon, avail);
	}
	for (; startb <= finishb; startb++) {
		attach(terms[startb].coef, terms[startb].expon, avail);
	}
}

// Prints the value of polynomial (coef, expon)
void printPoly(polynomial* terms, int sumstart, int avail) {
	for (int i = sumstart; i < avail; i++) {
		if (i < avail - 1) {
			printf("(%.0f, %d)\n", terms[i].coef, terms[i].expon);
		}else{
			printf("(%.0f, %d)", terms[i].coef, terms[i].expon);
		}
	}
}