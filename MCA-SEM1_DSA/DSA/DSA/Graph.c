#include<stdio.h>
#include<stdlib.h>

void create(int g[10][10],int n)
{
	int i,j;
	printf("\n Enter the adjacency matrix of the graph : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
}

void display_adj_mat(int g[][10],int n)
{
	int i,j;

	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf(" %d ",g[i][j]);
		}
	}
}

void display_adj_list(int g[][10],int n)
{
	int i,j;

	for(i=0;i<n;i++)
	{
		printf("\n %c",i+65);

		for(j=0;j<n;j++)
		{
			if(g[i][j]==1)
			{
				printf("->%c",j+65);
			}
		}

		printf("->NULL");
	}
}



int visited[10]={0}, queue[10], front = -1, rear = -1;

void bfs(int g[][10],int n,int v)
{
	int i;
	
    	for(i=0;i<n;i++)
    	{
	    	if (g[v][i] && !visited[i])
        	{      	
			queue[++rear] = i;
		}
	}
	
	if (front<=rear)
	{
		visited[queue[front]] = 1;
		bfs(g,n,queue[front++]);
	}
}

void dfs(int g[][10],int n,int v) 
{
    int i;
    visited[v] = 1;
    printf("\t%d",v);
    
    for (i=0;i<n;i++)
    {
	if (g[v][i] && !visited[i]) 
	{
            dfs(g,n,i);
        }
    }
}

int main()
{
	int g[10][10],n,ch,i;

	do
	{
		printf("\n---------------------MENU--------------------------\n 1. Create Adj. Matrix");
		printf("\n 2. Display Adj. Matrix");
		printf("\n 3. Display Adj. List");
		printf("\n 4. BFS");
		printf("\n 5. DFS");
		printf("\n 6. Exit\n");
		
		printf("---\n\t Enter Choice : ");
		scanf("%d",&ch);
		printf("---------------------------------------------------");
		switch(ch)
		{
			case 1:	printf("\n Enter the No. of nodes : ");
					scanf("%d",&n);
					create(g,n);
					break;
					
			case 2:	display_adj_mat(g,n);
					break;
			case 3:	display_adj_list(g,n);
					break;
			case 4:	for(i=0;i<n;i++)
					{
						visited[i]=0;
						queue[i]=0;
					}
					printf("\n BFS : ");
					bfs(g,n,5);
					
    				for (i=0;i<n;i++)
    				{
					if(visited[i])
            				{
						printf("%d\t", i);
					}
            			}printf("\n");
					break;

			case 5:	for(i=0;i<n;i++)
					{
						visited[i]=0;
						queue[i]=0;
					}
					printf("\n DFS : ");
					dfs(g,n,0);
					printf("\n");
					break;
			case 6:	exit(0);
			
			default:printf("\n Invalid Choice");
		}

	}while(1);

	return 0;
}
