#include <stdio.h>
#include <stdlib.h>
int v, e, visited[20], mat[20][20], p = 0;
int sorted[20], count = 0, c = 0, limit = 0;
void TopologicalSort()
{
    int i, j, n;
    n = v;
    while (n != 0) // Whether all vertices are removed
    {
        for (i = 1; i <= v; i++)
        {
            if (visited[i] == 0)
            {
                c++; // To check whether G has cycle by counting the number of times this statement executes.
                // The above statement can execute at most n(n+1)/2 times because for each time one vertex will be
                //  removed, if the graph is not cyclic. If the above statement executes more than n(n+1)/2 times then
                //  the graph is cyclic and topological sort cant be performed.
                for (j = 1; j <= v; j++) // check for vertex having indegree 0
                    if (mat[j][i] == 1)
                        break;
                if (j == v + 1) // vertex do not have indegree
                {
                    sorted[p++] = i;
                    count++;
                    visited[i] = count;
                    n--;
                    int k;
                    for (k = 1; k <= v; k++) // Remove all outgoing edges of i
                        mat[i][k] = 0;
                    break;
                }
            }
            if (c > limit) // There is cycle
                return;
        }
    }
}
int main()
{
    int i, v1, v2;
    printf("Enter the number of vertices : ");
    scanf("%d", &v);
    printf("Enter the number of edges : ");
    scanf("%d", &e);
    printf("Enter %d edges in the following format:\n", e);
    printf("Format : STARTING_VERTEX <space> TERMINAL_VERTEX\n");
    for (i = 1; i <= e; i++)
    {
        printf("Edge-%d : ", i);
        scanf("%d%d", &v1, &v2);
        mat[v1][v2] = 1;
    }
    limit = (v * (v + 1)) / 2;
    TopologicalSort();
    if (c > limit)
        printf("Graph is cyclic. \nTopological sort cannot be performed.!!");
    else
    {
        printf("\nTopologically sorted order:\n");
        for (i = 0; i < v; i++)
            printf("\t%d", sorted[i]);
    }
    return 0;
}
