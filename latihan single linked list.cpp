// Belajar Single Linked List 
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
struct node{
		int data;
		node* link;
};
node* root = NULL;
int len;
void append();
void addatbegin();
void addatafter();
int length();
void display();
void deletenode();
void reverse();
void nodeswap();
void dataswap();
int main()
{
	int ch;
	while(1)
	{
		printf("Single Linked List Operations : \n");
		printf("1. Append\n");
		printf("2. Addatbegin\n");
		printf("3. Addatafter\n");
		printf("4. Length\n");
		printf("5. Display\n");
		printf("6. Delete\n");
		printf("7. Reverse\n");
		printf("8. Node Swap (Not work for node1 & node2)\n");
		printf("9. Data Swap\n");
		printf("10. Quit\n");
		printf("Enter your choice :");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: 
			append();
			break;
			
			case 2:
			addatbegin();
			break;
			
			case 3:
			addatafter();
			break;
			
			case 4:
			len = length();
			printf("Length : %d\n\n",len);
			break;
			
			case 5:
			display();
			break;
			
			case 6:
			deletenode();
			break;
			
			case 7:
			reverse();
			break;
			
			case 8:
			nodeswap();
			break;
			
			case 9:
			dataswap();
			break;	
				
			case 10:
			printf("Thankyou\n");
			exit(1);
			
			default:
			printf("Invalid input\n\n");
		}
	}

}

void append()
{
	node* temp;
	temp = (node*)malloc(sizeof(node));	
	
	printf("Enter node data :");
	scanf("%d",&temp->data);
	temp->link = NULL;
	
	if(root == NULL) // list is empty
	root = temp;
	
	else
	{
		node* p;
		p = root;
		while(p->link != NULL)
		{
			p = p->link;
		}
		p->link = temp;
	}
	printf("\n");
}

int length()
{
	int count = 0;
	node* temps;
	temps = root;
	while(temps != NULL)
	{
		count++;
		temps = temps->link;
	}
	return count;
}

void display()
{
	node* tempd;
	tempd = root;
	if(tempd == NULL) printf("List is empty \n\n");
	else
	{
		while(tempd!= NULL)
		{
			printf("%d-->",tempd->data);
			tempd = tempd->link;
		}
		printf("\n\n");
	}
}

void addatbegin()
{
	node* tempbegin;
	tempbegin = (node*)malloc(sizeof(node));
	
	printf("Enter node data: ");
	scanf("%d",&tempbegin->data);
	tempbegin->link = NULL;
	
	if(root == NULL)
	root = tempbegin;
	
	else
	{
		tempbegin->link = root; // right side connection
		root = tempbegin ; // left side connection
	}
}

void addatafter()
{
	node* tempafter;
	node* p;
	int loc, len, i=1;
	printf("Enter location to add node : ");
	scanf("%d",&loc);
	len = length();
	
	if(loc > len)
	{
		printf("Location does not exist\n");
		printf("List contains only %d nodes\n\n",len);
	}
	
	else
	{
		p = root;
		while(i < loc)
		{
			p = p->link;
			i++;
		}
		tempafter = (node*)malloc(sizeof(node));
		
		printf("Enter node data : ");
		scanf("%d",&tempafter->data);
		
		tempafter->link = NULL;
		
		tempafter->link = p->link; // Right Side Connection
		p->link = tempafter; // Left Side Connection
	}
}

void deletenode()
{
	node* tempdel;
	int loc;
	
	printf("Enter location to delete : ");
	scanf("%d", &loc);
	
	if(loc > length()) printf("Location does not exist. \n\n");
	
	else if(loc == 1)
	{
		tempdel = root;
		root = tempdel->link;
		tempdel->link = NULL;
		free(tempdel);
	}
	else
	{
		node* p;
		p = root;
		node* q;
		int i = 1;
		while(i < loc-1)
		{
			p = p->link;
			i++;
		}
		q = p->link;
		p->link = q->link;
		q->link = NULL;
		free(q);
	}
}

void reverse()
{
	int len = length();
	if(len <= 1) printf("Not Enough Data inside!\n\n");
	
	else{
		
	node* prev;
	node* curr;
	node* next;
	prev = 0;
	curr = next = root;
	while(next != NULL)
	{
		next = next->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}
	root = prev;
	
	}
}

void nodeswap()
{
	int loc,i=1;
	printf("Choose a location to swap :");
	scanf("%d",&loc);
	
	if (loc > length()) printf("Invalid input\n\n");
	
	else{
	node* p; node* q; node* r;
	p = root;
	while(i<loc-1)
	{
		p = p->link;
		i++;
	}
	q = p->link;
	r = q->link;
	q->link = r->link;
	r->link = q;
	p->link = r;
	}
}

void dataswap()
{
	int temp;
	node* p; node* q;
	p = q = root;
	int node1,node2;
	if(length() <= 1) printf("Not enough node!\n\n");
	
	else{
	printf("choose node1 :");
	scanf("%d",&node1);
	printf("choose node2 :");
	scanf("%d",&node2);
	for(int i = 1;i<node1;i++){
		p = p->link;
	}
	for(int j = 1;j<node2;j++){
		q = q->link;
	}
	temp = p->data;
	p->data = q->data;
	q->data = temp;
	}
}
