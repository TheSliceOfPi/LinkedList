#include <stdio.h>
#include <stdlib.h>

int size=0;

typedef struct node
{
	struct node * next;
	int value;
} 	Node; 

void add(Node **head,int new) //Double pointer so pointer to head can point to the first number
{
	Node *newNode= (Node*) malloc(sizeof(Node));
	newNode->value=new;
	if (size==0)
	{
		newNode->next=NULL;
		(*head)->next=newNode->next;
		*head=newNode;
		
	}
	else
	{
	Node *current= *head;
	while(current->next!=NULL && newNode->value>current->next->value)
	{	
		current=current->next;
	}
	if(current==*head && newNode->value < current->value)
	{
		newNode->next=current;
		*head=newNode;
	}
	else
	{
		newNode->next=current->next;
		current->next=newNode;
	}
	}
	size=size+1;
	
	
}
void printList(Node **head)
{
	Node *current = *head;
	printf("%d\n", current->value);
	while(current->next!=NULL)
	{
		current=current->next;
		printf("%d\n", current->value);
	}
	
}


int main()
{
	Node * head= (Node*) malloc(sizeof(Node));
	head->value=0;
	head->next=NULL;
	
	add(&head,5);
	add(&head,99);
	add(&head,10);
	add(&head,2);
	printList(&head);
}
