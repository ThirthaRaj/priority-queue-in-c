#include<stdio.h>
#include<stdlib.h>

struct node{
	int priority;
	int value;
	struct node *link;
};
struct node *front=NULL;
struct node *create(struct node *root,int,int);
void display(struct node *root);
int del();

main()
{

	int priority,value,choice,p;
	while(1)
	{
		printf("\n1.to cteate\n2.to display\n3.to delete\n4.exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("\nenter the value \n" );
				scanf("%d",&value);
				printf("\nenter its priority\n");
				scanf("%d",&priority);
				front=create(front,value,priority);
				break;
				
			case 2:display(front);
			       break;
			    
			case 3:
				   printf("\nthe deleted value is %d\n",del());
				   break;
			case 4:exit(1);
			default:printf("\n wrong choice\n");
				   
		}
	}
}

struct node *create(struct node *front,int value,int priority)
{
	struct node *temp,*p;
	
	temp=(struct node *)malloc(sizeof(struct node));
	temp->value=value;
	temp->priority=priority;
	
	if(front==NULL || priority<front->priority)
	{
		temp->link=front;
		front=temp;
		return front;
	}
	
	else
	{
		p=front;
		
		while(p->link != NULL && p->link->priority<=priority)
		   p=p->link;
		   
		 temp->link=p->link;
		 p->link=temp;
		 return front;
	}
	
}

void display(struct node *front)
{
	struct node *p;
	if(front==NULL)
	{
		printf("\nthe queue is empty\n");
		return;
	}
	
	p=front;
	 while(p!=NULL)
	 {
	 	printf("the value =%d\t\t and its priority is =%d \n",p->value,p->priority);
	 	p=p->link;
	 }
}
int del()
{
	int item1;
	struct node *temp;
	if(front==NULL)
	{
		printf("emprty queue\n");
		return;
	}
	else
	{
	temp=front;
	item1=temp->value;
	front=front->link;
     free(temp);
     return item1;
   }
}
