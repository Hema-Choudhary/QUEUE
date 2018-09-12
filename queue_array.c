#include<stdio.h>
#define SIZE 10

typedef struct queue
{
 int nos[SIZE];
 int f,r;
}queue;

queue q;



void init(void);
void add(void);
int rem(void);
int isempty(void);
int isfull(void);
void disp(void);


void init(void)
{
 q.f=q.r=-1;
}

int isfull(void)
{
 if(q.r==SIZE-1)
  return 1;
 else return 0;
}

void add(void)
{
 fprintf(stdout,"\nEnter the no:");
 fscanf(stdin,"%d",&q.nos[++q.r]);
}


int isempty(void)
{
 if(q.f==-1 && -1==q.r)
 {
  return 1;
 }
 else return 0;
}

int rem(void)
{
 int x;
 if(q.f==-1)
  q.f=0;
 x=q.nos[q.f];
 if(q.f==q.r)
  q.f=q.r=-1;
 else
 q.f++;
 return x;
}


void disp(void)
{
 int i;
 printf("\n");
 if(q.f==-1)
   i=0;
 else
   i=q.f;
 for(;i<=q.r;i++)
   printf("\t%d",q.nos[i]);
}

int main(void)
{
 int op;
 init();
 do
 {
  fprintf(stdout,"\n1)add\n2)remove\nEnter: ");
  fscanf(stdin,"%d",&op);
  switch(op)
  {
   case 1:if(!isfull())
           add();
          else
           fprintf(stdout,"\nFULL");
          disp();break;
   case 2:if(!isempty())
           fprintf(stdout,"REMOVED :%d",rem());
          else
           fprintf(stdout,"\nEMPTY");   
  }
 }while(op<=2);
return 0;
}
