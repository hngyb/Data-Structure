# 6. Graphs
## 6.1 Graphs
- G = (V,E)
- __V__ is the vertex set.
- Vertices are also called nodes and points.
- __E__ is the edge set.
- Each edge connects two different vertices.
- Edges are also called arcs and lines.
- Directed edge has an orientation (u,v).
- Undirected edge has no orientation.
- __Complete Undirected Graph__
    - Has all possible edges.
- Number of Edges in an undirected graph is __n(n-1)/2__.
- Number of Edges in a directed graph is __n(n-1)__.
- __Vertex Degree__: Number of edges incident to vertex.
- Sum of Vertex Degree = __2e__(e is number of edges).
- In-Degree of a Vertex: 방향성이 나에게 돌아오는 edge의 개수.
- Out-Degree of a Vertex: number of outbound edges.
- sum of in-degrees = sum of out-degrees = e
- __Connected Graph__:
    - __Undirected__ graph.
    - There is a path between every pair of vertices.
- __Tree__:
    - Connected graph that has no cycles.
    - n vertex connected graph with n-1 edges.
- __Spanning Tree__:
    - Subgraph that includes all vertices of the original graph.
    - Subgraph is a tree.
        - If original graph has n vertices, the spanning tree has n vertices and n-1 edges.
## 6.2 Graph Representation
### Adjacency Matrix
- n*n matrix, where n = # of vertices.
- A(i,j) = 1 iff (i,j) is an edge.
- Diagonal entries are zero.
- Adjacency matrix of an undirected graph is symmetric.
    - A(i,j) = A(j,i) for all i and j.
- Adjacency matrix of a diagraph need not be symmetric.
- n^2 bits of space.
- For an undirected grpah, may store only lower or upper triangle (exclude diagonal).
    - (n-1)n/2 bits
- O(n) time to find vertex degree and/or vertices adjacent to a given vertex.
### Adjacency Lists
 - Adjacency list for vertex __i__ is a linear list of vertices adjacent from vertex __i__.
 - An array of __n__ adjacency lists.
 - Array로 표현할시 하나의 vertex에 많은 연결이 있으면 표현하기 힘듦.
- __Linked Adjacency Lists__
    - Each adjacency list is a chain.
- __Array Adjacency Lists__
    - Each adjacency list is an array list.
### Weighted Graphs
- Cost adjacency matrix.
    - __C(i,j)__ = cost of edge (i,j)
- Adjacency lists: each list element is a pair __(adjacent vertex, edge weight)__.
## 6.3 Graph Search Methods
- A vertex u is reachable from vertex v iff there is a path from v to u.
- A search method starts at a given vertex v and vists/labels/marks every vertex that is reachable from v.
### Depth-first search
```
void dfs(int v)
{
    /* depth first search of a graph beginning with vertex v.*/
    node_pointer w;
    visited[v] = TRUE;
    printf("%5d", v);
    for (w = graph[v];w;w = w->link){
        if(!visited[w->vertex]) dfs(w->vertex);
    }
}
```
- All vertices reachable from the start vertex (including the start vertex) are visited.
- Terminate when vertex u is visited or when dfs ends.
- O(n^2) when adjacency matrix used.
- O(n+e) when adjacency lists uesd (e is number of edges).
### Breadth-first search
- Visit start vertex and put into a FIFO queue.
- Repeatedly remove a vertex from the queue, visit its unvisited adjacent vertices, put newly visited vertices into the queue.
- Each visited vertex is put on the queue exactly once.
- When a vertex is removed from the queue, we examine its adjacent vertices.
```
void bfs(int v)
{
    /* breadth first traversal of a graph, staring with node v.
    The global array visited is initialized to 0 */

    node_pointer w;
    queue_pointer front, rear;
    front = rear = NULL; /* initialize queue */
    printf("%5d", v);
    visited[v] = TRUE;
    addq(&front, &rear, v);
    while(front){
        v = deleteq(&front);
        for(w = graph[v], w; w = w->link){
            if(!visited[w->vertex]){
                printf("%5d", w->vertex);
                addq(&front, &rear, w->vertex);
                visited[w->vertex] = TRUE;
            }
        }
    }
}
```
## 6.4 Minimum Cost Spanning Trees
### Prim's algorithm
```
T = {}; /* to make sure that the added edge does nt form a cycle */
TV = {0}; /* start with vertex 0 and no edges */
while (T contains fewer than n-1 edges){
    let (u,v) be a least cost edge such that u ∈ TV and v !∈ TV;
    if(there is no such edge) break;
    add v to TV;
    add(u,v) to T;
}
if(T contains fewer than n-1 edges){
    printf("No spanning tree\n");
}
```
### Kruskal's algorithm
- cost가 적은 것부터 연결.
- 연결된 edge로 인해 cycle이 생기면, discard.
```
T = {};
while (T contains less than n-1 edges && E is not empty){
    choose a least cost edge (v,w) from E;
    delete (v,w) from E;
    if((v,w) does not create a cycle in T) add (v,w) to T;
    else discard (v,w);
}
if(T contains fewer than n-1 edges) printf("No spanning tree\n");
```
- Using a min heap or sorting to determine an edge with minimum cost.
- The computing time of Kruskal's algorithm is O(eloge)
### Sollin's algorithm
- The initial configuration of zero selected edges.
- Find minimum cost edge at each vertex.
- Delete duplicate edges.
- The algorithm terminates when there is only one tree at the end of a stage or no edges remain for selection.

## 6.5 Shortest Paths
### Dijkstra Algorithm
- Relaxation:
```
if(d[u]+c(u,v)<d[v]) d[v] = d[u] + c(u,v)
```
- Time complexity is O(|V|^2) or O(n^2)
- Dijkstra's algorithm may not work for graps with negative weights.
### Bellman-Ford algorithm
### All Pairs Shortest Paths
- Cost adjacency matrix