// Purpose: Implemening failure function and KMP pattern match function
// Requirement:
//  1. Make input data file (file name must be kmp.txt) and get the input by using kmp.txt open/read.
//  2. Understanding the KMP
//  3. Implementing the following functions (described in cousrework book):
//      1. pmatch() function
//      2. fail() function

#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#define max_string_size 1000
#define max_pattern_size 1000

int failure[max_pattern_size];
char string[max_string_size];
char pat[max_pattern_size];

void fail(char* pat);
int pmatch(char* string, char* pat);

int main(int argc, char* argv[]){
    FILE* input = fopen("kmp.txt", "r");

    // file error 처리
    if (input == NULL){
        printf("error\n");
        return 1;
    }

    // file에서 string 가져오기
    fscanf(input, "%s", string);
    // file에서 pattern 가져오기
    fscanf(input, "%s", pat);

    fclose(input);

    // KMP matching
    // print -1 (No match) or Starting position of pat in string
    printf("%d", pmatch(string, pat));

    return 0;
}

// Implementing failure function
void fail(char* pat){
    int i = 1, j = 0;
    failure[0] = 0;
    int pat_size = strlen(pat);

    while (i < pat_size){
        // Prefix == Suffix
        if (pat[j] == pat[i]){
            failure[i] = j + 1;
            i++, j++;
        }
        // Prefix != Suffix && j > 0
        else if ((pat[j] != pat[i]) && (j > 0)){
            j = failure[j - 1];
        }
        else {
            failure[i] = 0;
            i++;
        }
    }
}

// Implementing pmatch function
int pmatch(char* string, char* pat){
    int i = 0, j = 0;
    int string_size = strlen(string);
    int pat_size = strlen(pat);
    
    // make failure function
    fail(pat);

    while (i < string_size){
        if (string[i] == pat[j]){
            // pattern 전체 일치
            if (j == pat_size - 1){
                break;
            }
            else {
                i++;
                j++;
            }
        }
        else if ((string[i] != pat[j]) && (j > 0)){
            j = failure[j - 1];
        }
        else {
            i++;
        }
    }
    // pattern match, return starting point of pat
    // pattern no match, return -1
    return ((j == pat_size - 1) ? (i - j) : -1);
}




