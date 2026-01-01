#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *createnode(int v) {
    node *nn = (node *)malloc(sizeof(node));
    nn->data = v;
    nn->next = NULL;
    return nn;
}
node *insAtBeg(node *head,int v)
{
	node *nn=(node *)malloc(sizeof(node));
	nn->data=v;
	nn->next=NULL;
	nn->next=head;
	head=nn;
	return nn;
}
node *insAtEnd(node *head,int v)
{
	node *nn=(node *)malloc(sizeof(node));
	nn->data=v;
	nn->next=NULL;
	node *temp=head;
	if(head==NULL)
	{
		return nn;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=nn; 
	return head;
}
node *delAtBeg(node *head)
{
	node *temp=head;
	if(head==NULL)
	{
		return NULL;
	}
	head=head->next;
	free(temp);
	return head;
}
node *delAtEnd(node *head)
{
	node *temp=head;
	if(head==NULL)
	{
		return NULL;
	}
	if(head->next==NULL)
	{
		free(head);
		return NULL;
	}
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	free(temp->next);
	temp->next=NULL;
	return head;
}
void display(node *head) {
    if (head == NULL) {
        printf("list is empty\n");
    } else {
        node *t = head;
        while (t!= NULL) {
            printf(" %d ->", t->data);
            t = t->next;
        }
        printf(" NULL\n");
    }
}
void counter(node *head)
{
	int count=0;
	if(head==NULL)
	{
		printf("list is empty");
	}
	node *temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	printf(" count:%d",count);
}

int main() {
    node *head=createnode(10);
    display(head);
    head=insAtBeg(head,20);
    display(head);
    head=insAtEnd(head,30);
    display(head);
    counter(head);
}
