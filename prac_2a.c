#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Stack Structure
struct Stack 
{
    int top;
    int size;
    char* array;
};

// Push operation
void push(struct Stack* ptr, char val)
{
    if(ptr->top == ptr->size-1)
        printf("Stack Overflow!!\n");
    else
    {
        ptr->top++;
        ptr->array[ptr->top] = val;
    }
}

// Pop operation
char pop(struct Stack* ptr)
{
    if(ptr->top <= -1)
        printf("Stack Underflow!!\n");
    else
    {
        char val = ptr->array[ptr->top];
        ptr->top--;
        return val;
    }
}

int main()
{
    // Taking input
    char str[20];
    printf("Enter a string: ");
    gets(str);

    // Stack declaration
    struct Stack s;
    s.top = -1;
    s.size = 30;
    s.array = (char*)malloc(sizeof(char)*s.size);

    // Pushing data to Stack
    for(int i = 0; i < strlen(str); i++)
        push(&s, str[i]);
    
    // Reversing the string using Stack
    char* ans;
    ans = (char*)malloc(sizeof(char)*strlen(str));
    for(int i = 0; i < strlen(str); i++)
        ans[i] = pop(&s);

    // Output
    printf("\n");
    printf("The original string is: %s\n", str);
    printf("The reversed string is: %s\n", ans);
    return 0;
}