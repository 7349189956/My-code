#include<stdio.h>
#include<stdlib.h>
void bfs(int src,int adj[10][10],int n)
{
int q[20],front=0,rear=-1,v,u,visited[ 10]={0};
q[++rear]=src;
visited[src]=1;
printf("%d\t",src);
while(front<=rear)
{
u=q[front++];
for(v=1;v<=n;v++)
{
if(adj[u][v]==1&&visited[v]==0)
{
q[++rear]=v;
printf("%d\t",v);

visited[v]=1;
}
}
}
}
int main()
{
int ch,i,j,src;
int adj[10][10],n;
while(1)
{
printf("\nProgram to Perform Graph Operation\n");

printf("\n1:Create a graph of N cities\n2:To print reachable nodes from source node using BFS\n3:Exit\n");
printf("Enter your choice:\t");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter the number of cities\t");
         scanf("%d",&n);
        printf("Enter the adjacency matrix\n");
       for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
        scanf("%d",&adj[i][j]);
        break;
case 2:printf("Enter the source vertex to start traversal:\n");
      scanf("%d",&src);
       printf("Vertices visited are:\n");
     bfs(src,adj,n);
      break;

case 3: exit(0);
default:printf("\nInvalid Choice\n");
}
}
return 0;
}
