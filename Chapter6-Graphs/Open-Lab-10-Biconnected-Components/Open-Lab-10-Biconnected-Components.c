#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 30
#define MIN2(x,y) ((x)<(y)?(x):(y))
#define FALSE 0
#define TRUE 1
short int visited[MAX_VERTICES];
short int dfn[MAX_VERTICES];
short int low[MAX_VERTICES];
int n = 0;
int num=0;
int top = -1;
int stack[MAX_VERTICES][2];

typedef struct node* node_pointer;
typedef struct node {
	int vertex;
	node_pointer link;
}node;
node_pointer graph[MAX_VERTICES];

void init(int);
void bicon(int, int);
void push(int, int);
void pop(int*, int*);

void main() {
	FILE* fp;
	fp = fopen("input.txt", "r");
	fscanf(fp, "%d\n", &n);
	char str[10];int i, j;int node;
		for (i = 0;i < n;i++) {
			fscanf(fp, "%d", &node);
			node_pointer tmp = malloc(sizeof(node));
			graph[i] = tmp;
			graph[i]->vertex= node;
			graph[i]->link = NULL;
			fgets(str,10, fp);
			for (j = 1;j < 10;j++) {
				if (str[j] != ' ' && str[j] != '\n' && str[j]!='\0') {
					node_pointer tmp2 = malloc(sizeof(node));
					int value = str[j] - '0';
					tmp2->vertex = value;
					tmp2->link = NULL;
					node_pointer ptr = graph[i];
					while (ptr->link != NULL) {
						ptr = ptr->link;
					}
					ptr->link = tmp2;
				}
				else if (str[j] == '\0') break;
				}
			}
	fclose(fp);

	init(n);
	bicon(3, -1);
}

void init(int n) {
	int i;
	for (i = 0;i < n;i++) {
		visited[i] = FALSE;
		dfn[i] = low[i] - 1;
	}
	num = 0;
}

void bicon(int u, int v) {
	node_pointer ptr;
	int w, x, y;
	dfn[u] = low[u] = num++;
	for (ptr = graph[u];ptr;ptr = ptr->link) {
		w = ptr->vertex;
		if (v != w && dfn[w] < dfn[u]) {
			push(u, w);
		}
		if (dfn[w] < 0) {
			bicon(w, u);
			low[u] = MIN2(low[u], low[w]);
			if (low[w] >= dfn[u]) {
				printf("New biconnected component: ");
				do {
					pop(&x, &y);
					printf(" <%d, %d>", x, y);
				} while (!((x == u) && (y == w)));
				printf("\n");
			}
		}
		else if (w != v) low[u] = MIN2(low[u], dfn[w]);
	}
}
void push(int x, int y) {
	stack[++top][0] = x;
	stack[top][1] = y;
}

void pop(int* x, int* y) {
	*x = stack[top][0];
	*y = stack[top--][1];
}
