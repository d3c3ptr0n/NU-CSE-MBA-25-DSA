#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coefficient, exponent;
    struct Node *next;
};
int N;

// Insert operation
struct Node* insert(struct Node *head, int coefficient, int exponent)
{
    if (N == 0)
    {
        head->coefficient = coefficient;
        head->exponent = exponent;
        head->next = NULL;
        N++;
        return head;
    }
    else
    {
        // New node
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->coefficient = coefficient;
        ptr->exponent = exponent;
        ptr->next = NULL;

        struct Node *p = head;

        while (p->next != NULL)
            p = p->next;

        p->next = ptr;
        N++;
        return head;
    }
}

// Create operation
void create(struct Node* head, int n)
{
    int terms;
    N = 0;
    printf("Enter the details for polynomial %d:\n", n);
    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    for(int i = 1; i <= terms; i++)
    {
        int coefficient, exponent;
        printf("\n");
        printf("Enter coefficient for term %d: ", i);
        scanf("%d", &coefficient);
        printf("Enter exponent for term %d: ", i);
        scanf("%d", &exponent);

        head = insert(head, coefficient, exponent);
    }
}

// Show operation
void show(struct Node *ptr)
{
    int i = 0;
    if(N!=0)
    {
        while (ptr != NULL)
        {
            if(i==0)
            {
                if(ptr->exponent == 0)
                    printf("%d ", ptr->coefficient);
                else
                    printf("(%dx^%d) ", ptr->coefficient, ptr->exponent);
            }
            else
            {
                if(ptr->exponent == 0)
                    printf("+ %d ", ptr->coefficient);
                else
                    printf("+ (%dx^%d) ", ptr->coefficient, ptr->exponent);
            }
            ptr = ptr->next;
            i++;
        }
    }
    else
        printf("0");
}

// Add operation
void add(struct Node* head1, struct Node* head2)
{
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Final polynomial 
    struct Node* ptr3 = (struct Node*)malloc(sizeof(struct Node));

    N = 0;
    
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->exponent == ptr2->exponent)
        {
            int coefficient = ptr1->coefficient + ptr2->coefficient;
            ptr3 = insert(ptr3, coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->exponent > ptr2->exponent)
        {
            ptr3 = insert(ptr3, ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3 = insert(ptr3, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->next;
        }
    }
    while(ptr1!=NULL)
    {
        ptr3 = insert(ptr3, ptr1->coefficient, ptr1->exponent);
        ptr1 = ptr1->next;
    }
    while(ptr2!=NULL)
    {
        ptr3 = insert(ptr3, ptr2->coefficient, ptr2->exponent);
        ptr2 = ptr2->next;
    }

    printf("\n");
    printf("First polynomial: ");
    show(head1);
    printf("\n");
    printf("Second polynomial: ");
    show(head2);
    printf("\n");
    printf("Addition of both the polynomial is: ");
    show(ptr3);
    printf("\n");

}

// Subtract operation
void subtract(struct Node* head1, struct Node* head2)
{
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Final polynomial 
    struct Node* ptr3 = (struct Node*)malloc(sizeof(struct Node));

    N = 0;
    
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->exponent == ptr2->exponent)
        {
            int coefficient = ptr1->coefficient - ptr2->coefficient;
            ptr3 = insert(ptr3, coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->exponent > ptr2->exponent)
        {
            ptr3 = insert(ptr3, ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3 = insert(ptr3, -ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->next;
        }
    }
    while(ptr1!=NULL)
    {
        ptr3 = insert(ptr3, ptr1->coefficient, ptr1->exponent);
        ptr1 = ptr1->next;
    }
    while(ptr2!=NULL)
    {
        ptr3 = insert(ptr3, -ptr2->coefficient, ptr2->exponent);
        ptr2 = ptr2->next;
    }

    printf("\n");
    printf("First polynomial: ");
    show(head1);
    printf("\n");
    printf("Second polynomial: ");
    show(head2);
    printf("\n");
    printf("Subtraction of both the polynomial is: ");
    show(ptr3);
    printf("\n");
}

// Multiply operation
void multiply(struct Node* head1, struct Node* head2)
{
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Final polynomial 
    struct Node* ptr3 = (struct Node*)malloc(sizeof(struct Node));
    N = 0;

    while(ptr1!=NULL)
    {
        while(ptr2!=NULL)
        {
            int coefficient = ptr1->coefficient * ptr2->coefficient;
            int exponent = ptr1->exponent + ptr2->exponent;

            ptr3 = insert(ptr3, coefficient, exponent);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
        ptr2 = head2;
    }

    printf("\n");
    printf("First polynomial: ");
    show(head1);
    printf("\n");
    printf("Second polynomial: ");
    show(head2);
    printf("\n");
    printf("Multiplication of both the polynomial is: ");
    show(ptr3);
    printf("\n");
}
int main()
{
    // Equation 1
    struct Node *head1 = (struct Node *)malloc(sizeof(struct Node));

    // Equation 2
    struct Node *head2 = (struct Node *)malloc(sizeof(struct Node));

    // Taking details of both polynomials
    create(head1, 1);
    printf("\n\n\n");
    create(head2, 2);

    // Selecting operations 
    printf("\n\n");
    start: //goto
    printf("Enter the operation:\n");
    printf("1: To add.\n");
    printf("2: To subtract.(1st poly - 2nd poly)\n");
    printf("3: To multiply.\n");
    printf("4: To exit.\n");

    int x;
    scanf("%d", &x);
    switch (x)
    {
        case 1:
        {
            add(head1, head2);
            printf("\n");
            goto start;
            break;
        }
        case 2:
        {
            subtract(head1, head2);
            printf("\n");
            goto start;
            break;
        }
        case 3:
        {
            multiply(head1, head2);
            printf("\n");
            goto start;
            break;
        }
        case 4:
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