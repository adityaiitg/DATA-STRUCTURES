#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void append(int);
void display();
void addbeg(int);
void sum();
int search(int);
void remov(int);

int main()
{
    int n, ch;
    do
    {
        printf("\nOperation on Link List");
        printf("\n1. Append\n2. Add at beginning\n3. Display\n4. Sum of list\n5. Search \n6. Delete \n0. Exit");
        printf("\nEnter Choice 0-6? : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter number ");
                scanf("%d", &n);
                append(n);
                break;
            case 2:
                printf("\nEnter number ");
                scanf("%d", &n);
                addbeg(n);
                break;
            case 3:
                display();
                break;
            case 4:
                sum();
                break;
            case 5:
                {
                    int x, index;
                    printf("\nEnter number you want to search ");
                    scanf("%d", &x);
                    index = search(x);
                    if (index ==  - 1)
                    {
                        printf("\nItem not found");
                    }
                    else
                    {
                        printf("Item found at position %d", index);
                    }
                    break;
                }
            case 6:
                {
                    int x;
                    printf("\nEnter number you want to delete ");
                    scanf("%d", &x);
                    remov(x);
                }
        }
    }while (ch != 0);
}

void append(int item)
{
    struct node *nptr = malloc(sizeof(struct node));
    nptr->data = item;
    nptr->next = NULL;
    if (start == NULL)
    {
        start = nptr;
    } 
    else
    {
        struct node *temp;
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        } temp->next = nptr;
    }
}


void addbeg(int item)
{
    struct node *nptr = malloc(sizeof(struct node));
    nptr->data = item;
    nptr->next = start;
    start = nptr;
}


void display()
{
    struct node *temp;
    temp = start;
    if (temp == NULL)
    {
        printf("link list is empty");
    } 
    while (temp != NULL)
    {
        printf("%d : ", temp->data);
        temp = temp->next;
    }
}

void sum()
{
    int sum = 0;
    struct node *temp;
    temp = start;
    while (temp != NULL)
    {
        sum = sum + temp->data;
        temp = temp->next;
    } printf("sum of elements :%d", sum);
}

int search(int item)
{
    int loc = 0;
    struct node *temp;
    temp = start;
    while (temp != NULL)
    {
        loc++;
        if (temp->data == item)
        {
            return loc;
        } temp = temp->next;
    }
    return  - 1;
}



void remov(int item)
{
    struct node *temp,  *old;
    temp = start;
    while (temp != NULL)
    {
        if (temp->data == item)
        {
            if (temp == start)
            {
                start = temp->next;
            } 
            else
                old->next = temp->next;
            printf("\n%d ttem deleted\n",temp->data);
            free(temp);
            return ;
        }
        else
        {
            old = temp;
            temp = temp->next;
        }
    }
    printf("Item not found ");
}