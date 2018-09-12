/*Header Files*/
#include<stdio.h>
#include<malloc.h>

/*Structure*/
typedef struct queue
{
 int no;
 struct queue *next;
}q;
q *trac;


/*Func Prototypes*/
void init(void);
void add(void);
int isempty(void);
int removeq(void);
void disp(void);


/*Functions*/
void init(void)
{
 trac=NULL;
}

void add(void)
{
 q *new;
 new=(q*)malloc(sizeof(q));
 fprintf(stdout,"\nEnter the no:");
 fscanf(stdin,"%d",&new->no);
 new->next=NULL;
 if(trac==NULL)
 {
  new->next=new;
  trac=new;
 }
 else
 {
  new->next=trac->next;
  trac->next=new;
  trac=new; 
 }
}


int isempty(void)
{
 if(trac==NULL)
  return 1;
 else return 0;
}

int removeq(void)
{
 int no;
 q *tmp; 
 tmp=trac->next; 
 no=tmp->no;
 if(tmp==trac)
  trac=NULL;
 else
  trac->next=tmp->next;
 free(tmp);
 return no; 
}


void disp(void)
{
 q *tmp;
 printf("\n");
 for(tmp=trac->next;tmp!=trac;tmp=tmp->next)
 { 
   printf("\t%d",tmp->no);
 }
 printf("\t%d",trac->no);
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
   case 1: add();disp();break;
   case 2: if(!isempty())
            fprintf(stdout,"REMOVED: %d",removeq());
           else fprintf(stdout,"\nEmpty");
           break;
  }
 }while(op<=2);
 
 return 0;
}


