// Purpose: Linked list로 Tree 구현 및 트리 순회 구현
// Requirement:
//  1. Tree.txt에 저장된 트리 정보를 파일 입출력으로 읽어오기.
//  2. Tree는 complete-binary tree fashion으로 만들기.
//  3. 다음 순회 출력 함수 구현하기:
//      1. Inorder()
//      2. Preorder()
//      3. Postorder()
//      4. Iterative Inorder()
//      5. Levelorder()
//  4. 전역 변수 사용 불가.
//  5. 자율적으로 함수의 파라미터 설정 가능.

#include<stdio.h>
#include<stdlib.h>
#define MAX_NODE_SIZE 50
#define MAX_TREE_SIZE 50

typedef struct node* tree_pointer;
typedef struct node{
    char data;
    tree_pointer left_child, right_child;
};

void create_node(tree_pointer* tree, char root);
tree_pointer link_tree(tree_pointer* tree, tree_pointer* left_tree, tree_pointer* right_tree);
void Inorder(tree_pointer tree);
void Preorder(tree_pointer tree);
void Postorder(tree_pointer tree);
void Iterative_Inorder(tree_pointer tree, int node_size);
void Levelorder(tree_pointer tree, int node_size);
void push(tree_pointer tree, int* top, tree_pointer* stack);
tree_pointer pop(int *top, tree_pointer* stack);
void addq(tree_pointer tree, int* front, int* rear, tree_pointer* queue);
tree_pointer deleteq(int* front, int* rear, tree_pointer* queue);

int main(){
    int node_size;
    int i;
    char root[MAX_NODE_SIZE];
    tree_pointer tree[MAX_TREE_SIZE] = { NULL };

    FILE* fp;
    fp = fopen("tree.txt", "r");
    if (!fp){
        fprintf(stderr, "Input file doesn't exist\n");
        exit(1);
    }

    fscanf(fp, "%d\n", &node_size);
    for (i = 0; i < node_size; i++){
        fscanf(fp, "%c\n", &root[i]);
        create_node(&tree[i], root[i]);
    }
    fclose(fp);

    i = 0;
    while(2*i + 1 < node_size){
        link_tree(&tree[i], &tree[2*i + 1], &tree[2*i + 2]);
        i++;
    }

    printf("Inorder: "); Inorder(tree[0]);
    printf("\n");
    printf("Preorder: "); Preorder(tree[0]);
    printf("\n");
    printf("Postorder: "); Postorder(tree[0]);
    printf("\n");
    printf("Iterative Inorder: "); Iterative_Inorder(tree[0], node_size);
    printf("\n");
    printf("Level order: "); Levelorder(tree[0], node_size);
    
    return 0;
}

void create_node(tree_pointer* tree, char root){
    *tree = (tree_pointer)malloc(sizeof(struct node));
    tree_pointer temp = *tree;
    temp->data = root;
    temp->left_child = NULL;
    temp->right_child = NULL;
}

tree_pointer link_tree(tree_pointer* tree, tree_pointer* left_tree, tree_pointer* right_tree){
    tree_pointer temp = *tree;
    temp -> left_child = (*left_tree);
    if (right_tree != NULL){
        temp->right_child = (*right_tree);
    }
    return temp;
}

void Inorder(tree_pointer tree){
    if(tree){
        Inorder(tree->left_child);
        printf("%c", tree->data);
        Inorder(tree->right_child);
    }
}

void Preorder(tree_pointer tree){
    if(tree){
        printf("%c", tree->data);
        Preorder(tree->left_child);
        Preorder(tree->right_child);
    }
}

void Postorder(tree_pointer tree){
    if(tree){
        Postorder(tree->left_child);
        Postorder(tree->right_child);
        printf("%c", tree->data);
    }
}

void Iterative_Inorder(tree_pointer tree, int node_size){
    int top = -1;
    tree_pointer stack[MAX_NODE_SIZE];
    for (int i = 0; i < node_size; i++){
        for (; tree; tree = tree->left_child){
            push(tree, &top, stack);
        }
        tree = pop(&top, stack);
        if (!tree) break;
        printf("%c", tree->data);
        tree = tree->right_child; 
    }
}

void push(tree_pointer tree, int* top, tree_pointer* stack){
    if(*top < MAX_NODE_SIZE - 1){
        (*top)++;
        stack[*top] = tree;
    }
}

tree_pointer pop(int* top, tree_pointer* stack){
    if(*top >= 0){
        return stack[(*top)--];
    }
}

void Levelorder(tree_pointer tree, int node_size){
    int front = 0, rear = 0;
    tree_pointer queue[MAX_NODE_SIZE];
    if (!tree) return;
    addq(tree, &front, &rear, queue);
    for (int i = 0; i < node_size; i++){
        tree = deleteq(&front, &rear, queue);
        if (tree){
            printf("%c", tree->data);
            if (tree->left_child){
                addq(tree->left_child, &front, &rear, queue);
            }
            if (tree->right_child){
                addq(tree->right_child, &front, &rear, queue);
            }
        }
        else break;
    }
}

void addq(tree_pointer tree, int* front, int* rear, tree_pointer* queue) {
	(*rear)++;
	queue[*rear] = tree;
}

tree_pointer deleteq(int* front, int* rear, tree_pointer* queue) {
	(*front)++;
	return queue[*front];
}
