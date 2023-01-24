#include <stdio.h>
#include <stdlib.h>
int count=0;
int v,e;
int visited[20];
int mat[20][20];
int queue[20],front=0,rear=-1;
void bfs(int w)
{
 int j;
 count++;
 visited[w]=count; //Mark vertex w as visited
 rear++;
 queue[rear]=w; //Add w to the queue
 while(front<=rear)
 {
 printf("%d(%d)\t",queue[front],visited[queue[front]]);
 for(j=1; j<=v; j++)
 {
 if(visited[j]==0 && mat[queue[front]][j]==1) //Add all adjacent vertices of queue[front] to queue
 {
 count++;
 visited[j]=count;
 rear++;
 queue[rear]=j;
 }
 }
 front++; //Remove front vertex from queue after processing it
 }
}
void BFS()
{
 int i;
 for(i=1; i<=v; i++) //Ensures all the vertices are visited
 {
 if(visited[i]==0)
 bfs(i);
 }
}
int main()
{
 int i;
 int v1,v2,ch;
 printf("Select the type of Graph:\n\t> 1.Directed Graph\n\t> 2.Undirected Graph\n");
 scanf("%d",&ch);
 if(ch!=1 && ch!=2)
 {
 printf("Invalid option !!");
 return 0;
 }
 printf("Enter the number of vertices : ");
 scanf("%d",&v);
 printf("Enter the number of edges : ");
 scanf("%d",&e);
 printf("Enter %d edges one by one : \n",e);
 for(i=1; i<=e; i++)
 {
 printf("Edge-%d : ",i);
 scanf("%d%d",&v1,&v2);
 if(ch==1)
 mat[v1][v2]=1; //Directed graph
 else
 mat[v1][v2]=mat[v2][v1]=1; //Undirected graph
 }
 printf("\nOrder of vertices processed:\n");
 BFS();
 return 0;
}
