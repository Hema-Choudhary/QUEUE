/*Header Files*/
#include<stdio.h>
#include<malloc.h>


/*Stucture*/
typedef struct queue
{
 int no;
 struct queue *next;
}q;
q *f,*r;


/*Func Prototypes*/
void init(void);
void add(void);
int removeq(void);
int isempty(void);
void disp(void);


/*Functions*/
void init(void)
{
 f=r=NULL;
}

void add(void)
{
 q *new;
 new=(q*)malloc(sizeof(q));
 fprintf(stdout,"\nEnter no: ");
 fscanf(stdin,"%d",&new->no);
 new->next=NULL;
 if(r==NULL && f==NULL)
 {
  f=r=new;
 }
 else
 {
  r->next=new;
  r=new;
 }
}

int isempty(void)
{
 if(f==NULL && r==NULL)
  return 1;
 else return 0;
}

int removeq(void)
{
 q *tmp;
 int no;
 
 no=f->no;
 tmp=f;
 if(tmp==r)
  f=r=NULL;
 else
  f=f->next;
 free(tmp);
 return no;
}

void disp(void)
{
 q* tmp;
 printf("\n");
 for(tmp=f;tmp!=r;tmp=tmp->next)
  printf("\t%d",tmp->no);
 printf("\t %d",r->no);
}

int main(void)
{
 int op;
 init();
 do
 {
  fprintf(stdout,"\n1)add\n2)remove\nEnter op:");
  fscanf(stdin,"%d",&op);
  switch(op)
  {
   case 1: add();disp();break;
   case 2: if(!isempty())
            fprintf(stdout,"REMOVED: %d",removeq());
           else
             fprintf(stdout,"\nEMPTY");
          
  }

 }while(op<=2);
 return 0;
}
