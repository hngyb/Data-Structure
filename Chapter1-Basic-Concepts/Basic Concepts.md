# Basic Concepts
## Sorting
- In computer science, arranging in an ordered sequence is called __"sorting"__.
### Sort Methods
- Insertion Sort, Bubble Sort, Selection Sort, Merge Sort, Quick Sort, Heap Sort, ...
### Insertion Sort
- Insertion Sort is a sorting technique that scans the sorted list, starting at the beginning, for the correct insertion location for each of the data items from the unsorted list.
```c
for (i = 1; i < n; i+){
  int t = a[i];
  int j;
  for (j = i - 1; j >= 0 && t < a[j]; j--){
    a[j + 1] = a[j];
  }
  a[j + 1] = t;
}
```
### Selection Sort
```c
for (i = 0; i < n; i++){
  Examine list[i] to list[n - 1]
  and suppose that the smallest integer is at list[min];
  Interchnage list[i] and list[min];
}
```
## Performance Analysis
- Estimates of __time__ and __space__ that are machine independent.
- The __space complexity__ of a program is the amount of memory that it needs to run to completion.
- The __time complexity__ of a program is the amount of computer time that it needs to run to completion.
### Space Complexity
- __Fixed space__ requirements (고정공간): 프로그램 입출력의 횟수나 크기와 관계없는 공간 요구를 의미. E.g. 명령어 공간, 단순 변수, 고정 크기의 구조화 변수, 상수들을 위한 공간
- __Variable space__ requirements (가변공간): 특정 인스턴스 I에 의존하는 크기를 가진 구조화 변수들을 위해 필요로 하는 공간들로 구성.
- __S(P) = c + Sp(I)__
- Example1: adding a list of numbers iteratively
  ```c
  float sum(float list[], int n){
    float tempsum = 0;
    int i;
    for (i = 0; i < n; i++){
     tempsum += list[i];
    }
    return tempsum;
  }
  ```
  - Ssum(n) = n if parameters are __passed by value__.
  - Ssum(n) = 0 if parameters are __passed by reference__.
- Example2: adding a list of numbers recursively
  ```c
  float rsum(float list[], int n){
    if (n) return rsum(list, n-1) + list[n-1];
    return 0;
  }
  ```
  - Srsum(n) = __12__*n (parameter(array pointer): 4bytes, parameter(integer): 4bytes, return address: 4bytes)
### Time Complexity
- Compile Time
- __Execution (Running) Time__
  - the times needed to perform each operation
  - the number of each operation performed for the given instance (dependent on the compiler)
  - A __program step__ is a syntactically or semantically meaningful program segment whose execution time is independent of the instance characteristics.
- __Time complexity__ of a program is given by the __number of steps__ taken by the program to compute the function it was written for.
### Asymptotic Notation (점근 표기법)
![time complexity-1](https://user-images.githubusercontent.com/68726615/88618506-448da880-d0d4-11ea-8bd2-a337faad0e65.jpg "")
![time complexity-2](https://user-images.githubusercontent.com/68726615/88618507-448da880-d0d4-11ea-97c4-f5124456e632.jpg "")
![time complexity-3](https://user-images.githubusercontent.com/68726615/88618508-45263f00-d0d4-11ea-9a3f-eedae52dccd9.jpg "")
![time complexity-4](https://user-images.githubusercontent.com/68726615/88618509-45bed580-d0d4-11ea-9e41-cd00917b4321.jpg "")
![time complexity-5](https://user-images.githubusercontent.com/68726615/88618511-45bed580-d0d4-11ea-80d7-99c1e11ecfc6.jpg "")
![time complexity-6](https://user-images.githubusercontent.com/68726615/88618501-435c7b80-d0d4-11ea-9f15-ebcad804ee19.jpg "")
