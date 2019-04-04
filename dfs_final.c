#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s)\
if(!(p=malloc(s)))\
printf("ERROR\n");
typedef struct node *graph;
typedef struct node
{
    int vertex;
    graph edge;
}node;
 
graph ver[10];   
short int visited[10];
int n;
void initialise()
{int i;
	for(i=0;i<n;i++)
	{
	ver[i]=NULL;	
    visited[i]=0;
	}
}
void insert(int v1,int v2)
{
    graph temp,new_;
	MALLOC(new_,sizeof(node));
    new_->vertex=v2;
    new_->edge=NULL;
    if(ver[v1]==NULL)
    ver[v1]=new_;
    else
    {
		for(temp=ver[v1];temp->edge!=NULL;temp=temp->edge);
        temp->edge=new_;
    }
}
void read()
{
    int i,v1,v2,e;
    printf("Enter number of vertices:");
	scanf("%d",&n);
	printf("Enter number of edges:");
    scanf("%d",&e);
    for(i=0;i<e;i++)
        {
        	printf("Enter edge :");
			scanf("%d%d",&v1,&v2);
			insert(v1,v2);
        }
} 

void dfs(int i)
{
    graph temp;  
	printf("\n%d",i);
	visited[i]=1;
    temp=ver[i];
    while(temp!=NULL)
    {
       i=temp->vertex;
	   if(!visited[i])
       dfs(i);
    temp=temp->edge;
    }
}

void main()
{
    int i;
    initialise();
    read();
    printf("Enter the vertex number : ");
    scanf("%d",&i);
    printf("\n***DFS TREE***\n");
    dfs(i);
}
