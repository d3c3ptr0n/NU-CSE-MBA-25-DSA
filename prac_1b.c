#include <stdio.h>
#include<string.h>

// Declaring structure
struct students
{
    int id;
    char firstName[10], lastName[10];
    float cgpa;
};

// Displays given code
void display(struct students array[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Student ID: %d\n", (array+i)->id);
        printf("Name: %s %s\n", (array+i)->firstName, (array+i)->lastName);
        printf("CGPA: %f", (array+i)->cgpa);
        printf("\n\n");
    }
}

// Insert function
void insert_student(struct students array[], int n, int index, struct students insert)
{
    index--;
    for(int i = n-1; i > index; i--)
    {
        (array+i)->id = (array+i-1)->id;
        (array+i)->cgpa = (array+i-1)->cgpa; 
        strcpy((array+i)->firstName, (array+i-1)->firstName);
        strcpy((array+i)->lastName, (array+i-1)->lastName); 
    }
    (array+index)->id = insert.id;
    (array+index)->cgpa = insert.cgpa;
    strcpy((array+index)->firstName, insert.firstName);
    strcpy((array+index)->lastName, insert.lastName);
}

// Delete Function
void delete_student(struct students array[], int n, int index)
{
    index--;
    for(int i = index; i < n; i++)
    {
        (array+i)->id = (array+i+1)->id;
        (array+i)->cgpa = (array+i+1)->cgpa; 
        strcpy((array+i)->firstName, (array+i+1)->firstName);
        strcpy((array+i)->lastName, (array+i+1)->lastName); 
    }
}

// Update Function
void update_student(struct students array[], int index, struct students update)
{
    index--;
    (array+index)->id = update.id;
    (array+index)->cgpa = update.cgpa; 
    strcpy((array+index)->firstName, update.firstName);
    strcpy((array+index)->lastName, update.lastName);
}

int main()
{
    // Taking input
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    int size = n+1;
    struct students studentsArray[size];
    struct students *ptr = studentsArray;

    printf("\n\n");
    for(int i = 0; i < n; i++)
    {
        printf("Enter details for student %d:\n", i+1);
        printf("Enter the ID: ");
        scanf("%d", &(ptr+i)->id);
        printf("Enter the First Name: ");
        scanf("%s", &(ptr+i)->firstName);
        printf("Enter the Last Name: ");
        scanf("%s", &(ptr+i)->lastName);
        printf("Enter the CGPA: ");
        scanf("%f", &(ptr+i)->cgpa);
        printf("\n\n");
    }

    printf("The entered details are: \n\n");
    display(studentsArray, n);

    // Insert operation 
    printf("\n\n");
    int insertIndex;
    struct students insert;
    printf("Enter the Student number you want to insert: ");
    scanf("%d", &insertIndex);
    printf("Enter the ID: ");
    scanf("%d", &insert.id);
    printf("Enter the First Name: ");
    scanf("%s", &insert.firstName);
    printf("Enter the Last Name: ");
    scanf("%s", &insert.lastName);
    printf("Enter the CGPA: ");
    scanf("%f", &insert.cgpa);
    insert_student(studentsArray, size, insertIndex, insert);
    printf("The updated data is:\n\n");
    display(studentsArray, size);

    // Delete operation
    int deleteIndex;
    printf("Enter the Student number to be deleted: ");
    scanf("%d", &deleteIndex);
    delete_student(studentsArray, n, deleteIndex);
    printf("The updated data is:\n\n");
    display(studentsArray, n);
    
    // Update operation
    int updateIndex;
    struct students update;
    printf("Enter the Student number you want to update: ");
    scanf("%d", &updateIndex);
    printf("Enter the ID: ");
    scanf("%d", &update.id);
    printf("Enter the First Name: ");
    scanf("%s", &update.firstName);
    printf("Enter the Last Name: ");
    scanf("%s", &update.lastName);
    printf("Enter the CGPA: ");
    scanf("%f", &update.cgpa);
    update_student(studentsArray, updateIndex, update);
    printf("The updated data is:\n\n");
    display(studentsArray, n);
    
    return 0;
}