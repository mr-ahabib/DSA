#include<iostream>
using namespace std;
int n,capacity=0;
struct Queue
{
    int front, rear, capacity;
    int* queue;
    Queue(int c)
    {
        front = rear = 0;
        capacity = c;
        queue = new int;
    }

    Queue()
    {
        delete[] queue;
    }

    void Enqueue ( int elem )
    {
        if (rear == SIZE-1)
            cout<<"Queue is full \n";
        else
        {
            if( front == -1)
                front = 0;
            rear++;
            A[rear] = value;
        }
    }
    void Dequeue()
    {
        if( isempty() )
            cout<<"Queue is empty\n";
        else if( front == rear )
            front = rear = -1;
        else
            front++;
    }
    void Display()
    {
        if(isempty())
            cout<<"Queue is empty\n";
        else
        {
            for( int i=front ; i<= rear ; i++)
                cout<<A[i]<<" ";
            cout<<"\n";
        }

        bool isempty()
        {
            if(front == -1 && rear == -1)
                return 1;
            else
                return 0;
        }

        int Peek()
        {
            if( isempty())
                cout<<"Queue is empty\n";
            else
                cout<<"element at front is:"<<A[front]<<"\n";
        }
    };

    int menu()
    {
        int ch;
        cout<<"1.Enqueue\n"<<endl;
        cout<<"2.Dequeue\n"<<endl;
        cout<<"3.Peek\n"<<endl;
        cout<<"4.is Empty\n"<<endl;
        cout<<"5.Display\n"<<endl;

        cout<<"6. Exit\n\n"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>ch;
        return ch;
    }
    int main()
    {
        Queue q;
        int  choice,rear=0;

        cout << " Queue size" << endl;
        cin >> n;
        int stack[n];
        choice = menu();
        while (choice != 6)
        {
            if (choice == 1)
            {
                int a;
                cout << "\n Enque value :" << endl;
                cin >> a;

                q.Enqueue(a);
                rear++;

            }
            else if (choice == 2)
            {

                q.Dequeue();
                rear--;
            }
            else if (choice == 3)
            {

                cout<<q.isEmpty()<<endl;

            }
            else if (choice == 4)
            {
                cout<<q.Peek()<<endl;

            }
            else if (choice == 5)
            {

                q.Display();
            }
            else
            {
                printf("Invalid choice. Please try again...\n\n");
            }

            choice = menu();
        }

    }
