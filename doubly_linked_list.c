#include <stdio.h>
#include <stdlib.h>

struct Node
{
     struct Node* previous;
     int data;
     struct Node* next;
};
int N = 0;

struct Node* insert(struct Node* head, int index, int data)
{
     struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
     ptr->data = data;

     if (index == 0) //insert at start
     {
          ptr->previous = NULL;
          head->previous = ptr;
          ptr->next = head;
          
          printf("Inserted %d at %d\n", data, index);
          N++;
          return ptr;
     }
     else if(index == N) //insert at start
     {
          struct Node* p = head;
          while(p->next!=NULL)
          {
               p = p->next;
          }
          p->next = ptr;
          ptr->previous = p;
          ptr->next = NULL;
          
          printf("Inserted %d at %d\n", data, index);
          N++;
          return head;
     }
     else
     {
          if(index > N)
          {
               printf("Invalid index.\n");
               return head;
          }
          else
          {
               int i = 0;
               struct Node* p = head;
               while (i != index-1)
               {
                    p = p->next;
                    i++;
               }

               ptr->next = p->next;
               ptr->previous = p;
               p->next = ptr;
               ptr->next->previous = ptr;
               
               printf("Inserted %d at %d\n", data, index);
               N++;
               return head;      
          }
     }
}

struct Node* delete(struct Node* head, int index)
{
     struct Node* ptr = head;
     struct Node* qtr = head->next;
     if(index == 0) //delete at first
     {
          printf("Deleted %d at %d.\n", head->data, index);
          head = head->next;
          head->previous = NULL;
          N--;
          free(ptr);
          return head;
     }
     else if(index == N-1) //delete at end
     {
          while(qtr->next != NULL)
          {
               ptr = ptr->next;
               qtr = qtr->next;

          }
          printf("Deleted %d at %d.\n", qtr->data, index);
          N--;
          ptr->next = NULL;
          free(qtr);
          return head;
     }
     else
     {
          if(index >= N)
          {
               printf("Invalid Index!\n");
               return head;
          }
          else
          {
               int i = 0;
               while(i != index-1)
               {
                    ptr = ptr->next;
                    qtr = qtr->next;
                    i++;
               }
               printf("Deleted %d at %d.\n", qtr->data, index);
               N--;
               qtr->next->previous = ptr;
               ptr->next = qtr->next;
               free(qtr);
               return head;

          }

     }
}
void show(struct Node* ptr)
{
     int i = 0;
     if (N > 0)
     {
          while (ptr != NULL)
          {
               printf("%d at %d\n", ptr->data, i);
               i++;
               ptr = ptr->next;
          }
     }
     else
          printf("The linked list is empty.\n");
}

int main()
{

     struct Node* head = (struct Node*)malloc(sizeof(struct Node));
     head->previous = NULL;
     head->data = 10;
     head->next = NULL;
     N++;

     head = insert(head, 0, 20);
     show(head);
     printf("\n");
     head = insert(head, 1, 15);
     show(head);
     printf("\n");
     head = insert(head, 3, 30);
     show(head);
     printf("\n");
     head = delete(head, 0);
     show(head);
     printf("\n");
     head = delete(head, 3);
     show(head);
     return 0;
}