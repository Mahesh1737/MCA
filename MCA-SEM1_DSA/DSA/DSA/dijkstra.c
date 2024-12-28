// #include<stdio.h>
// #define max 10
// #define M 999

// int wt[max],vis[max];
// int adj[max][max],n,s,h;

// int min_key()
// {
//     int minimum=M,min,i;
//     for (i=0;i<n;i++)
//     {
//         if (vis[i]==0 && wt[i]<minimum)
//         {
//            minimum=wt[i];
//            min=i;
//         }
//     }
//     return min;
// }
// void dick(int s)
// {
//      int i,j,u;
//      for (i=0;i<n;i++)
//      {
//          wt[i]=M;
//          vis[i]=0;
//      }
//      wt[s-1]=0;
//      for (i=0;i<n-1;i++)
//      {
//          u=min_key();
//          vis[u]=1;
//          for (j=0;j<n;j++)
//          {
//              if ( vis[j]==0 && adj[u][j] && wt[u]!=M && wt[u]+adj[u][j] < wt[j] )
//                 wt[j]=wt[u]+adj[u][j];
//          }
//      }

// }
// void print()
// {
//      printf("\n Shortest path from vertex %d : ",s);
//      for (int i=0;i<n;i++)
//      {
//           if (i != s)
//                   printf("\n Shortest path from %d-->%d  %d ",s,i+1,wt[i]);
//           else
//              printf("\n Shortest path from %d-->%d  %d ",s,i+1,wt[i]);
//      }

// }
// void main()
// {
//      int i,j,w,tw=0;
//      printf("\n Enter no of areas in the city: ");
//      scanf("%d",&n);

//      for (i=0;i<n;i++)
//          for (j=0;j<n;j++)
//          {
//               if (i==j)
//                  adj[i][j]=0;
//               else
//                  adj[i][j]=999;
//           }
//      printf ("\n Enter edges or links between areas: \n ");
//      while (1)
//      {
//             printf ("\n Enter the edge between areas areas  :  ");
//             scanf ("%d%d",&i,&j);
//             if (i==0 || j==0)
//                 break;
//             printf ("\n Enter weight of edge between two areas :  ");
//             scanf ("%d",&w);
//             if (w<0)
//                printf("\n Negative cost is not allowed..");
//             else
//             {
//                adj[i-1][j-1]=w;
//                adj[j-1][i-1]=w;
//             }
//      }
//       printf ("\n Adjacency matrix of areas of City is : \n    ");
//       for (i=0;i<n;i++)
//            printf (" %d ",i+1);
//       for (i=0;i<n;i++)
//       {
//            printf ("\n  %d ",i+1);
//            for (j=0;j<n;j++)
//                printf (" %d ",adj[i][j]);
//       }

//       printf("\n Enter vertex (college) To start :  ");
//       scanf("%d",&s);
//       printf("\n Enter vertex (home) To reach :  ");
//       scanf("%d",&h);
//       dick(s);
//       print();
//       printf("\n\n");
// }

#include <stdio.h>
#include <limits.h>

#define max 10

int adj[max][max], vis[max], n, w, e, s;
int wt[max];

int minKey()
{
    int minimum = INT_MAX, min;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0 && wt[i] < minimum)
        {
            minimum = wt[i];
            min = i;
        }
    }
    return min;
}

void dij(int s)
{
    int i, j, u;
    for (int i = 0; i < n; i++)
    {
        wt[i] = INT_MAX;
        vis[i] = 0;
    }
    wt[s - 1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        u = minKey();
        vis[u] = 1;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == 0 && adj[u][j] && wt[u] + adj[u][j] < wt[j])
            {
                wt[j] = wt[u] + adj[u][j];
            }
        }
    }
}

void print()
{
    printf("\nShoetest path from vertex %d", s);
    for (int i = 0; i < n; i++)
    {
        if (i != s)
            printf("\nPath from %d-->%d : weight: %d", s, i + 1, wt[i]);
        else
            printf("\nPath from %d-->%d : weight: %d", s, i + 1, wt[i]);
    }
}

int main()
{
    int i, j;
    printf("\nENter the number of the edges : ");
    scanf("%d", &n);

    printf("\nEnter the edges from the city: ");
    while (1)
    {
        printf("\nEnter the path front the source to destination : ");
        scanf("%d%d", &i, &j);
        if (i == 0 && j == 0)
            break;
        printf("\nEnter the weight for the paths : ");
        scanf("%d", &w);
        if (w < 0)
        {
            printf("Weight is invalid : ");
        }
        else
        {
            adj[i - 1][j - 1] = w;
            adj[j - 1][i - 1] = w;
        }

        printf("\n Adjacency matrix of areas of City is : \n    ");
        for (i = 0; i < n; i++)
            printf(" %d ", i + 1);
        for (i = 0; i < n; i++)
        {
            printf("\n  %d ", i + 1);
            for (j = 0; j < n; j++)
                printf(" %d ", adj[i][j]);
        }
    }
    printf("\nEnter the source vertex : ");
    scanf("%d", &s);

    dij(s);
    print();

    printf("\n");
}
