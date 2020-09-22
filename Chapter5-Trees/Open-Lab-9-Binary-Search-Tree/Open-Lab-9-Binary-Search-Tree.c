// Purpose: Binary Search Tree 구현하기.
// Requirement:
//  1. BST.txt에 저장된 트리 정보를 파일 입출력으로 읽어오기.
//  2. 트리를 Linked-List로 구현하기.
//  3. 트리의 노드는 동적 할당.
//  4. 다음 함수 구현하기:
//      1. InsertBST()
//      2. InorderBST()
//      3. SearchBST()
//  4. 전역 변수 사용 불가.
//  5. 자율적으로 함수의 파라미터 설정 가능.

#include <stdio.h>
#include <stdlib.h>

typedef struct BST* BSTPointer;
typedef struct BST{
    int key;
    char value;
    BSTPointer leftChild;
    BSTPointer rightChild;
}BST;

void InsertBST(BSTPointer *root, int key, char value);
void InorderBST(BSTPointer root);
void SearchBST(BSTPointer root, int key);

int main(){
    int key;
    char value, flag;
    BSTPointer root = NULL;
    
    FILE* fp;
	fp = fopen("BST.txt", "r");
	if (!fp) {
		fprintf(stderr, "Input file doesn't exist\n");
		return(1);
	}
    
    while(!feof(fp)){
        fscanf(fp, "%c", &flag);
        if(flag == 'I'){
            fscanf(fp, "%d %c", &key, &value);
            InsertBST(&root, key,value);
        }
        else if(flag == 'T'){
            InorderBST(root);
        }
        else if(flag == 'S'){
            fscanf(fp,"%d", &key);
            SearchBST(root, key);
        }
    }
    fclose(fp);
    return 0;

}

void InsertBST(BSTPointer* root, int key, char value){
    BSTPointer temp = (BSTPointer)malloc(sizeof(BST));
    temp->key = key;
    temp->value = value;
    temp->leftChild = temp->rightChild = NULL;

    if(*root == NULL){
        *root = temp;
    }
    else{
        BSTPointer ptr = *root;
        while(ptr){
            if(ptr->key == temp->key) break;
            else if(ptr->key < temp->key){
                if(ptr->rightChild == NULL){
                    ptr->rightChild = temp;
                    break;
                }
                ptr = ptr->rightChild;
            }
            else{
                if(ptr->leftChild == NULL){
                    ptr->leftChild = temp;
                    break;
                }
                ptr = ptr->leftChild;
            }
        }
    }
}

void InorderBST(BSTPointer root){
    if(root){
        InorderBST(root->leftChild);
        printf("(%d, %c)\n", root->key, root->value);
        InorderBST(root->rightChild);
    }
}

void SearchBST(BSTPointer root, int key){
    while(root){
        if(key == root->key){
            printf("%c\n", root->value);
            break;
        }
        else if(key < root->key) root = root->leftChild;
        else root = root->rightChild;
    }
}