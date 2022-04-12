// Adjacency Matrix representation in C

#include <stdio.h>
#define V 8

// Initialize the matrix to zero
void init(int arr[][V]) {
  int i, j;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      arr[i][j] = 0;
}

// Add edges
void addEdge(int arr[][V], int i, int j) {
  arr[i][j] = 1;
  arr[j][i] = 1;
}

// Print the matrix
void printAdjMatrix(int arr[][V]) {
  int i, j;

  for (i = 0; i < V; i++) {
    printf("%d: ", i);
    for (j = 0; j < V; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int adjMatrix[V][V];

  init(adjMatrix);

  addEdge(adjMatrix, 1, 2);
  addEdge(adjMatrix, 1, 4);
  addEdge(adjMatrix, 1, 3);

  addEdge(adjMatrix, 2, 4);
  addEdge(adjMatrix, 2, 5);

  addEdge(adjMatrix, 3, 6);

  addEdge(adjMatrix, 4, 3);
  addEdge(adjMatrix, 4, 6);
  addEdge(adjMatrix, 4, 7);

  addEdge(adjMatrix, 5, 4);
  addEdge(adjMatrix, 5, 7);

  addEdge(adjMatrix, 7, 6);



  printAdjMatrix(adjMatrix);

  return 0;
}