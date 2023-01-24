#include <stdio.h>
#include <stdlib.h>
int count = 0;
int v, e;
int visited[20], mat[20][20];
void dfs(int w)
{
    int j;
    count++;
    visited[w] = count; // Mark vertex w as visited
    printf("%d(%d)\t", w, visited[w]);
    for (j = 1; j <= v; j++)
        if (mat[w][j] == 1 && visited[j] == 0)
            dfs(j);
}
void DFS() // To ensure all the vertices are visited
{
    int i;
    for (i = 1; i <= v; i++)
    {
        if (visited[i] == 0)
            dfs(i);
    }
}
int main()
{
    int i;
    int v1, v2, ch;
    printf("Select the type of Graph:\n\t> 1.Directed Graph\n\t> 2.Undirected Graph\n");
    scanf("%d", &ch);
    if (ch != 1 && ch != 2)
    {
        printf("Invalid option !!");
        return 0;
    }
    printf("Enter the number of vertices : ");
    scanf("%d", &v);
    printf("Enter the number of edges : ");
    scanf("%d", &e);
    printf("Enter %d edges one by one :\n", e);
    for (i = 1; i <= e; i++)
    {
        printf("Edge-%d : ", i);
        scanf("%d%d", &v1, &v2);
        if (ch == 1)
            mat[v1][v2] = 1; // Directed graph
        else
            mat[v1][v2] = mat[v2][v1] = 1; // Undirected graph
    }
    printf("\nOrder of vertices processed:\n");
    DFS();
    return 0;
}
