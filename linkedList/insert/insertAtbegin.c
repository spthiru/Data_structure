#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node* next;
};

typedef struct Node node_t;

node_t* createNewNode(int);
void insertAtEnd(node_t**, node_t*);
void printList(node_t*);
void insertAtBegin(node_t**, node_t*);
void insertParticularPlace(node_t**, node_t*, int);

int main()
{
   int n;
   node_t* head = NULL;

  // printf("%p\n",&head);
   node_t* newNode = createNewNode(10);
   insertAtEnd(&head, newNode);

   node_t* newNode1 = createNewNode(20);
   insertAtEnd(&head, newNode1);

   printList(head);

   node_t* newNode2 = createNewNode(30);
   insertAtBegin(&head, newNode2);
 
   node_t* newNode3 = createNewNode(40);
   insertAtBegin(&head, newNode3);
   
   printList(head);

   node_t* newNode4 = createNewNode(50);
   printf("Entwr the position of newNode:");
   scanf("%d",&n);
   insertParticularPlace(&head, newNode4, n);
   printList(head);
}

node_t* createNewNode(int data)
{
   node_t* newNode;

   newNode = (node_t*)malloc(sizeof(node_t));
   if(newNode == NULL)
   {
      printf("Memory allocation failed\n");
      exit(-1);
   }

   newNode->data = data;
   newNode->next = NULL;

   return newNode;
}
void insertAtEnd(node_t** head, node_t* newNode)
{
   if(*head == NULL)
   {
      *head = newNode;
      return;
   }

   node_t* temp = *head;

   while(temp->next != NULL)
   {
      temp = temp->next;
   }

   temp->next = newNode;
}
void printList(node_t* head)
{
   node_t* temp;
   temp = head;

   while(temp->next != NULL)
   {
      printf("%d->",temp->data);
      temp = temp->next;
   }
   printf("NULL\n");
}
void insertAtBegin(node_t** head, node_t* newNode)
{
    node_t* oldDataAdrr = *head;
   *head = newNode;
   newNode->next = oldDataAdrr;
}
void insertParticularPlace(node_t** head, node_t* newNode, int n)
{
   int inc = 0;
   node_t* temp = *head;
   node_t* oldAdrr;


   while(temp->next != NULL)
   {
      if(inc == 0 && n == 0)
      {

      }
      printf("%d\n",inc);
      if(inc == n)
      {
         oldAdrr = temp->next;
         temp -> next = newNode;
         newNode -> next = oldAdrr;
	 break;
      }
      inc++;
      temp = temp->next;
   }
}

