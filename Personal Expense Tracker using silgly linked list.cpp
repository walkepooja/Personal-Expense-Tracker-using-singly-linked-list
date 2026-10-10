#include<iostream>
using namespace std;


// Create Node Structure
struct Node
{
	string name;
	int amount;
	Node *next;
};

Node *head=NULL;

// Add  Expense
void addExpense()
{
	Node* newnode=new Node;
	
	cout<<"Enter expense Name:";
	cin>>newnode->name;
	
	cout<<"Enter amount:";
	cin>>newnode->amount;
	
	newnode -> next = head;
	head=newnode;
	
	cout<<"Expense added successfully \n:";
	
}

// Display Expense
void displayExpense()
{
	Node *temp=head;
	
	if(head==NULL)
	{
		cout<<"No Expense Found\n:";
		return;
	}
	while(temp!=NULL)
	{
		cout<<temp->name<<"Rs"<<temp->amount<<endl;
		temp=temp->next;
	}
}

//calculate total expense
void totalExpense()
{
	Node *temp=head;
	int total=0;
	
	while(temp!=NULL)
	{
		total=total+temp->amount;
		temp=temp->next;
	}
	cout<<"Total expense=Rs"<<total<<endl;
}

//Main function
int main()
{
	int choice;
	
	do
	{
		cout<<"\n Personal Expense Tracker \n:";
		cout<<"1.Add Expense \n:";
		cout<<"2.Display Expense \n:";
		cout<<"3.Total Expense \n:";
		cout<<"4.Exit \n:";
		
		cout<<"Enter your choice:";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				addExpense();
				break;
				
				case 2:
					displayExpense();
					break;
					
					case 3:
						totalExpense();
						break;
						 
						 case 4:
						 	cout<<"Thank You";
						 	break;
						 	
						 	default:
						 		cout<<"Invalid choice";
						 		
					
		}
    } while(choice!=4);
    return 0;
}

