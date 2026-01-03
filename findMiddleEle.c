#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
node *createNode(int v)
{
	node *nn=(node *)malloc(sizeof(node));
	nn->data=v;
	nn->next=NULL;
	return nn;
}
node *findMiddle(node *head)
{
	node *slow=head;
	node *fast=head;
	while(slow->next!=NULL && slow->next->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	
	return slow;
}
void display(node *head)
{
	if(head==NULL)
	{
		printf("list is empty");
	}
	else{
		node *temp=head;
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}
int main()
{
	node *head=createNode(10);
	head->next=createNode(20);
	head->next->next=createNode(30);
	display(head);
	printf("%d",findMiddle(head)->data);
}