#include <stdio.h> // buat semua library
#include <stdlib.h>
#include <windows.h>

struct node{
	int data;
	node* left;
	node* right;
}*head,*tail;

void append();
void display();
void addatbegin();
void addatend();
void addatpos();
int length();
void addatafterpos();
void delbegin();
void delend();
void delpos();
void reverse();

int main()
{
	while(1){
	int choice;
	printf("Welcome to the Double Linked List Operations!\n");
	printf("1. Append\n");
	printf("2. Add at begin\n");
	printf("3. Add at end\n");
	printf("4. Add at pos\n");
	printf("5. Add at after pos\n");
	printf("6. Length\n");
	printf("7. Display\n");
	printf("8. Delete from begin\n");
	printf("9. Delete from end\n");
	printf("10. Delete from pos\n");
	printf("11. Reverse\n");
	printf("12. Quit\n");
	printf("Enter your choice : ");
	
	scanf("%d",&choice);
	switch(choice){
		case 1:
		append();
		break;
		
		case 2:
		addatbegin();
		break;
		
		case 3:
		addatend();	
		break;
		
		case 4:
		addatpos();	
		break;
		
		case 5:
		addatafterpos();
		break;
		
		case 6:
		int len;
		len = length();
		printf("Length : %d\n\n",len);
		break;
		
		case 7:
		display();
		break;
		
		case 8:
		delbegin();
		printf("\n");
		break;
		
		case 9:
		delend();	
		break;
		
		case 10:
		delpos();
		break;
		
		case 11:
		reverse();
		break;
		
		case 12:
		exit(0);
		break;
		
		default:
		printf("Invalid input\n\n");
	}
	
	
	
	}	
	return 0;
	
}

void append()
{
	node* temp;
	temp = (node*)malloc(sizeof(node));
	printf("input node data :");
	scanf("%d",&temp->data);
	temp->right = NULL;
	temp->left = NULL;
	if(head == NULL) head = tail = temp;
	else
	{
		tail->right = temp;
		temp->left = tail;
		tail = temp;
	}
	printf("\n");
}

void display()
{
	node* temp;
	temp = head;
	if(temp == NULL) printf("List is empty \n\n");
	else{
	while(temp != NULL)
	{
		printf("%d-->",temp->data);
		temp = temp->right;
	}
		printf("\n\n");	
	}
}

void addatbegin()
{
	node* temp;
	temp = (node*)malloc(sizeof(node));
	printf("Enter data :");
	scanf("%d",&temp->data);
	temp->right = NULL; temp->left = NULL;
	if(head == NULL) head = temp;
	else{
	head->left = temp;
	temp->right = head;
	head = temp;
	}
}

void addatend()
{
	node* temp;
	temp = (node*)malloc(sizeof(node));
	printf("Enter data :");
	scanf("%d",&temp->data);
	temp->right = NULL, temp->left = NULL;
	if(tail == NULL) head = tail = temp;
	else{
		tail->right = temp;
		temp->left = tail;
		tail = temp;
	}
}

int length()
{
	int i=0;
	node* temp;
	temp = head;
	while(temp != NULL)
	{
		i++;
		temp = temp->right;
	}
	return i;
}

void addatpos()
{
	int pos,i=1;
	node* p;
	printf("Enter a position :");
	scanf("%d",&pos);
	if(pos > length()) printf("Invalid position!");
	else if(pos == 1) addatbegin();
	else
	{
		node* temp;
		temp = (node*)malloc(sizeof(node));
		printf("Enter data :");
		scanf("%d",&temp->data);
		temp->right = NULL; temp->left = NULL;
		p = head;
		while(i < pos-1)
		{
			 p = p->right;
			 i++;
		}
		 temp->left = p ;
		 temp->right = p->right;
		 p->right = temp;
		 tail->left = temp;
		 //temp->right->left = temp; // atau
	}
}

void addatafterpos()
{
	int pos,i=1;
	node* p;
	printf("Enter a position :");
	scanf("%d",&pos);
	if(pos > length()) printf("Invalid position!");
	else if(pos == 1) addatbegin();
	else
	{
		node* temp;
		temp = (node*)malloc(sizeof(node));
		printf("Enter data :");
		scanf("%d",&temp->data);
		temp->right = NULL; temp->left = NULL;
		p = head;
		while(i < pos)
		{
			 p = p->right;
			 i++;
		}
		 temp->left = p;
		 temp->right = p->right;
		 p->right = temp;
		 tail->left = temp;
		 //temp->right->left = temp; // atau
	}
}

void delbegin()
{
	node* temp;
	if(head == NULL) printf("No Data here!");
	else if(head == tail)
	{
		temp = head;
		head=tail=NULL;
		free(temp);
	}
	else
	{
		temp = head;
		head = head->right;
		head->left = NULL;
		temp->right = NULL;
		free(temp);
	}
}

void delend()
{
	node* temp;
	if(tail == NULL) printf("No data here!");
	else if(head == tail)
	{
		temp = head;
		head = tail = NULL;
		free(temp);
	}
	else{
		temp =tail;
		tail = tail->left;
		tail->right = NULL;
		free(temp);
	}
}

void delpos()
{
	int pos,i = 1;
	node* temp;
	printf("Enter a position :");
	scanf("%d",&pos);
	if(pos > length()) printf("Invalid Position!");
	else if(pos == 1) delbegin();
	else{
		temp = head;
		while(i < pos)
		{
			temp = temp->right;
			i++;
		}
		if(temp->right == NULL) // check whether the node you want to delete is last node or not.
		{
			tail = tail->left;
			tail->right = NULL;
			free(temp);
		}
		else{
		temp->left->right = temp->right;
		temp->right->left = temp->left;
		free(temp);
		}
	}
}

void reverse()
{
	node* temp; node* temp2;
	temp = head;
	while(temp != NULL)
	{
	temp2 = temp->right;
	// swap pointer value
	temp->right = temp->left;
	temp->left = temp2;
	temp = temp2;
	}
	//swap head and tail
	temp = head;
	head = tail;
	tail = temp;
}
