/*
Write a program to simulate music playlist application using appropriate data structure.There is no estimation about
number of music files to be managed by this application.It is expected that user may add new music files or may remove music files frequently.
Your Program should support following functionalities : 
(a)play next file
(b) play previous file,
(c)play first file
(d) play last file  
(e) play specific file.
*/

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
     ptr->next = head;

     if (head == NULL)
     {
          head = ptr;
          head->previous = head;

          printf("%s added.\n", songName);
          return head;
     }
     else
     {
          struct Node *p = head;
          while (p->next != NULL)
               p = p->next;

          p->next = ptr;
          ptr->previous = p;

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

          while(ptr!=NULL)
          {
               if(strcmp(ptr->songName, songName)==0)
               {
                    if(ptr->previous == NULL && ptr->next == NULL) // first and last song
                    {
                         printf("%s deleted.\n", songName);

                         head = NULL;

                         flag = true;
                         free(ptr);
                         break;
                    }
                    else if(ptr->previous == NULL && ptr->next != NULL) // first song with many in the playlist
                    {
                         printf("%s deleted.\n", songName);

                         head = ptr->next;
                         head->previous = NULL;

                         flag = true;
                         free(ptr);
                         break;
                    }
                    else if(ptr->previous != NULL && ptr->next == NULL) // last song
                    {

                         printf("%s deleted.\n", songName);

                         (ptr->previous)->next = NULL;

                         flag = true;
                         free(ptr);
                         break;
                    }
                    else
                    {
                         printf("%s deleted.\n", songName);

                         (ptr->previous)->next = ptr->next;
                         (ptr->next)->previous = ptr->previous;

                         flag = true;
                         free(ptr);
                         break;
                    }

               }
               ptr = ptr->next;
          }
          if(!flag)
               printf("Song not found!\n");
     }
     
     return head;
}   

void show(struct Node* ptr)
{
     if(ptr==NULL)
          printf("The playlist is empty!\n");
     else
     {
          while(ptr!=NULL)
          {
               printf("%s\n", ptr->songName);
               ptr = ptr->next;
          }
     }
}

struct Node* play_next(struct Node* current)
{
     if(current == NULL)
          printf("No songs in the playlist!\n");
     else if(current->next == NULL)
          printf("This is the last song already!\n");
     else
     {
          current = current->next;
          printf("Playing: %s", current->songName);
     }

     return current;
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
          printf("4: Play next file.\n");
          printf("5: To exit.\n");

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
                    current = play_next(current);
                    printf("\n");
                    goto start;
                    break;
               }
               case 5:
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
