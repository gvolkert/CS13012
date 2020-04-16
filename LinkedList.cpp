//
//  Examole of a simple linked list
//
#include<iostream>
using namespace std;

struct node
{
	int nodeData;
//	char moreNodeData;
	node *next;	
};

class list
{
	public:
		list();
        void createnode(int value);
        void insert_start(int value);
        void delete_position(int pos);
        void display();
        void insert_start(int value);
        void insert_position(int pos, int value);
        void delete_first();
        void delete_last();
        void delete_position(int pos);
        
	private:
		node *head;
        node *tail; 
};

list::list(){

	head = NULL;
	tail = NULL;
}

void list::createnode(int value){

    node *temp = new node;
    temp->nodeData = value;
    temp->next = NULL;
    if(head =  = NULL){
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else{	
        tail->next = temp;
        tail = temp;
    }
}


void list::display()
{
    node *temp = new node;
    temp = head;
    while(temp! = NULL){
        cout<<temp->nodeData<<"\t";
        temp = temp->next;
    }
}

void list::insert_start(int value)
{
    node *temp = new node;
    temp->nodeData = value;
    temp->next = head;
    head = temp;
}


void list::insert_position(int pos, int value)
{
    node *pre = new node;
    node *cur = new node;
    node *temp = new node;
    cur = head;
    for(int i = 1;i<pos;i++){
        pre = cur;
        cur = cur->next;
    }
    temp->nodeData = value;
    pre->next = temp;	
    temp->next = cur;
}


void list::delete_first()
{
    node *temp = new node;
    temp = head;
    head = head->next;
    delete temp;
}


void list::delete_last()
{
    node *current = new node;
    node *previous = new node;
    current = head;
    while(current->next! = NULL){
        previous = current;
        current = current->next;	
    }
    tail = previous;
    previous->next = NULL;
    delete current;
}


void list::delete_position(int pos)
{
    node *current = new node;
    node *previous = new node;
    current = head;
    for(int i = 1;i<pos;i++){
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
}


int main()
{
	list obj;
    int nodeValue;
    int nodePosition;
	char continueAnswer;
    
    
    cout << "enter integer value for node or -1 to quit: ";
    cin >> nodeValue;
    
    while( !(nodeValue == -1) ){
    
    	obj.createnode(nodeValue);
        
        cout << "enter integer value for linked-list node or -1 to stop adding nodes: ";
        cin >> nodeValue;
    }
	
    do{
		cout<<"\n--------------------------------------------------\n";
		cout<<"---------------Displaying All nodes---------------";
		cout<<"\n--------------------------------------------------\n";
		obj.display();
		
		
		cout<<"\n--------------------------------------------------\n";
		cout<<"-----------------Inserting At End-----------------";
		cout<<"\n--------------------------------------------------\n";
		
		cout << "enter integer value for new node at end: ";
		cin >> nodeValue;
		
		obj.createnode(nodeValue);
		obj.display();
		
		cout<<"\n--------------------------------------------------\n";
		cout<<"----------------Inserting At Start----------------";
		cout<<"\n--------------------------------------------------\n";
		
		cout << "enter integer value for new node at start: ";
		cin >> nodeValue;
		
		obj.insert_start(nodeValue);
		obj.display();
		
		
		cout<<"\n--------------------------------------------------\n";
		cout<<"--------Inserting At Particular Position-----------";
		cout<<"\n--------------------------------------------------\n";
		
		cout << "enter index of node to insert at: ";
		cin >> nodePostion;
		
		cout << "enter integer value for new node: ";
		cin >> nodeValue;
		
		obj.insert_position(nodePosition, nodeValue);
		obj.display();
		
		
		cout<<"\n--------------------------------------------------\n";
		cout<<"----------------Deleting At Start-----------------";
		cout<<"\n--------------------------------------------------\n";
		
		obj.delete_first();
		obj.display();
		
		cout<<"\n--------------------------------------------------\n";
		cout<<"-----------------Deleing At End-------------------";
		cout<<"\n--------------------------------------------------\n";
		
		obj.delete_last();
		obj.display();
		
		cout<<"\n--------------------------------------------------\n";
		cout<<"---------Deleting At Particular Position-----------";
		cout<<"\n--------------------------------------------------\n";
		
		cout << "enter index of node to delete: ";
		cin >> nodePostion;
		
		obj.delete_position(nodePosition);
		obj.display();
	
		cout<<"\n--------------------------------------------------\n";
		
		cout << "Would you like to continue? (y/n)";
		cin >> continueAnswer;
	}
	while( continueAnswer == 'y' )
	
	system("pause");
	return 0;
}