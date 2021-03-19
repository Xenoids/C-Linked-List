#include <stdio.h> // buat semua library
#include <stdlib.h>

struct node{
	int data;
	node* link;
}*tail;

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
	while(1)
	{
	int choice;
	printf("Welcome to the Circular Linked List Operations!\n");
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
	temp->link = NULL;
	if(tail == NULL)
	{
		tail = temp;
		tail->link = temp;
	} 
	else
	{
		temp->link = tail->link;
		tail->link = temp;
		tail = temp;
	}
	printf("\n");
}

void display()
{
	if(tail == NULL) printf("List is empty \n\n");
	else{
	node* temp;
	temp = tail->link;
	while(temp->link != tail->link)
	{
		printf("%d-->",temp->data);
		temp = temp->link;
	}
	printf("%d-->",temp->data);
	printf("\n\n");
}
	
}
void addatbegin()
{
	node* temp;
	temp = (node*)malloc(sizeof(node));
	printf("input node data :");
	scanf("%d",&temp->data);
	temp->link = NULL;
	if(tail == NULL) 
	{
		tail = temp;
		tail->link = temp;
	}
	else
	{
		temp->link = tail->link;
		tail->link = temp;
	}
	
}

void addatend()
{
	node* temp;
	temp = (node*)malloc(sizeof(node));
	printf("input node data :");
	scanf("%d",&temp->data);
	temp->link = NULL;
	if(tail == NULL)
	{
		tail = temp;
		tail->link = temp;
	}
	else
	{
		temp->link = tail->link;
		tail->link = temp;
		tail = temp;
	}
	
}

void addatpos()
{
	node* temp;
	node* p;
	int pos, i=1;
	printf("Enter a pos :");
	scanf("%d",&pos);
	if(pos<1 || pos > length())
	{
		printf("invalid pos\n");
	}
	else if(pos==1){
		addatbegin();
	}
	else{
		temp = (node*)malloc(sizeof(node));
		printf("Enter node data :");
		scanf("%d",&temp->data);
		temp->link = NULL;
		p = tail->link;
		while(i<pos-1)
		{
			p = p->link;
			i++;
		}
		temp->link = p->link;
		p->link = temp;
		
	}
	
}

int length()
{
	int i = 0;
	if(tail == NULL) return i;
	else{
	int i=1;
	node* temp;
	temp = tail->link;
	while(temp->link != tail->link)
	{
		i++;
		temp = temp->link;
	}
	return i;
	}
}

void addatafterpos()
{
	node* temp;
	node* p;
	int pos, i=1;
	printf("Enter a pos :");
	scanf("%d",&pos);
	if(pos<1 || pos > length())
	{
		printf("invalid pos\n");
	}
	
	else{
		temp = (node*)malloc(sizeof(node));
		printf("Enter node data :");
		scanf("%d",&temp->data);
		temp->link = NULL;
		p = tail->link;
		while(i<pos)
		{
			p = p->link;
			i++;
		}
		temp->link = p->link;
		p->link = temp;
	}
	
}

void delbegin()
{
	if(tail == NULL) {
	printf("No data!\n");
	}
	else{
	node* temp;
	temp = tail->link;
	if(temp->link == temp)
	{
		tail = NULL;
		free(temp);
	}
	else
	{
		tail->link = temp->link;
		free(temp);
	}
	}
}

void delend()
{
	if(tail == NULL) printf("No data!\n");
	else{
	node* curr;
	node* prev;
	curr = tail->link;
		if(curr->link == curr)
		{
			tail = NULL;
			free(curr);
		}
		else
		{
			while(curr->link != tail->link)
			{
				prev = curr;
				curr = curr->link;
			}
			prev->link = tail->link;
			tail = prev;
			free(curr);
		}
	}
	
}

void delpos()
{
	int pos, i = 1;
	printf("Enter Position :");
	scanf("%d",&pos);
	if(pos<1 || pos> length()) printf("Invalid Pos\n");
	else{
	node* curr;
	node* nextnode;
	curr = tail->link;
	if(pos==1){
		delbegin();
	}
	else if(pos == length()){
		delend();
	}
	else{
		while(i<pos-1)
		{
			curr = curr->link;
			i++;
		}
		nextnode = curr->link;
		curr->link = nextnode->link;
		free(nextnode);
	}
	}
}

void reverse()
{
	if(tail == NULL) printf("No data!\n");
	else{
		node* curr;
		node* prev;
		node* nextnode;
		curr = tail->link;
		nextnode = curr->link;
		while(curr!= tail)
		{
			prev = curr;
			curr = nextnode;
			nextnode = curr->link;
			curr->link = prev;			
		}
		nextnode->link = tail;
		tail = nextnode;
	}
}
