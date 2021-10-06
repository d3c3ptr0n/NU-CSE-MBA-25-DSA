#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
int N = 0;

struct Node* insert(struct Node* head, int data, int index)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node*));
    if(index == 0) // insert at first
    {
        ptr->data = data;
        ptr->next = head;

        printf("Inserted %d at index %d.\n", data, index);
        N++;
        return ptr;
    }
    else if(index == N) // insert at end
    {
        ptr->data = data;
        struct Node* p = head;
        
        while(p->next!=NULL)
            p = p->next;
        
        p->next = ptr;
        ptr->next = NULL;

        printf("Inserted %d at index %d.\n", data, index);
        N++; 
        return head;
    }
    else
    {
        if(index > N)
        {
            printf("Invalid index!\n");
            return head;
        }
        else
        {
            struct Node* p = head;

            int i = 0;
            while(i != index - 1)
            {
                p = p->next;
                i++;
            }

            ptr->data = data;
            ptr->next = p->next;
            p->next = ptr;

            printf("Inserted %d at index %d.\n", data, index);
            N++; 
            return head;
        }
    }
}

struct Node* delete(struct Node* head, int index)
{
    struct Node* ptr = head;
    struct Node* qtr = head->next;
    if(index == 0) // delete first node
    {
        printf("Deleted node with value %d at index %d.\n", ptr->data, index);
        head = head->next;
        free(ptr);
        N--;
        return head;
    }
    else if(index == N - 1) // delete last node
    {
        while(qtr->next != NULL)
        {
            ptr = ptr->next;
            qtr = qtr->next;
        }
        printf("Deleted node with value %d at index %d.\n", qtr->data, index);
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
            while(i!=index-1)
            {
                ptr = ptr->next;
                qtr = qtr->next;
                i++;
            }
            printf("Deleted node with value %d at index %d.\n", qtr->data, index);
            ptr->next = qtr->next;
            free(qtr);
            N--;
            return head;
        }
    }
}
void show(struct Node* ptr)
{
    int i = 0;
    if(N!=0)
    {
        printf("The linked list's data is:\n");
        while(ptr!=NULL)
        {
            printf("%d at %d.\n", ptr->data, i);
            ptr = ptr->next;
            i++;
        }
    }
    else
        printf("The linked list is empty!\n");
    
}
int main()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));

    // Taking user input
    start: //goto
    printf("Enter the operation:\n");
    printf("1: To create a linked list.\n");
    printf("2: To insert a new node.\n");
    printf("3: To delete a node.\n");
    printf("4: To display linked list.\n");
    printf("5: To exit.\n");

    int x;
    scanf("%d", &x);
    switch (x)
    {
        case 1:
        {
            printf("Enter the data: ");
            int data;
            scanf("%d", &data);
            head->data = data;
            head->next = NULL;
            N++;
            printf("\n");
            goto start;
            break;
        }
        case 2:
        {
            int index, data;
            printf("Enter the index: ");
            scanf("%d", &index);
            printf("Enter the data: ");
            scanf("%d", &data);
            head = insert(head, data, index);
            printf("\n");
            goto start;
            break;
        }
        case 3:
        {
            int index;
            printf("Enter the index: ");
            scanf("%d", &index);
            head = delete(head, index);
            printf("\n");
            goto start;
            break;
        }
        case 4:
        {
            show(head);
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
