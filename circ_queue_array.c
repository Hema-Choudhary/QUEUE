#include<stdio.h>
#define MAX 5

typedef struct queue
{
 int nos[MAX];
 int f,r;
}queue;
 
queue q;

void init(void);
int isfull(void);
void add(void);
int isempty(void);
int rem(void);
void disp(void);

void init(void)
{
 q.f=q.r=-1;
}

int isfull(void)
{
 if((q.r+1%MAX) == q.f || (q.f==-1 && q.r==MAX-1))
  return 1;
 else return 0;
}

void add(void)
{
 if(q.r==-1)
  q.r=0;
 else 
  q.r=(q.r+1)%MAX;
 fprintf(stdout,"\nEnter the No:");
 fscanf(stdin,"%d",&q.nos[q.r]);
}

int isempty(void)
{
 if(q.r==-1 && q.f==-1)
  return 1;
 else 
  return 0;
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
  q.f=(q.f+1)%MAX;
 return x;
}

void disp(void)
{
 int i;
 if(q.f==-1)
  i=0;
 else
  i=q.f;
 printf("\n");
 for(;i!=q.r;i=(i+1)%MAX)
  printf("\t %d",q.nos[i]);
 printf("\t %d",q.nos[q.r]);

}

int main(void)
{
 int op;
 init();
 do
 {
  fprintf(stdout,"\n1)add\n2)remove\nEnter:");
  fscanf(stdin,"%d",&op);
  switch(op)
  {
   case 1:if(!isfull())
            add();
          else printf("\nFULL");
 	  disp();
	  break;
   case 2:if(!isempty())
 	    fprintf(stdout,"\n REMOVED: %d",rem());
	  else printf("\nEMPTY");
  }
 }while(op<=2);
return 0;
}
