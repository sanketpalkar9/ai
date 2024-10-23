#include <stdio.h>
#include <stdbool.h>

#define N 4  
#define M 3  

int graph[N][N] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

//  (colors assigned to each node)
void printSolution(int color[]) {
    printf("Solution: \n");
    for (int i = 0; i < N; i++) {
        printf("Node %d -> Color %d\n", i, color[i]);
    }
}

//  to check if the color assignment is valid
bool isSafe(int node, int graph[N][N], int color[], int c) {
    for (int i = 0; i < N; i++) {
        if (graph[node][i] && color[i] == c) {  // Check if adjacent node has the same color
            return false;
        }
    }
    return true;
}

// Recursive function to solve the graph coloring problem
bool graphColoringUtil(int graph[N][N], int m, int color[], int node) {
    // Base case: If all nodes are assigned a color, return true
    if (node == N) {
        return true;
    }

    
    for (int c = 1; c <= m; c++) {
        
        if (isSafe(node, graph, color, c)) {
            color[node] = c;  // Assign the color

            
            if (graphColoringUtil(graph, m, color, node + 1)) {
                return true;
            }

            
            color[node] = 0;
        }
    }

   
    return false;
}


bool graphColoring(int graph[N][N], int m) {
    int color[N];  // Array to store colors assigned to each node
    for (int i = 0; i < N; i++) {
        color[i] = 0;  // Initialize all colors as 0 (no color assigned)
    }

    if (graphColoringUtil(graph, m, color, 0)) {
        printSolution(color);
        return true;
    } else {
        printf("No solution exists.\n");
        return false;
    }
}

int main() {
    int m = M;  // Number of colors

    
    graphColoring(graph, m);

    return 0;
}
