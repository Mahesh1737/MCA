#include <stdio.h>
#include <stdlib.h>
#define max 20

int adj[max][max];
int visited[max];
int r = -1, f = -1, queue[max];
void dfs(int start, int visited[], int n)
{
    int i;
    visited[start] = 1;
    printf("%d ", start + 1);
    for (int i = 0; i < n; i++)
    {
        if (adj[start][i] == 1 && visited[i] == 0)
        {
            dfs(i, visited, n);
        }
    }
}

void bfs(int start, int visited[], int n)
{
    queue[++r] = start;
    visited[start] = 1;
    while (f < r)
    {
        start = queue[++f];
        printf("%d ", start + 1);
        for (int i = 0; i < n; i++)
        {
            if (adj[start][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++r] = i;
            }
        }
    }
}

int main()
{
    int e, i, j, n;

    printf("\nEnter the number of vertices : ");
    scanf("%d", &n);
    printf("\nEnter the number of edges : ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    int u, v;
    printf("\nEnter the edges between the graph: ");
    for (int i = 0; i < e; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u - 1][v - 1] = 1;
        adj[v - 1][u - 1] = 1;
    }

    int ch = 3, start;
    while (1)
    {
        printf("\n1. DFS traversal: \n2.BFS traversal : \n3.Display \n4. exit :");
        printf("\nEnter the choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the starting vertex: ");
            scanf("%d", &start);
            for (i = 0; i < n; i++)
                visited[i] = 0;

            dfs(start - 1, visited, n);
            break;
        case 2:
            printf("Enter the starting vertex: ");
            scanf("%d", &start);
            for (i = 0; i < n; i++)
                visited[i] = 0;
            bfs(start - 1, visited, n);
            break;
        case 3:
            for (i = 0; i < n; i++)
            {
                printf("\n");
                for (j = 0; j < n; j++)
                {
                    printf(" %d ", adj[i][j]);
                }
            }
            break;
        case 4:exit(0);
        }
    }
    return 0;
}
