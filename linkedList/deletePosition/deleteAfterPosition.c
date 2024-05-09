#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node* next;
};

typedef struct Node node_t;

node_t* createNode( int );
void insertNode( node_t**, int );
void printList( node_t* );
void deletePosition( node_t**, int );
int main()
{
   int pos;
   node_t* head = NULL;

   insertNode( &head, 10 );
   insertNode( &head, 20 );
   insertNode( &head, 30 );
   insertNode( &head, 40 );
   insertNode( &head, 50 );
   printList(head);

   printf( "Enter the position to delete : " );
   scanf( "%d", &pos );
   deletePosition( &head, pos );
   printList(head);
}
node_t* createNode( int data )
{
   node_t* newNode;

   newNode = ( node_t* )malloc(sizeof( node_t ));

  if( newNode == NULL )
  {
     printf("Memory allocation failed!\n");
     exit(-1);
  } 

  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

void insertNode( node_t** head, int data )
{
   node_t* newNode = createNode( data );

   if( *head == NULL )
   {
      *head = newNode;
      return;
   }

   node_t* temp = *head;

   while( temp->next != NULL )
   {
      temp = temp->next; 
   }
   temp->next = newNode;
}
void printList( node_t* head )
{
   node_t* temp;
   temp = head;

   while( temp->next != NULL )
   {
      printf( "%d->",temp->data );
      temp = temp->next;  
   }
   printf("\n");
}
void deletePosition( node_t** head, int pos )
{
   int inc = 0, k = 0; 

   node_t* temp = *head;
   node_t* temp1 = *head;
  
      node_t* nextAdrr;

      while( temp->next != NULL)
      {
	 if( inc == pos+1 )
	 {
	    nextAdrr = temp->next;
	    while( temp1->next != NULL )
	    {
	       if( k == (pos) )
	       {
		  temp1->next = nextAdrr;
		  break;
	       }
	       temp1 = temp1->next;
	       k++;
	    }
	    break;
	 }
	    temp = temp->next;
	    inc++;
      }
}
