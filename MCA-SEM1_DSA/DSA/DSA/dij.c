#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_NODES 10


void create(int g[MAX_NODES][MAX_NODES], int n) 
{
    int i, j;
    printf("\nEnter the adjacency matrix of the city graph (distance between areas):\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 	
	{
            scanf("%d", &g[i][j]);

    	        if (g[i][j] == 0 && i != j) 
		{
	                g[i][j] = INF;
	        }
        }
    }
}


void display_adj_mat(int g[MAX_NODES][MAX_NODES], int n) 
{
    int i, j;
    printf("\nCity's Adjacency Matrix (Distance between areas):\n");
	for (i = 0; i < n; i++) 
	{
        	for (j = 0; j < n; j++) 
		{
		        if (g[i][j] == INF) 
			{
                		printf("INF ");
            	} 
		else 
		{
	                printf("%d ", g[i][j]);
	        }
        }
        printf("\n");
    }
}


void dijkstra(int g[MAX_NODES][MAX_NODES], int n, int start) 
{
    int dist[MAX_NODES], visited[MAX_NODES];
    int i, j, minDist, nextNode;
    

	for (i = 0; i < n; i++) 
	{
        	dist[i] = INF;
        	visited[i] = 0;
    	}
    	dist[start] = 0;

    	for (i = 0; i < n - 1; i++) 
	{

	        minDist = INF;
	        nextNode = -1;
	        for (j = 0; j < n; j++) 
		{
            		if (!visited[j] && dist[j] < minDist) 
			{
		                minDist = dist[j];
        		        nextNode = j;
        		}
        	}

	        visited[nextNode] = 1;


        	for (j = 0; j < n; j++) 
		{
            		if (!visited[j] && g[nextNode][j] != INF) 
			{
		                int newDist = dist[nextNode] + g[nextNode][j];
		                if (newDist < dist[j]) 
				{
		                    dist[j] = newDist;
		                }
	            	}
        	}
    	}


    	printf("\nShortest distance from Area %c:\n", start + 65);
    	for (i = 0; i < n; i++) 
	{
	        if (dist[i] == INF) 
		{
            		printf("No path to area %c\n", i + 65);
	        } 
		else 
		{
            		printf("To Area %c: %d units\n", i + 65, dist[i]);
        	}
    	}
}


int main() 
{
    int g[MAX_NODES][MAX_NODES], n, choice;

    printf("\nEnter the number of areas in the city: ");
    scanf("%d", &n);

    do {
        printf("\n---------------------MENU--------------------------\n");
        printf("1. Create City Graph (Adjacency Matrix)\n");
        printf("2. Display City Graph (Adjacency Matrix)\n");
        printf("3. Find Shortest Path using Dijkstra's Algorithm\n");
        printf("4. Exit\n");
        printf("---\n\tEnter Choice: ");
        scanf("%d", &choice);
        printf("---------------------------------------------------");

        switch (choice) 
	{
            case 1:
                create(g, n);
                break;
            case 2:
                display_adj_mat(g, n);
                break;
            case 3:
                printf("\nEnter the area representing your home (0 to %d): ", n - 1);
                int home;
                scanf("%d", &home);
                printf("\nEnter the area representing your college (0 to %d): ", n - 1);
                int college;
                scanf("%d", &college);
                dijkstra(g, n, home);
                printf("\nThe shortest path from home (Area %c) to college (Area %c):\n", home + 65, college + 65);
                printf("Shortest Path Distance: %d units\n", g[home][college]);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid Choice\n");
        }
    } while (1);

    return 0;
}

