#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

typedef struct Node node_t;

node_t* createNode(int);
void insertAtEnd(node_t **, int data);
void printList(node_t*);

int main()
{
  node_t* head = NULL;

  insertAtEnd(&head, 10);
  insertAtEnd(&head, 20);
  printList(head);
  insertAtEnd(&head, 30);
  insertAtEnd(&head, 40);
  printList(head);
}
//Function create a newNode
node_t* createNode(int data)
{
  node_t* newNode;
  newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL)
  {
    printf("memory allocation failed!\n");
    exit(-1);
  }

  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}
//Function insert a node at end
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

  temp->next = newNode;
}
//function print the data
void printList(node_t* head)
{
  node_t* temp;
  temp = head;
  printf("Head -> ");
  while (temp->next != NULL)
  {
    printf(" %d ->",temp->data);
    temp = temp->next;
  }
  printf(" NULL\n");
}

