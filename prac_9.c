#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    long int phoneNumber;
    char contactName[15];
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(long int phoneNumber, char contactName[])
{
	struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->phoneNumber = phoneNumber;
	strcpy(ptr->contactName, contactName);
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

void ascendingTraversal(struct Node *root)
{
	if(root == NULL)
		return;

	ascendingTraversal(root->left);
	printf("\n");
	printf("Name: %s\n", root->contactName);
	printf("Phone Number: %ld\n", root->phoneNumber);
	ascendingTraversal(root->right);
}

void descendingTraversal(struct Node *root)
{
	if(root == NULL)
		return;
	descendingTraversal(root->right);
	printf("\n");
	printf("Name: %s\n", root->contactName);
	printf("Phone Number: %ld\n", root->phoneNumber);
	descendingTraversal(root->left);
}

struct Node *insertNode(struct Node *root, long int phoneNumber, char contactName[])
{
	if(root == NULL)
	{
		root = createNode(phoneNumber, contactName);
		return root;
	}
	else if(strcmp(contactName, root->contactName) < 0)
		root->left = insertNode(root->left, phoneNumber, contactName);
	else if(strcmp(contactName, root->contactName) > 0)
		root->right = insertNode(root->right, phoneNumber, contactName);

	return root;
}

struct Node *findMinNode(struct Node *root)
{
    while(root->left!=NULL)
        root = root->left;
    return root;
}

struct Node *deleteNode(struct Node* root, char contactName[])
{
	if(root == NULL)
		return root;
	else if(strcmp(contactName, root->contactName) < 0)
		root->left = deleteNode(root->left, contactName);
	else if(strcmp(contactName, root->contactName) > 0)
		root->right = deleteNode(root->right, contactName);
	else 
	{
		if(root->left == NULL && root->right == NULL)
		{
			struct Node *ptr = root;
			root = NULL;
			return root;
		}
		else if(root->left == NULL)
		{
			struct Node *ptr = root;
			root = root->right;
			free(ptr);
		}
		else if(root->right == NULL)
		{
			struct Node *ptr = root;
			root = root->left;
			free(ptr);
		}
		else
		{
			struct Node *ptr = findMinNode(root->right);
			root->phoneNumber = ptr->phoneNumber;
			strcpy(root->contactName, ptr->contactName);
			
			root->right = deleteNode(root->right, ptr->contactName);
		}
	}
	return root;
}

void searchNode(struct Node *root, char contactNumber[])
{
	if(root == NULL)
	{
		printf("\n");
		printf("Contact not found!\n");
		return;
	}
	else if(strcmp(contactNumber, root->contactName) == 0)
	{
		printf("\n");
		printf("Contact found!\n");
		printf("Name: %s\n", root->contactName);
		printf("Phone Number: %ld\n", root->phoneNumber);
		return;
	}
	else if(strcmp(contactNumber, root->contactName) < 0)
		searchNode(root->left, contactNumber);
	else
		searchNode(root->right, contactNumber);
}

int main()
{
	// root node
    struct Node *root = NULL;

	// Taking user input
    start: //goto
    printf("Enter the operation:\n");
    printf("1: To insert new contact.\n");
    printf("2: To delete a contact.\n");
    printf("3: To get a phone number of a contact.\n");
	printf("4: To print all the contacts in Ascending order.\n");
	printf("5: To print all the contacts in Descending order.\n");
    printf("6: To exit.\n");

    int x;
    scanf("%d", &x);
	getc(stdin);
    switch (x)
    {
        case 1:
        {
			char contactName[15];
            printf("Enter the name of the contact: ");
			gets(contactName);
			
			long int phoneNumber;
			printf("Enter the phone number of %s: ", contactName);
			scanf("%ld", &phoneNumber);
			
			root = insertNode(root, phoneNumber, contactName);
            
			printf("\n");
            goto start;
            break;
        }
		case 2:
		{
			char contactName[15];
            printf("Enter the name of the contact to be deleted: ");
			gets(contactName);

			root = deleteNode(root, contactName);
			
			printf("\n");
            goto start;
            break;

		}
		case 3:
		{
			char contactName[15];
			printf("Enter the name of the contact: ");
			gets(contactName);

			searchNode(root, contactName);

			printf("\n");
            goto start;
            break;
		}
		case 4:
		{
			ascendingTraversal(root);
			printf("\n");
            goto start;
            break;
		}
		case 5:
		{
			descendingTraversal(root);
			printf("\n");
            goto start;
            break;
		}
		case 6:
		{
			return 0;
			break;
		}
        default:
        {
            printf("\n");
            goto start;
        }
    }
    return 0;
}