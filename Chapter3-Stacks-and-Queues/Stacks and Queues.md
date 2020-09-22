# 3. Stacks and Queues
## 3.1 Stacks
- Linear list.
- One end is called __top__.
- Other end is called __bottom__.
- Additions to and removals from the __top__ end only.
- A stack is a __LIFO__ list.
- The stacks and queues are special cases of the more general data type, __ordered list__.
- A stack is an ordered list in which insertions and deletions are mad at one end called the __top__.
### Implementation of Stack
```c
// Stack CreateS(maxStackSize) ::=
#define MAX_STACK_SIZE 100
typedef struct{
    int key;
}element;
element stack[MAX_STACK_SIZE];
int top = -1;

// Boolean IsEmpty(stack) ::= top < 0;
// Boolean IsFull(stack) ::= top >= MAX_STACK_SIZE - 1;

// Add to a stack
void push(element item){
/* add an item to the global stack */
    if(top >= MAX_STACK_SIZE - 1){
        stackFull();
    }
    stack[++top] = item;
}

// Delete from a stack
element pop(){
/* return the top element from the stack */
    if(top == -1){
        return stackEmpty();
    }
    return stack[top--];
}
```
## 3.2 Programming Maze Problem
- [Maze 실습](https://github.com/hngyb/CSE/blob/master/Data-Structure/Chapter3-Stacks-and-Queues/Open-Lab4-Maze/Maze.c "")
## 3.3 Queue
- Linear list.
- One end is called __front__.
- Other end is called __rear__.
- Additions are done at the __rear__ only.
- Removals are made from the __front__ only.
### Queue in an Array
- Use a 1D array to represent a queue.
- Suppose queue elements are stored with the front element in queue[0], the next in queue[1], and so on.
- DeleteQ() --> delete queue[0]
    - O(queue size) time
- AddQ(x) --> if there is capacity, add at right end
    - O(1) time
### Queue in a Circular Array
- to perform each operation in __O(1)__, we use a circular representation.
- Use integer variables __front__ and __rear__.
    - __front__ is one position counterclockwise from first element.
    - __rear__ gives position of last element.
- Add an Element
    - Move __rear__ one clockwise.
    - Then put into __queue[rear]__.
- Delete An Element
    - Move __front__ one clockwise.
    - Then extract from __queue[front]__.
- We cannot distinguish between a full queue and an empty queue!
    - Remedies
        - Don't let the queue get full
        - Define a boolean variable __lastOperationIsAddQ__.
        - Define an integer variable __size__.
        - Performance is slightly better when first strategy is used.
### Implementation of Queue
```c
// Queue CreateQ(maxQueueSize) ::=
#define MAX_QUEUE_SIZE 100
typedef struct{
    int key;
}element;
element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

// Boolean IsEmptyQ(queue) ::= front == rear;
// Boolean IsFullQ(queue) ::= rear == MAX_QUEUE_SIZE - 1;

// Add to a queue
void addq(element item){
/* add an item to the queue */
    if(rear == MAX_QUEUE_SIZE - 1){
        queueFull();
    }
    queue[++rear] = item;
}

// Delete from a queue
element deleteq(){
/* remove element at the front of the queue */
    if(front == rear){
        return queueEmpty();
    }
    return queue[++front];
}
```
- Using the modulus operator:
    - rear = (rear + 1) % MAX_QUEUE_SIZE;
    - front = (front + 1) % MAX_QUEUE_SIZE;
## 3.4 Evaluation of Expressions
- [Converting infix to postfix 실습](https://github.com/hngyb/CSE/blob/master/Data-Structure/Chapter3-Stacks-and-Queues/Open-Lab5-Coverting-infix-to-postfix/Converting-infix-to-postfix.c "")
