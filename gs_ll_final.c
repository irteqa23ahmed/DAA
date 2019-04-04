#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MALLOC(p,s)\
if(!(p=malloc(s)))\
printf("ERROR\n");

typedef struct node *ptr;
typedef struct node
{
	int data;
	ptr link;
}node;

ptr M[10],W[10];
int m[10],w[10];
int n;

void initialise()
{
int i;
for(i=0;i<n;i++)
m[i]=w[i]=-1;
}

void insert(int i,int j,char gen)
{
    ptr temp,new_;
	MALLOC(new_,sizeof(ptr));
    new_->data=j;
    new_->link=NULL;
    if(gen == 'm')
    {
    if(M[i]==NULL)
    M[i]=new_;
    else
    {
		for(temp=M[i];temp->link!=NULL;temp=temp->link);
        temp->link=new_;
    }
    }
    else
    {
    if(W[i]==NULL)
    W[i]=new_;
    else
    {
		for(temp=W[i];(temp->link!=NULL);(temp=temp->link));
        (temp->link)=new_;
    }
    }
}

void read()
{
int i,j,k;
printf("Enter the number of elements: "); scanf("%d",&n);
printf("\nEnter Men's Preference list:\n");
for(i=0;i<n;i++)
{
printf("M[%d] : ",i);
for(j=0;j<n;j++){
scanf("%d",&k);
insert(i,k,'m');}
printf("\n");
}
printf("\nEnter Women's Preference list:\n");
for(i=0;i<n;i++)
{
printf("W[%d] : ",i);
for(j=0;j<n;j++){
scanf("%d",&k);
insert(i,k,'w');
printf(" ");}
printf("\n");
}
}
int check()
{
int i;
for(i=0;i<n;i++) 
{
if((m[i]!=-1) && (w[i]!=-1))
continue; 
else 
return 1;
}
return 0;
}

int preference(int g,int q)
{
ptr temp;
int i,j;

int curr=w[g];
for(temp=W[g];((temp->data)!=curr) && ((temp->link)!=NULL);(temp = temp->link)) 
if((temp->data)==q) 
{
 m[curr]=-1;
 M[curr] = M[curr]->link; 
 return 1;
}
return 0; 
}

int better_pair(int a,int b)
{
if(w[b]==-1)  return 1;
else return (preference(b,a));
}
void pair(int i,int j)
{int a;
m[i]=j;
w[j]=i;
}

void g_s()
{
int i=0;
 while(check())
  {
   if(m[i]==-1)
    {
      if(better_pair(i,M[i]->data)) 
        pair(i,M[i]->data); 
      else
        M[i] = M[i]->link; 
    }
    else
       M[i] = M[i]->link;
   i=((i+1)%n); 
  }
}

void display()
{
int i;
for(i=0;i<n;i++)
printf("\n M[%d] = W[%d]",i,m[i]);
}

int main()
{
double total_time;
clock_t start, end;
read();
start = clock();
srand(time(NULL));
initialise();
g_s();
end = clock();
display();
total_time = ((double) (end - start)) / CLK_TCK;
printf("%f\n",total_time);
}
