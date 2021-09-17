#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Stack 
{
    int size, top;
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

// Checks precedence of given operator
int precedence(char val)
{
    if(val == '*' || val == '/')
        return 2;
    else if(val == '+' || val == '-')
        return 1;
    return 0;
}

// Checks if given character is an operator or not
int isOperator(char val)
{   
    if(val == '*' || val == '/' || val == '+' || val == '-')
        return 1;
    return 0;
}

// Converts infix expression to postfix
char* infixToPostfix(char* infix, struct Stack* ptr)
{
    char* postfix = (char*)malloc(sizeof(char)*strlen(infix)+1); // +1 for string literal '\0'
    int i = 0, j = 0; //i->>infix tracking, j->>postfix tracking
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            if(infix[i]=='(')
            {
                push(ptr, infix[i]);
                i++;
            }
            else if(infix[i] == ')')
            {
                while(ptr->top != -1 && ptr->array[ptr->top]!='(')
                {
                    postfix[j] = pop(ptr);
                    j++;
                }
                if(ptr->top != -1)
                    pop(ptr); // To pop '('
                i++;
            }
            else
            {
                postfix[j] = infix[i];
                j++; i++;
            }  
        }
        else
        {
            if(precedence(infix[i])>precedence(ptr->array[ptr->top]))
            {
                push(ptr, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(ptr);
                j++;
            }
        }
    }

    // passing remaining elements from stack to postfix array
    while(ptr->top!=-1)
    {
        postfix[j] = pop(ptr);
        j++;
    }

    postfix[j] = '\0';
    return postfix;
}

int main()
{
    // Taking infix expression
    char expression[20];
    printf("Enter the infix expression: ");
    gets(expression);

    // Creating the Stack
    struct Stack s;
    s.size = 30;
    s.top = -1;
    s.array = (char*)malloc(sizeof(char)*s.size);

    // Output  
    printf("\n");
    printf("Infix expression: %s\n", expression);
    printf("Postfix expression: %s\n", infixToPostfix(expression, &s));
    return 0;
}
