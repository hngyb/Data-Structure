// Purpose: Implementing Insertion Sort algorithm for integer array.
// Requirement:
//	1. Use dynamic memory allocation 
//	2. Make input data file and get the input by using file open/read.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char* argv[]) {
	// input 파일에 난수 출력
	FILE* input = fopen("input.txt", "w+");
	int cnt;
	printf("생성할 난수의 개수를 입력하세요: ");
	scanf("%d", &cnt);

	for (int i = 0; i < cnt;i++) {
		int temp = rand();
		fprintf(input,"%d",temp);
		if(i < cnt - 1) {
			fprintf(input, "\n");
		}
	}
	rewind(input);

	// input 파일의 unsorted 난수들 array에 할당
	int* array = (int*)(malloc(sizeof(int) * cnt));
	for (int i = 0; i < cnt; i++) {
		fscanf(input, "%d", &array[i]);
	}
	fclose(input);

	// Insertion Sort
	clock_t start, stop;
	start = clock();
	// array[0]은 sorted 가정, i = 1부터 시작
	for (int i = 1; i < cnt; i++) {
		int t = array[i];
		int j;
		for (j = i - 1; j >= 0 && t < array[j]; j--) {
			array[j + 1] = array[j];
		}
		array[j + 1] = t;
	}
	stop = clock();
	
	// Elapsed time 계산
	double duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
	// output 파일 생성
	FILE* output = fopen("output.txt", "w");
	if (output == NULL) {
		printf("error\n");
		return 1;
	}
	// sorted array 출력
	for (int i = 0; i < cnt; i++) {
		fprintf(output, "%d ", array[i]);
	}
	fprintf(output, "\n");
	// Elapsed time 출력
	fprintf(output, "Elapsed time(sec): %.3f sec", duration);
	fclose(output);

	return 0;
}

// rewind 함수 사용할 때 파일모드 주의!
