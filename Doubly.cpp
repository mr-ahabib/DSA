#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node node;

int menu();
node* insert_head(node *head, node *nn);
node* insert_tail(node *head, node *nn);
node* createNode();
node* InsertItem(node *head, node *nn, int pos);
node* delete_head(node *head);
node* delete_DLLLast(node *head);
void printList(node *head);
void printReverse(node *head);

int node_counter = 0;

int main()
{
    node *head = NULL, *nn;
    int ch, pos;
    ch = menu();

    while(ch)
    {
        if(ch == 1)
        {
            nn = createNode();
            head = insert_head(head, nn);
        }
        else if(ch == 2)
        {
            printf("enter position: ");
            scanf("%d",&pos);
            if(pos >= 1 && pos <= node_counter+1)
            {
                nn = createNode();
                head = InsertItem(head, nn, pos);
            }
            else
            {
                printf("invalid position.\n\n");
            }
        }

        else if(ch == 3)
        {
            head = delete_DLLLast(head);
        }

         else if(ch == 4)
        {
            printList(head);

        }

        else if(ch == 5)
        {
            printReverse(head);

        }
        else
        {
            printf("invalid choice.\n\n");
        }
        ch = menu();
    }
}


int menu()
{
    int ch;
    printf("1. InsertFirst\n");
    printf("2. InsertItem\n");
    printf("3. DeleteLast\n");
    printf("4. printList\n");
    printf("5. print list reverse\n");
    printf("0. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    return ch;
}

node* createNode()
{
    node *temp;
    temp = new node();
    printf("enter value: ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

node* insert_head(node *head, node *nn)
{
    if(head != NULL)
    {
        nn->next = head;
        head->prev = nn;

    }
    head = nn;

    node_counter++;
    return head;
}

void printList(node *head)
{
    node *temp;
    temp = head;

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

void printReverse(node *head)
{
    node *temp;
    temp = head;
    while(temp->next!=NULL)
        {
            temp = temp->next;
        }

        while(temp!=NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->prev;
        }
      printf("\n\n");
}


node* InsertItem(node *head, node *nn, int pos)
{
    if(pos == 1)
    {
        head = insert_head(head, nn);
    }
    else if(pos == node_counter+1)
    {
        head = insert_tail(head, nn);
    }
    else
    {
        node *temp;
        temp = head;

        while(pos-2 > 0)
        {
            temp = temp->next;
            pos--;
        }
        nn->next = temp->next;
        temp->next = nn;
        nn->prev=temp;
        nn->next->prev = nn;
        node_counter++;
    }


    return head;
}

node* insert_tail(node *head, node *nn)
{
    if(head == NULL)
    {
        head = insert_head(head, nn);
    }
    else
    {
        node *temp;
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        nn->prev = temp;
        temp->next = nn;
        node_counter++;
    }

    return head;
}

node* delete_head(node *head)
{
    if(head == NULL)
    {
        printf("nothing to delete.\n\n");
    }
    else
    {
        node *temp;
        temp = head;
        head = head->next;
        head->prev = NULL;
        printf("%d deleted\n",temp->data);
        delete(temp);
        node_counter--;
    }

    return head;
}

node* delete_DLLLast(node *head)
{
    if(node_counter < 2)
    {
        head = delete_head(head);
    }
    else
    {
        node *temp;
        temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        printf("%d deleted\n",temp->next->data);
        delete(temp->next);
        temp->next = NULL;
        node_counter--;
    }
    return head;
}

