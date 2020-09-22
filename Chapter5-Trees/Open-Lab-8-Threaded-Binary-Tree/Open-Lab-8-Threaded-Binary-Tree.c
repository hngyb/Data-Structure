// Purpose: Threaded Binary Tree 구현하기.
// Requirement:
//  1. Tree.txt에 저장된 트리 정보를 파일 입출력으로 읽어오기.
//  2. 다음 함수 구현하기:
//      1. Insertion()
//      2. InsertRight(), InsertLeft()
//      3. Traversal()
//      4. insucc()
//  4. 전역 변수 사용 불가.
//  5. 자율적으로 함수의 파라미터 설정 가능.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct threadedTree * threadedPointer;
typedef struct threadedTree {
    short int leftThread;
    threadedPointer leftChild;
    char data;
    threadedPointer rightChild;
    short int rightThread;
} threadedTree;

threadedPointer search(threadedPointer root, int searchnum);
void Traversal(threadedPointer root);
void InsertRight(threadedPointer parent, threadedPointer child);
void InsertLeft(threadedPointer parent, threadedPointer child);
threadedPointer insucc(threadedPointer root);

int main() {
    char flag;
    int parentdata, childdata;
    threadedPointer temp, parent, child;
    threadedPointer root = (threadedPointer)malloc(sizeof(threadedTree));
    root->data = 0;
    root->rightThread = true;
    root->leftThread = true;

    FILE* fp;
    fp = fopen("Tree.txt", "r");
    if(!fp){
        fprintf(stderr, "Input file doesn't exist\n");
        return(1);
    }

    while(1){
        fscanf(fp, "%c", &flag);
        if(flag == 'E') break;
        fscanf(fp, "%d", &parentdata);
        fscanf(fp, "%d\n",&childdata);
        
        switch(flag){
        case 'S':
            parent = root;
            child = (threadedPointer)malloc(sizeof(threadedTree));
            child->data = childdata;
            InsertRight(parent, child);
            break;
        case 'L':
            parent = search(root, parentdata);
            child = (threadedPointer)malloc(sizeof(threadedTree));
            child->data = childdata;
            InsertLeft(parent, child);
            break;
        case 'R':
            parent = search(root, parentdata);
            child = (threadedPointer)malloc(sizeof(threadedTree));
            child->data = childdata;
            InsertRight(parent, child);
        }
    }
    fclose(fp);
    child->rightChild = root;
    Traversal(root);

    return 0;
}

threadedPointer search(threadedPointer tree, int searchnum){
    while(searchnum != tree->data){
        tree = insucc(tree);
    }
    return tree;
}

threadedPointer insucc(threadedPointer tree){
    threadedPointer temp;
    // rightThread가 1일 때, rightChild가 successor
    temp = tree->rightChild;
    // rightThread가 0일 때
    if (!tree->rightThread){
        while(!temp->leftThread){
            temp = temp->leftChild;
        }
    }
    return temp;
}

void InsertLeft(threadedPointer parent, threadedPointer child){
    threadedPointer temp;
    child->leftChild = parent->leftChild;
    child->leftThread = parent->leftThread;
    child->rightChild = parent;
    child->rightThread = true;
    parent->leftChild = child;
    parent->leftThread = false;
    if(!child->leftThread){
        temp = insucc(child);
        temp->rightChild = child;
    }
}

void InsertRight(threadedPointer parent, threadedPointer child)
{
	threadedPointer temp;
	child->rightChild = parent->rightChild;
	child->rightThread = parent->rightThread;
	child->leftChild = parent;
	child->leftThread = true;
	parent->rightChild = child;
	parent->rightThread = false;
	if (!child->rightThread) {
		temp = insucc(child);
		temp->leftChild = child;
	}
}

void Traversal(threadedPointer tree){
    threadedPointer temp = tree;
    while(1){
        temp = insucc(temp);
        if (temp == tree) break;
        printf("%d\n", temp->data);
    }
}