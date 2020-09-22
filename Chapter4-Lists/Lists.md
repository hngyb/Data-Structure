# 4. Lists
## 4.1 Pointers
- Linked representation
    - A node, associated with an element in the list, contains a __data component__ and a __pointer__ to the next item in the list.
    - The pointers are often called __links__.
- C provides extensive support for pointers
    - Actual value of a pointer type is an __address of memory__.
    - operators
        - &: the address operator
        - *: the dereferencing (or indirection) operator
    - To assign a value to i,
        - i = 10; or *pi = 10;
### 4.1.1 Pointers Can Be Dangerous
- pointer can be dangerous: accessing unexpected memory locations
    - __Set all pointers to NULL when they are not actually pointing to an object__
    - Explicit type casts when converting between pointer types
        - pi = malloc(sizeof(int));
        - pf = (float *)pi; cast an int pointer to a float pointer
        - Define __explicit return types__ for functions
### 4.1.2 Using Dynamically Allocated Storage
- malloc
- free
```c
int i, *pi;
float f, *pf;
pi = (int *)malloc(sizeof(int));
pf = (float *)malloc(sizeof(float));
*pi = 1024;
*pf = 3.14;
printf("an integer = %d, a float = %f\n", *pi, *pf);
free(pi);
free(pf);
```
## Linked Lists
- list elements are stored, in memory, in an __arbitrary order.__
- explicit information (__called a link__) is used to go from one element to the next.
### Chain
- A chain is a linked list in which each node represents __one element.__
- There is a link or pointer from one element to the next.
- The last node has a __NULL (or 0)__ pointer.
### Node Representation
```c
typedef struct listNode *listPointer;
typedef struct{
    char data;
    listpointer link;
}listNode;
```
### Delete An Element
```c
deleteNode = first;
first = first->link;
free(deleteNode);
```
## 4.2 Singly Linked Lists
- If e is a pointer to a structure that contains the field name, __e->name__ is a shorthand way of writing the expression __(*e).name__.
```c
list_pointer create2(){
    /* create a linked list with two nodes */
    list_pointer first, second;
    first = (list_pointer)malloc(sizeof(list_node));
    second = (list_pointer)malloc(sizeof(list_node));
    second->link = NULL;
    second->data = 20;
    first->data = 10;
    first->link = second;
    return first;
}
```
```c
void insert(list_pointer *ptr, list_pointer node){
    /* insert a new node with data = 50 into the list ptr after node */
    list_pointer temp;
    temp = (list_pointer)malloc(sizeof(list_node));

    if(IS_FULL(temp)){
        fprintf(stderr, "The memory is full\n");
        exit(1);
    }
    temp->data = 50;
    if(*ptr){
        temp->link = node->link
        node->link = temp;
    }
    else{
        temp->link = NULL;
        *ptr = temp;
    }
}
```c
void delete(list_pointer *ptr, list_pointer trail, list_pointer node){
    /* delete node from the list, trail is the preceding node, ptr is the head of the list */
    if(trail){
        trail->link = node->link;
    }
    else{
        *ptr = (*ptr)->link;
    }
    free(node);
}
```
```c
void print_list(list_pointer ptr){
    printf("The list contains: ");
    for(; ptr; ptr = ptr->link){
        printf("%4d", ptr->data);
    }
    printf("\n");
}
```
```c
list_pointer search(list_pointer ptr, int num){
    for(; ptr; ptr = ptr->link){
        if(ptr->data == num) return ptr;
    }
    return ptr;
}
```
## 4.3 Dynamically Linked Stacks and Queues
- [Converting-infix-to-postfix 실습](https://github.com/hngyb/CSE/blob/master/Data-Structure/Chapter3-Stacks-and-Queues/Open-Lab5-Coverting-infix-to-postfix/Converting-infix-to-postfix.c "")
## 4.4 Polynomials
### 4.4.1 Representing Polynomials As Singly Linked Lists
```c
typedef struct poly_node *poly_pointer;
typedef struct poly_node{
    float coef;
    int expon;
    poly_pointer link;
};
poly_pointer a,b,d;
```
### 4.4.2 Adding Polynomials
- poly_pointer padd(poly_pointer a, poly_pointer b)
- void attach(float coefficient, int exponent, poly_pointer *ptr)
### 4.4.3 Erasing Polynomials
- 항상 free()를 해줘야 함.
### 4.4.4 Representing Polynomials As Circularly Linked Lists
- To free all the nodes of a polynomial more efficiently, we modify our list structure so that the link field of the last node points to the first node in the list.
- We call this a __circular list__.
- We can obtain an efficient erase algorithm for circular lists, by maintaining our own list (as a chain) of nodes that have been __"freed"__.
- When we need a new node, we examine this list.
    - If the list is not empty, then we may use one of its nodes.
    - Only when the list is empty, use malloc to create a new node.
- Let __avail__ be a variable of type poly_pointer that points to the first node in the list of freed nodes.
## 4.5 Additional List Operations
### 4.5.1 Operations For Chains
- Inverting a chain
- Concatenating two chains
### 4.5.2 Operations For Circularly Linked Lists
- Inserting a new node at the front of a circular list
## 4.6 Equivalence Relations
## 4.7 Sparse Matrix
- [Sparse Matrix Linked List 실습](https://github.com/hngyb/CSE/blob/master/Data-Structure/Chapter4-Lists/Open-Lab-6-Sparse-Matrix-Linked-List/Open-Lab-6-Sparse-Matrix-Linked-List.c "")
## 4.8 Doubly Linked Lists
- Singly linked lists pose problem because we can move easily only in the direction of the links.
- Whenever we have a problem that requires us to move in either direction, it is useful to have doubly linked lists.
- The necessary declarations are:
```c
typedef struct node *node_pointer;
typedef struct node{
    node_pointer llink;
    element item;
    node_pointer rlink;
};
```
- ptr == ptr->llink->rlink == ptr->rlink->llink
- Insertion into a doubly linked circular list:
```c
void dinsert(node_pointer node, node_pointer newnode){
    /* insert newnode to the right of node */
    newnode -> llink = node;
    newnode->rlink = node->rlink
    node->rlink->llink = newnode;
    node->rlink = newnode;
}
```
- Deletion from a doubly linked circular list:
```c
void ddelete(node_pointer node, node_pointer deleted){
    /* delete from the doubly linked list */
    if(node == deleted){
        printf("Deletion of head node not permitted.\n");
    }
    else{
        deleted->llink->rlink = deleted->rlink;
        deleted->rlink->llink = deleted->llink;
        free(deleted);
    }
}