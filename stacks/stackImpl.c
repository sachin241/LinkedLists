#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
node *top=NULL;
void push(int v)
{
	node *nn=(node *)malloc(sizeof(node));
	if(!nn)
	{
		printf("stack is empty");
		return;
	}
	nn->data=v;
	nn->next=top;
	top=nn;
	printf("%d is pushed successfully into the stack\n",nn->data);
}
void pop()
{
	if(top==NULL)
	{
		printf("stack under flow");
		return;
	}
	node *temp=top;
	int v=temp->data;
	top=top->next;
	free(temp);
	printf("%d is poped from the stack\n",v);
}
void display()
{
	if(top==NULL)
	{
		printf("list is empty");
		return;
	}
	node *temp=top;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	pop();
	display();
}
