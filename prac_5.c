#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct Node
{
     struct Node* previous;
     char songName[15];
     struct Node* next;
};

struct Node* current = NULL;

struct Node* insert(struct Node *head, char songName[])
{
     struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
     strcpy(ptr->songName, songName);

     if (head == NULL)
     {
          head = ptr;
          head->previous = head;
          head->next = head;

          current = head;
          
          printf("%s added.\n", songName);
     }
     else
     {
          struct Node *p = head->previous;

          ptr->previous = p;
          p->next = ptr;
          
          ptr->next = head;
          head->previous = ptr;

          printf("%s added.\n", songName);
     }
     return head;
}

struct Node* delete(struct Node* head, char songName[])
{
     if(head==NULL)
          printf("The playlist is empty!\n");
     else
     {
          struct Node* ptr = head;
          bool flag = false;

          do
          {
               if(strcmp(ptr->songName, songName)==0)
               {
                    if(ptr->next == ptr) // one and only song
                    {
                         printf("%s deleted.\n", songName);

                         head = NULL;
                         current = NULL;

                         flag = true;
                         free(ptr);
                         return head;
                    }
                    else
                    {
                         printf("%s deleted.\n", songName);

                         (ptr->previous)->next = ptr->next;
                         (ptr->next)->previous = ptr->previous;

                         flag = true;
                         free(ptr);
                         return head;
                    }  
               }
               ptr = ptr->next;
          }while(ptr!=head);
          
          if(!flag)
               printf("Song not found!\n");
     }
     
     return head;
}   

void show(struct Node* head)
{
     if(head==NULL)
          printf("The playlist is empty!\n");
     else
     {
          struct Node* ptr = head; 
          do
          {
               printf("%s\n", ptr->songName);
               ptr = ptr->next;
          }while(ptr!=head);
     }
}

void play_next()
{
     if(current == NULL)
          printf("No songs in the playlist!\n");
     else
     {
          current = current->next;
          printf("Playing: %s\n", current->songName);
     }
}

void play_previous()
{
     if(current == NULL)
          printf("No songs in the playlist!\n");
     else
     {
          current = current->previous;
          printf("Playing: %s\n", current->songName);
     }
}

void play_first(struct Node* head)
{
    if(current == NULL)
          printf("No songs in the playlist!\n");
     else
     {
          current = head;
          printf("Playing: %s\n", current->songName);
     }
}

void play_last(struct Node* head)
{
    if(current == NULL)
          printf("No songs in the playlist!\n");
     else
     {
          current = head->previous;
          printf("Playing: %s\n", current->songName);
     }
}

void play_specific(struct Node* head, char songName[])
{    
     if(current == NULL)
          printf("No songs in the playlist!\n");
     else
     {
          struct Node* ptr = head;
          bool flag = false;
          do
          {
               if(strcmp(ptr->songName, songName)==0)
               {
                    printf("Playing: %s\n", songName);
                    current = ptr;
                    flag = true;
                    return;
               }
               ptr = ptr->next;
          } while (ptr!=head);

          if(!flag)
               printf("Song not found!\n");
          
     }
}
int main()
{

     struct Node* head = NULL;

     // Taking user input
     start: //goto
          printf("Enter the operation:\n");
          printf("1: To add a new song.\n");
          printf("2: To delete a song.\n");
          printf("3: To display the playlist.\n");
          printf("4: Play next song.\n");
          printf("5: Play previous song.\n");
          printf("6: Play first song.\n");
          printf("7: Play last song.\n");
          printf("8: Play specific song.\n");
          printf("9: To exit.\n");

          int x;
          scanf("%d", &x);
          getc(stdin);
          switch (x)
          {
               case 1:
               {
                    char songName[15];
                    printf("Enter the song name: ");
                    gets(songName);
                    head = insert(head, songName);
                    printf("\n");
                    goto start;
                    break;
               }
               case 2:
               {
                    char songName[15];
                    printf("Enter the song name to be deleted: ");
                    gets(songName);
                    head = delete(head, songName);
                    printf("\n");
                    goto start;
                    break;
               }
               case 3:
               {
                    show(head);
                    printf("\n");
                    goto start;
                    break;
               }
               case 4:
               {
                    play_next();
                    printf("\n");
                    goto start;
                    break;
               }
               case 5:
               {
                    play_previous();
                    printf("\n");
                    goto start;
                    break;
               }
               case 6:
               {
                    play_first(head);
                    printf("\n");
                    goto start;
                    break;
               }
               case 7:
               {
                    play_last(head);
                    printf("\n");
                    goto start;
                    break;
               }
               case 8:
               {
                    char songName[15];
                    printf("Enter the song name you want to play: ");
                    gets(songName);
                    play_specific(head, songName);
                    printf("\n");
                    goto start;
                    break;
               }
               case 9:
               {
                    return 0;
                    break;
               }
               default:
               {
                    printf("Invalid input.\n");
                    printf("\n");
                    goto start;
               }
          }

     return 0;
}