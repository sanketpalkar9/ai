#include <stdio.h>

#define n 7
#define N 100
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if (rear == N - 1)
    {
        printf("increase the size of the queue used ");
        return;
    }
    if (rear == -1 && front == -1)
    {
        rear = front = 0;
        queue[rear] = value;
    }
    else
    {
        rear++;
        queue[rear] = value;
    }
}

void dequeue()
{
    if (rear == -1 && front == -1)
    {
        printf("Nothing to print");
    }
    else if (front == rear)
    {
        printf("%d ", queue[rear]);
        rear = front = -1;
    }
    else
    {
        printf("%d ", queue[front]);
        front++;
    }
}

int main(int argc, char const *argv[])
{
    int visited[n] = {0};
    int graph[n][n] = {
        {0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 1, 1},
        {0, 1, 0, 1, 1, 1, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 1},
        {0, 1, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0}};
    int startVertex = 0;
    int currentVertex = startVertex;

    visited[startVertex] = 1;
    enqueue(currentVertex);

    while (front != -1)
    {
        currentVertex = queue[front];
        for (int i = 0; i < n; i++)
        {
            if (graph[currentVertex][i] && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
        dequeue();
    }

    return 0;
}