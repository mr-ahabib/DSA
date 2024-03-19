#include <bits/stdc++.h>
using namespace std;
  
  int n,len=0;
class Node
{
public:
	int elem;
	Node *link;

	Node(int n)
	{
		this->elem = n;
		this->link = NULL;
	}
};

class Stack
{
	Node *top;

public:
	Stack() { top = NULL; }

	void push(int elem)
	{

		Node *temp = new Node(elem);

		if (len>n)
		{
			cout << "\nStack Overflow\n";
			
		}else{
             temp->elem = elem;

		temp->link = top;
		top = temp;
		}
		
	}
	void sorts(){
		Node *temp;
		Node *x;
		int y;
		if (top == NULL)
		{
			cout << "\nStack Underflow.\n";
			exit(1);
		}
		else
		{
			temp = top;
		
			while (temp != NULL)
			{
				x=temp->link;

				while(x!=NULL){
					if(temp->elem <x->elem){
						y=temp->elem;
						temp->elem=x->elem;
						x->elem=y;

					}
					x=x->link;
				}

			temp=temp->link;
			}

		}
	}

	bool isEmpty()
	{
		if(top==NULL){
			return 1;
		}
		else{
			return 0;
		}
		
	}

	int peek()
	{
		if (!isEmpty()){
                 return top->elem;
		}else
			exit(1);
	}

	void pop()
	{
		Node *temp;

		if (top == NULL)
		{
			cout << "\nStack Underflow" << endl;
			exit(1);
		}
		else
		{

			temp = top;
			top = top->link;

			free(temp);
		}
	}

	void display()
	{
		Node *temp;
		if (top == NULL)
		{
			cout << "\nStack Underflow.\n";
			exit(1);
		}
		else
		{
			temp = top;
			while (temp != NULL)
			{

				cout << temp->elem;
				temp = temp->link;
				if (temp != NULL)
					cout << " -> ";
			}
		}
		cout<<endl;
	}
	
};

int menu()
{
	int ch;
	printf("1.PUSH\n");
	printf("2.POP\n");
	printf("3.isEmpty\n");
	printf("4. peek\n");
	printf("5.display\n");

	printf("6. Exit\n\n");
	printf("Enter your choice: ");
	scanf("%d", &ch);
	return ch;
}
int main()
{
	Stack s;
	int  choice,top;


	top = -1;
	cout << " Stack size" << endl;
	cin >> n;
      int stack[n];
	// cout << "1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT" << endl;

	choice = menu();
	while (choice != 6)
	{
		if (choice == 1)
		{
			int a;
			cout << "\n Enter push :" << endl;
			cin >> a;
			len++;
			s.push(a);
			
		}
		else if (choice == 2)
		{
            s.sorts();
			s.pop();
			len--;
		}
		else if (choice == 3)
		{

			cout<<s.isEmpty()<<endl;
			
		}
		else if (choice == 4)
		{
			s.sorts();
			cout<<s.peek()<<endl;

		}
		else if (choice == 5)
		{
            s.sorts();
			s.display();
		}
		else
		{
			printf("Invalid choice. Please try again...\n\n");
		}

		choice = menu();
	}

}