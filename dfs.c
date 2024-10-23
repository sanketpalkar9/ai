#include <stdio.h>

#define n 7
#define N 100
int stack[N];
int top = -1;

void push(int value)
{
    if (top > N)
    {
        printf("queue if full");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Nothing to pop ");
        return;
    }
    printf("%d ", stack[top]);
    top--;
}

int main(int argc, char const *argv[])
{
    int visited[n] = {0};
    int graph[n][n] = {
        {0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 1, 1},
        {0, 1, 0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 1},
        {0, 1, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1, 1, 0}

    };
    int startVertex = 0;
    int currentVertex = startVertex;

    visited[startVertex] = 1;
    push(currentVertex);

    while (top != -1)
    {
        currentVertex = stack[top];
        pop();

        for (int i = 0; i < n; i++)
        {
            if (graph[currentVertex][i] && !visited[i])
            {
                visited[i] = 1;
                push(i);
            }
        }
    }

    return 0;
}