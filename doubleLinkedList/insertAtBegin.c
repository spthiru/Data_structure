#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node* prev;
   struct Node* next;
};

typedef struct Node node_t;

node_t* createNode(int);
void insertAtEnd(node_t**, int);
void printList(node_t*);
void insertBefore(node_t**, int, int);

int main()
{
   int data, val, num, position;
   node_t* head = NULL;
   while (1)
   {
      scanf("%d", &val);
      switch (val)
      {
	 case 1:
      	    scanf("%d", &data);
	    insertAtEnd( &head, data);
	    break;
	 case 2:
	    printList(head);
	    break;
	 case 3:
	    printf("Enter number :");
	    scanf("%d", &num);
	    printf("Enter position :");
	    scanf("%d", &position);
	    insertBefore(&head, num, position);
	    break;
      }

      if ( val == 6)
      {
	 break;
      }
   }
}

node_t* createNode(int data)
{
   node_t* newNode;

   newNode = (node_t*)malloc(sizeof (node_t));

   if (newNode == NULL)
   {
      printf("Memory allocation failed!");
      exit(-1);
   }

   newNode->data = data;
   newNode->prev = NULL;
   newNode->next = NULL;
   return newNode;
}

void insertAtEnd(node_t** head, int data)
{
   node_t* newNode = createNode(data);

   if (*head == NULL)
   {
      *head = newNode; 
      return;
   }

   node_t* temp = *head;

   while (temp->next != NULL)
   {
      temp = temp->next;
   }
      newNode->prev = temp;
      temp->next = newNode;
}

void printList(node_t* head)
{
   node_t* temp;

   temp = head;
   while (temp->next != NULL)
   {
      printf("%d->", temp->data);
      temp = temp->next;
   }
   printf("%d->NULL\n", temp->data);
   printf("\n");

   while (temp->prev != NULL)
   {
      printf("%d->", temp->data);
      temp = temp->prev;
   }
   printf("%d->head\n", temp->data);
}

void insertBefore(node_t** head, int data, int pos)
{
   int inc = 0; 
   node_t* newNode = createNode(data);

   node_t* temp = *head;
   /*if (pos == 1)
   {
	 newNode->next = *head;
	 (*head)->prev = newNode;
	 *head = newNode;
   }*/
   if(pos != 1)
   {
   while (temp->next != NULL)
   {
      if(inc == (pos-1))
      {
	 newNode->prev = temp->prev;
	 temp->prev = newNode;
	 break;
      }
      inc++;
      temp = temp->next;
   }
   inc = 0;
   node_t* temp1 = *head;
   while (temp1->next != NULL)
   {
      if (inc == (pos-2))
      {
	 newNode->next = temp1->next;
	 temp1->next = newNode;
      }
      inc++;
      temp1 = temp1->next;
   }
   }
}
