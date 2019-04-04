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
typedef struct block *queue;
typedef struct block
{
	int data;
	queue link;
}block;
queue front,rear;
 
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
	for(i=0;i<n;i++)
    {     
		printf("Enter number of edges:");
       	scanf("%d",&e);
    for(i=0;i<e;i++)
        {
        	printf("Enter edge :");
			scanf("%d%d",&v1,&v2);
			insert(v1,v2);
        }
    }
} 
int q_empty()
{
	if(!front) return 1;
	return 0;
}
void addq(int x)
{
queue temp;
MALLOC(temp,sizeof(temp));
temp->data = x;
temp->link = rear;
rear = temp;
if(!front)
front = rear;	
}
int delq()
{int i;
	queue temp;
	temp = front;
	if(front==rear)
	{
	front = rear = NULL;
	return (temp->data);	
	}
	else{
	for(temp = rear;(temp->link)!=front;temp=temp->link);
    i = temp->link->data;
    temp->link = NULL;
    front = temp;
    return i;
	}
}
void bfs(int i)
{
    graph temp;
    addq(i);
	while(!q_empty())
	{
	i = delq();
	if(!visited[i])
	{
	printf("%d\n",i);
	visited[i] = 1;
	for(temp=ver[i];temp!=NULL;temp=temp->edge) if(!visited[temp->vertex]) addq(temp->vertex);
	}}
}

void main()
{
    int i;
    initialise();
    read();
    printf("Enter the vertex number : ");
    scanf("%d",&i);
    printf("\n***BFS TREE***\n");
    bfs(i);
}
