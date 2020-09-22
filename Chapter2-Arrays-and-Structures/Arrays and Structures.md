# 2. Arrays and Structures
## 2.1. Array
### 2.1.1 Array 추상 데이터 타입
- __Objects__:
  - index의 각 값에 대하여 집합 item에 속한 한 값이 존재하는 __<index, values>__ 쌍의 집합.
  - index는 1차원 또는 다차원의 유한 순서 집합.
  - 예를 들면, 1차원의 경우 {0, ... , n-1}과 2차원 배열 {(0,0), (0,1), (0,2), (1,0), (1,1), (1,2), (2,0), (2,1), (2,2)}
### 2.1.2 Arrays in C
- Declaration of one-dimensional arrays in C: int list[5]. *plist[5];
- Memory allocation of arrays:
  - list[0]: base address = a
  - list[1]: a + sizeof(int)
  - list[2]: a + 2*sizeof(int)
 - __C interprets list[i] as a pointer to an integer__.
  - (list2 + i) equals &list2[i]
  - *(list2 + i) equals list2[i]
## 2.2. Dynamically Allocated ARRAYS (동적으로 할당된 배열)
### 2.2.1 1차원 배열
- If the user wishes to change array size, we have to change the definition of MAX_SIZE and recompile the program.
- A good solution to this problem is __to defer this decision to run time and allocate the array when we have a good estimate of the required array size.__
  ```c
  int i, n, *list;
  printf("Enter the number of numbers to generate: ");
  scanf("%d", &n);
  if (n < 1){
    fprintf(stderr, "Improper value of n\n");
    exit(EXIT_FAILURE);
  }
  MALLOC(list, n * sizeof(int));
  ```
### 2.2.2 2차원 배열
- 2차원 배열을 동적으로 생성
  ```c
  int** make2dArray(int row, int cols)
  {
    int **x, i;
    /* get memory for row pointers */
    MALLOC(x, rows * sizeof(*x));;
    
    /* get memory for each row */
    for(i = 0; i < rows; i++){
      MALLOC(x[i], cols * sizeof(**x));
    }
    return x;
  }
  ```
  - cf. x = (int**)(malloc(rows*sizeof(*x));
- realloc 하면 list의 주소 값 변경됨.
## 2.3 Structures and Unions (구조와 유니언)
### 2.3.1 Structures
- 배열은 같은 타입의 데이터의 모임. 타입이 다른 데이터를 그룹화하는 방법을 구조(structure)라 하고 __struct__ 라 표기함.
- 각 항목은 타입과 이름으로 식별됨.
- e.g.
  ```c
  struct{
    /* 총 10 + 4 + 4 = 18 bytes
    char name[10];
    int age;
    float salary;
    }person;
    ```
 - The structure member operator '.' is used to select a particular member of the structure.
 - __typedef__ 명령문을 사용하여 구조 데이터 타입을 생성.
### 2.3.2 Unions
- __union__ 의 선언은 구조와 유사하지만, union의 필드들은 그들의 메모리 공간을 공용해야 함.
- 이는 union의 한 필드 만 어느 한 시점에서 활성화되어 사용 가능하다는 것을 의미함.
### 2.3.3 자기 참조 구조 (self-referential structure)
- 자기 참조 구조는 명시적으로 메모리를 할당받고 반납하기 위해, 통상적으로 동적 저장 공간 관리 루틴 (malloc과 free)을 필요로 함.
- e.g.
  ```c
  typedef struct{
    char data; // 1byte
    struct list *link; // 4bytes
    }list;
  ```
- link는 list 구조에 대한 포인터 
## 2.4 Polynomials (다항식)
### 2.4.1 ADT Polynomial
- __objects__:
  - <ei, ai>의 순서쌍으로 된 집합.
  - ai는 Coefficient, ei는 Exponent
  - ei는 0 또는 0 보다 큰 정수
### 2.4.2 다항식 표현
```c
#define MAX_DEGREE 101 /* 다항식의 최대 차수 + 1 */
typedef struct{
  int degree;
  float coef[MAX_DEGREE];
}polynomial;
```
- [다항식 실습](https://github.com/hngyb/CSE/blob/master/Data-Structure/Chapter2-Arrays-and-Structures/Open-Lab2-Polynomial/Polynomial.c "")
## 2.5 The Sparse Matrix (희소행렬)
### 2.5.1 ADT 
- A sparse matrix is a matrix which contains many zero entries.
### 2.5.2 희소행렬의 표현
```c
#define MAX_TERMS 101
typedef struct{
  int col;
  int row;
  int value;
} term;
term a[MAX_TERMS];
```
### 2.5.3 Transposing A Matrix
### 2.5.4 Matrix Multiplication
## 2.6 Representation of MultiDimensional Arrays
## 2.7 Strings
### 2.7.1 ADT
- __objects__:
  - 0개 이상의 문자들의 유한 집합
### 2.7.2 Strings in C
- In C, we represent strings as character arrays terminated with the __null character__.
### 2.7.3 Pattern Matching
-  Brute-Force Pattern Matching
- nfind() Pattern Matching
- [KMP 실습](https://github.com/hngyb/CSE/blob/master/Data-Structure/Chapter2-Arrays-and-Structures/Open-Lab3-KMP-String-Pattern-Matching/KMP-String-Pattern-Matching.c "")

