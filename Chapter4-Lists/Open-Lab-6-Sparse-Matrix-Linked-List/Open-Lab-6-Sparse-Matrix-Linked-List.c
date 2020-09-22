// Purpose: Linked List로 Sparse Matrix 구현하기.
// Requirement:
//  1. Circular linked list로 구현.
//  2. 두 File(A.txt와 B.txt)에 저장된 Sparse matrix를 파일 입출력으로 읽어오기.
//  3. 다음 함수 구현하기:
//      1. mread(): 행렬을 읽어 Linked list 형태로 구성하는 함수.
//      2. mwrite(): 행렬을 row-major 방식으로 출력하는 함수.
//      3. merase(): 행렬을 삭제하고 노드에 쓰인 메모리를 반환하는 함수.
//  4. 전역 변수 사용 불가.

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

typedef enum { head, entry } tagfield;
typedef struct matrix_node* matrix_pointer;
typedef struct entry_node{
    int row;
    int col;
    int value;
} entry_node;
typedef struct matrix_node{
    matrix_pointer down;
    matrix_pointer right;
    tagfield tag;
    union{
        matrix_pointer next;
        struct entry_node entry;
    } u;
} matrix_node;

/* Global Variables */
matrix_pointer hdnode[MAX_SIZE];

/* Functions to be implemented by student */
matrix_pointer mread(FILE* fp);
void mwrite(matrix_pointer node);
void merase(matrix_pointer* node);

int main() {
    matrix_pointer a, b;
    FILE* fp_A, * fp_B;

    fp_A = fopen("A.txt", "r");
    fp_B = fopen("B.txt", "r");
    a = mread(fp_A);
    b = mread(fp_B);
    mwrite(a);
    mwrite(b);
    merase(&a);
    merase(&b);
    mwrite(a);
    mwrite(b);

    fclose(fp_A);
    fclose(fp_B);

    return 0;
}

matrix_pointer new_node() {
	matrix_pointer node = (matrix_pointer)malloc(sizeof(matrix_node));
	if (!node) {
		fprintf(stderr, "There is no available memory for allocation.\n");
		fprintf(stderr, "Program will be shutdown.\n");
		exit(0);
	}
	return node;
}
matrix_pointer mread(FILE* fp){
    int num_rows, num_cols, num_terms, num_heads, i;
    int row = 0, col = -1, value, current_row;
    matrix_pointer temp, last, node;

    fscanf(fp, "%d %d", &num_rows, &num_cols);
    // head node의 개수는 max{행의 수, 열의 수}만큼만 생성
    num_heads = (num_cols > num_rows) ? num_cols : num_rows;
    num_terms = num_cols * num_rows;
    node = new_node();
    node->tag = entry;
    node->u.entry.row = num_rows;
    node->u.entry.col = num_cols;

    if(!num_heads) node->right = node;
    else{
        // head node 생성
        for(i = 0; i < num_heads; i++){
            temp = new_node();
            hdnode[i] = temp;
            hdnode[i]->tag = head;
            hdnode[i]->right = temp;
            hdnode[i]->u.next = temp;
        }
        current_row = 0;
        last = hdnode[0];
    
    for (i = 0; i < num_terms; i++){
        fscanf(fp, "%d", &value);
        col++;
        if(col == num_cols){
            col = 0;
            row++;
        }
        if(row > current_row){
            last->right = hdnode[current_row];
            current_row = row;
            last = hdnode[row];
        }
        if(value == 0) continue;
        temp = new_node();
        temp->tag = entry;
        temp->u.entry.row = row;
        temp->u.entry.col = col;
        temp->u.entry.value = value;
        last->right = temp;
        last = temp;
        hdnode[col]->u.next->down = temp;
        hdnode[col]->u.next = temp;
    }
    last->right = hdnode[current_row];
    for (i = 0; i < num_cols; i++){
        hdnode[i]->u.next->down = hdnode[i];
    }
    for (i = 0;i < num_heads - 1;i++) {
		hdnode[i]->u.next = hdnode[i + 1];
	}
	hdnode[num_heads - 1]->u.next = node;
	node->right = hdnode[0];
    }
    return node;
}
void mwrite(matrix_pointer node){
    int i, j;
    matrix_pointer temp, head = node->right;
    
    for(i = 0; i < node->u.entry.row; i++){
        temp = head->right;
        for(j = 0; j < node->u.entry.col; j++){
            if (j != temp->u.entry.col){
                printf("0 "); continue;
            }
            printf("%d ", temp->u.entry.value);
            temp = temp->right;
        }
        printf("\n");
        head = head->u.next;
    }
    printf("\n");
}
void merase(matrix_pointer* node){
    int i;
    matrix_pointer x, y, head = (*node)->right;
    
    for (i = 0; i < (*node)->u.entry.row; i++){
        y = head->right;
        while (y != head){
            x = y;
            y = y->right;
            free(x);
        }
        x = head;
        head = head->u.next;
        free(x);
    }
    y = head;
    while(y != *node){
        x = y;
        y = y->u.next;
        free(x);
    }
    free(*node);
    *node = NULL;
}