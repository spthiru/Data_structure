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
void insertData(node_t**, int );
void printList(node_t*);
void insertBefore(node_t**, int, int);

int main()
{
   int position;

   node_t* head = NULL;

   insertData(&head, 10);
   insertData(&head, 20);
   insertData(&head, 30);
   insertData(&head, 40);
   insertData(&head, 50);
   insertData(&head, 60);

   scanf("%d", &position);
   insertBefore(&head, 70, position);
   printList(head);
}

node_t* createNode(int data)
{
   node_t* newNode = (node_t*)malloc(sizeof(node_t));

   if (newNode == NULL)
   {
      printf("Memory allocation  failed!\n");
      exit(-1);
   }

   newNode->data = data;
   newNode->prev = NULL;
   newNode->next = NULL;

   return newNode;
}
void insertData(node_t** head, int data)
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
   printf("%d->", temp->data);
   printf("NULL\n");

   while (temp->prev != NULL)
   {
      printf("%d->", temp->data);
      temp = temp->prev;
   }
   printf("%d->", temp->data);
   printf("HEAD\n");
}

void insertBefore(node_t** head, int data, int pos)
{
   int inc = 0;
   node_t* newNode = createNode(data);

   node_t* temp = *head;
   node_t* temp1 = *head;

   if (pos == 0)
   {
      temp->prev = newNode;
      newNode->next = temp;
      *head = newNode;
   }

   else if (pos != 0)
   {
      while (temp->next != NULL)
      {
	 temp = temp->next;
	 if (inc == pos-1)
	 {
	    printf("%d\n", temp->data);
	    newNode->next = temp;
	    temp->prev = newNode;
	    break;
	 }
	 inc++;
      }
      inc = 0;
      while (temp1->next != NULL)
      {
	 if(inc == pos-1)
	 {
	    printf("%d\n", temp1->data);
	    newNode->prev = temp1;
	    temp1->next = newNode;
	    break;
	 }
	 temp1 = temp1->next;
	 inc++;
      }
   }
}

