/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>

int m[10][10],w[10][10],m1[10]={-1},w1[10]={-1};
int n;

void read()
{
int i,j;
printf("Enter the number of elements: "); scanf("%d",&n);
printf("\nEnter Men's Preference list:\n");
for(i=0;i<n;i++)
{
printf("M[%d] : ",i);
for(j=0;j<n;j++){
scanf("%d",&m[i][j]);printf(" ");}
printf("\n");
}
printf("\nEnter Women's Preference list:\n");
for(i=0;i<n;i++)
{
printf("W[%d] : ",i);
for(j=0;j<n;j++){
scanf("%d",&w[i][j]);printf(" ");}
printf("\n");
}
}

int check()
{
int i;
for(i=0;i<n;i++) 
{
if((m1[i]!=-1) && (w1[i]!=-1))
continue; 
else 
return 1;
}
return 0;
}

void pair(int i,int j)
{int a;
m1[i]=j;
w1[j]=i;
//for(a=0;a<n;a++) if(w[j][a]==i) {w[j][a]=-1;break;}
for(a=0;a<n;a++) if(m[i][a]==j) 
{
	m[i][a]=-1;
	break;
}
}

int preference(int g,int q)
{
int i,j,curr=w1[g];
for(i=0;i<n;i++) if(w[g][i]==curr) break;
for(j=0;j<n;j++) if(w[g][j]==q) break;
if(i>j) { m1[curr]=-1; return 1;}
else return 0; 
}

int better_pair(int a,int b)
{
if(w1[b]==-1)  return 1;
else return (preference(b,a));
}

void display()
{
int i;
for(i=0;i<n;i++)
printf("\n M[%d] = W[%d]",i,m1[i]);
}

void g_s()
{
int i=0,j=0;
 while(check(n)==1) // check if anyone is free
  {
   if(m1[i]==-1)  // check if m[i] is free
    {
    short int check=0;
    for(j=0;(j<n)&&(check==0);j++)  // look for options to propose
    {
     if(m[i][j]!=-1) // check if priority is available
      {
      if(better_pair(i,m[i][j])) // check if m[i] is better pair for the women preferred if already engaged
       {
        check=1; 
        pair(i,m[i][j]); // pair man and woman
       }
      else
        m[i][j]=-1; //say priority not available
      }
      else
        m[i][j]=-1; //say priority not available
    }
    }
  i=((i+1)%n); //move to next man
   }
}

int main()
{
read();
g_s();
display();
}


