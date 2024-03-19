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
    if (rear == n-1)
        cout<<"Queue is full \n"<<endl;
    else
    {
        if( front == -1)
            front = 0;
        rear++;
        A[rear] = elem;
    }
}
void dequeue ( )
{
    if( isempty() )
        cout<<"Queue is empty\n"<<endl;
    else if( front == rear )
        front = rear = -1;
    else
        front++;
}

void peek(){
    if( isempty())
        cout<<"Queue is empty\n"<<endl;
    else
        cout<<"Front:"<<A[front]<<"\n"<<endl;
}

void display(){
    if(isempty()){
        cout<<"Queue is empty\n"<<endl;
    }
    else
    {
        for( int i=front ; i<= rear ; i++)
            cout<<A[i]<<" ";
        cout<<"\n";
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
	cout << " Queue size" << endl;
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
