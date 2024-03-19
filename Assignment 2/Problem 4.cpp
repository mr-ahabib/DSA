#include <bits/stdc++.h>
using namespace std;
int n;
int A[100];
int front = -1;
int rear = -1;
bool isempty()
{
    if(front == -1 && rear == -1)
        return 1;
    else
        return 0;
}
void enqueue( int elem )
{
    if ((rear+1)%n ==front)
        cout<<"Queue is full \n"<<endl;
    else
    {
        if( front == -1)
            front = 0;
        rear=(rear+1)%n;
        A[rear] = elem;
    }
}
int dequeue ( )
{
    int element;
    if (isempty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    else
    {
        element = A[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) %n;
        }
        return element;
    }

}

void peek()
{
    if( isempty())
        cout<<"Queue is empty\n"<<endl;
    else
        cout<<"Front:"<<A[front]<<"\n"<<endl;
}

void display(){
    if(isempty())
        cout<<"Queue is empty\n";
    else
    {
        int i;
        if( front <= rear )
        {
            for( i=front ; i<= rear ; i++)
                cout<<A[i]<<" "<<endl;
        }
        else
        {
            i=front;
            while( i <n)
            {
                cout<<A[i]<<" "<<endl;
                i++;
            }
            i=0;
            while( i <= rear)
            {
                cout<<A[i]<<" "<<endl;
                i++;
            }
        }
    }
}

int menu()
{
    int ch;
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.isEmpty\n");
    printf("4.Peek\n");
    printf("5.Display\n");

    printf("6. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}
int main()
{
    int choice;
    cout << " Queue size: ";
    cin >> n;
    int A[n];
    choice = menu();
    while (choice != 6)
    {
        if (choice == 1)
        {
            int a;
            cout << "\n Enter push :" << endl;
            cin >> a;
            enqueue(a);

        }
        else if (choice == 2)
        {

            dequeue();
        }
        else if (choice == 3)
        {

            cout<<isempty()<<endl;

        }
        else if (choice == 4)
        {
            peek();

        }
        else if (choice == 5)
        {

            display();
        }
        else
        {
            printf("Invalid choice. Please try again...\n\n");
        }

        choice = menu();
    }

}

