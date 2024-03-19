#include <stdio.h>

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

class ListNode
{

public:
    int item;
    ListNode *next;
};

class LinkedListWithTail
{

    ListNode *head;
    ListNode *tail;
    int length;

public:
    LinkedListWithTail()
    {
        head = NULL;
        length = 0;
    }

    int getLength() const
    {
        return length;
    }

    int insertItem(int item)
    {

        ListNode *newNode = new ListNode();
        newNode->item = item;


        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            ListNode *temp;
            temp=head;
            while(temp->next !=NULL)
            {
                temp = temp->next;
            }
            temp->next=newNode;
        }

        length++;
        return SUCCESS_VALUE;
    }

    int deleteItem(int item)
    {
        ListNode *temp;
        ListNode *previous = NULL;

        temp = head;
        if(head == NULL)
        {
            printf("Nothing to delete.\n\n");
        }
        else if(getLength() == 1)
        {

            printf("deleted The List \n\n");
            delete(temp);
            head = NULL;


        }
        else
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            printf("%d deleted\n\n",temp->next->item);
            delete(temp->next);
            temp->next = NULL;
        }



        length--;
        return SUCCESS_VALUE;
    }

    ListNode *searchItem(int item) const
    {
        ListNode *temp = head;

        while (temp != NULL)
        {
            if (temp->item == item)
            {
                return temp;
            }

            temp = temp->next;
        }

        return NULL;
    }

    void printList() const
    {
        ListNode *temp = head;

        while (temp != NULL)
        {
            printf("%d->", temp->item);
            temp = temp->next;
        }

        printf("\n");
        printf("Length: %d\n", getLength());
    }


    int insertLast(int item)
    {
        ListNode *newTail = new ListNode();
        newTail->item = item;
        tail->next = newTail;
        tail = newTail;
        return SUCCESS_VALUE;
    }

    ListNode *getItemAt(int position) const
    {
        ListNode *tmp = head;
        while (position--)
        {
            if (tmp == NULL)
                return NULL;
            tmp = tmp->next;
        }
        return tmp;
    }

    int deleteLast()
    {
        if (head == NULL)
            return NULL_VALUE;
        if (head->next == NULL)
        {
            delete (head);
            head = tail = NULL;
            return SUCCESS_VALUE;
        }
        ListNode *tmp = head;
        while (tmp->next->next != NULL)
            tmp = tmp->next;
        delete (tmp->next);
        tmp->next = NULL;
        tail = tmp;
        return SUCCESS_VALUE;
    }


    ~LinkedListWithTail()
    {
        while (deleteLast() != NULL_VALUE)
        {

        }
    }
};

int main(void)
{
    LinkedListWithTail ll;
    int choice, item;

    while (1)
    {
        printf("1. Insert item \n2. Inset item (Last)\n");
        printf("3. Delete item (Last)\n4. Delete item\n");
        printf("5. Search item\n6. Get item at\n7. Print list\n8. exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nEnter item: ");
            scanf("%d", &item);

            ll.insertItem(item);
        }
        else if (choice == 2)
        {
            printf("\nEnter item: ");
            scanf("%d", &item);

            ll.insertLast(item);
        }
        else if (choice == 3)
        {
            if (ll.deleteLast() == NULL_VALUE)
            {
                printf("\nDeletion failed\n");
            }
            else
            {
                printf("\nDeletion successful\n");
            }
        }
        else if (choice == 4)
        {


            ll.deleteItem(item);

        }
        else if (choice == 5)
        {
            printf("\nEnter item: ");
            scanf("%d", &item);

            ListNode *returnNode = ll.searchItem(item);

            if (returnNode != NULL)
            {
                printf("\nItem found\n");
            }
            else
            {
                printf("\nItem not found\n");
            }
        }
        else if (choice == 6)
        {
            int position;

            printf("\nEnter position: ");
            scanf("%d", &position);

            ListNode *returnNode = ll.getItemAt(position);

            if (returnNode->item != NULL_VALUE)
            {
                printf("\nItem found: %d\n", returnNode->item);
            }
            else
            {
                printf("\nItem not found\n");
            }
        }
        else if (choice == 7)
        {
            ll.printList();
        }
        else if (choice == 8)
        {
            break;
        }
        else
        {
            printf("\nInvalid choice\n");
        }

        printf("\n---------------------------------------------\n\n");
    }

    return 0;
}
