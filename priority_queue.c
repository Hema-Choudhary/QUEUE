/*Header Files*/
#include<stdio.h>
#include<malloc.h>


/*Structure*/
typedef struct queue
{
 int no;
 int pri;
 struct queue *next;
}q;
q *f,*r;


/*Prototypes*/
void init(void);
void add(void);
void disp(void);
int isempty(void);
int rem(void);



/*Functions*/
void init(void)
{
 f=NULL,r=NULL;
}

void add(void)
{
 q *new,*tmp;
 new=(q*)malloc(sizeof(q));
 fprintf(stdout,"\nEnter the no:");
 fscanf(stdin,"%d",&new->no);
 fprintf(stdout,"\nEnter the priority:");
 fscanf(stdin,"%d",&new->pri);
 new->next=NULL;
 
 if(r==NULL)
 {
 f=r=new;return;
 }
 
 else
 {
  if(f->pri > new->pri)
  {
   new->next=f;
   f=new;return;
  }
  else
  {
   tmp=f;
   for(;tmp->next!=NULL;tmp=tmp->next)
   {
    if(tmp->next->pri > new->pri)
    {
     new->next=tmp->next;
     tmp->next=new;
     return;
    }
   }
  }
  r->next=new;
  r=new;
  return;
 }
}

int isempty(void)
{
 if(f==NULL && r==NULL)
  return 1;
 else
   return 0;
}

int rem(void)
{
 int x;
 q *tmp;
 tmp=f;
 x=f->no;
 if(tmp==r)
  f=r=NULL;
 else
  f=f->next;
 free(tmp);
 return x;
}

void disp(void)
{
 q *tmp;
 printf("\nNO\tPRI");
 for(tmp=f;tmp!=NULL;tmp=tmp->next)
  printf("\n%d\t%d",tmp->no,tmp->pri);
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
   case 1:add();disp();break;
   case 2:if(!isempty())
           fprintf(stdout,"\nREMOVED : %d",rem());
          else
           fprintf(stdout,"\nEMPTY");
  }
 }while(op<=2);
 return 0;
}
