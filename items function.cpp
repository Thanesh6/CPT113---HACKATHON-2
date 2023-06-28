#include <iostream>
#include "items.h"
#include<ctime>
#include<cstdlib>
#include<fstream>
using namespace std;

Items::Items()
{
  head = nullptr;
  coins = 0;
  num = 0;
}

void Items ::clear()
{
    Node *nodeptr = nullptr,*temp = nullptr;
    nodeptr = head;
    while (nodeptr) {
        nodeptr->next = temp;
        delete nodeptr;
        nodeptr = temp;
    }
}
bool Items::isEmpty() {
    return (head == nullptr);
}
Items::~Items() {
  clear();
}

bool Items:: checkValidInt(string d) {
    bool status = true;
    for (char c: d) {
      if (!isdigit(c)) {
        status = false;
        break;
      }
    }
    return status;
  }

void Items::Insert(int code) {
    Node* newNode = new Node;
    newNode->code = code;
    newNode->next = nullptr;

    if (isEmpty()) {
        head = newNode;
    } else if (code < head->code) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* nodeptr = head;
        while (nodeptr->next && code >= nodeptr->next->code) {
            nodeptr = nodeptr->next;
        }
        newNode->next = nodeptr->next;
        nodeptr->next = newNode;
    }
    num++;
}


void Items::Display() {
    Node* current = head;
    cout << "\n-----------"<<endl;
    cout << "Inventory"<<endl;
    cout << "-----------"<<endl;
   cout << "Coin = " << coins << endl;
   int j=1;
   cout << "Number of items= "<<num<<endl;
    if (isEmpty()) {
        cout << "The inventory is empty!" << endl;
        return;
    } else {
         
        	for(int i=0;i<3;i++)
        	{
        		
        		int num =0;
        		while (current != NULL && (current->code)==j)
        		{
        			num++;
        			current = current->next;
				}
				cout << item[i]<<" : "<< num<<endl;
				j++;
}
}
}

void Items::Display2P() {
    Node* current = head;
    cout << "   -----------"<<endl;
    cout << "   Inventory"<<endl;
    cout << "   -----------"<<endl;
   int j=1;
    if (isEmpty()) {
        cout << "   The inventory is empty!" << endl;
        return;
    } else {
         
        	for(int i=0;i<3;i++)
        	{
        		
        		int num =0;
        		while (current != NULL && (current->code)==j)
        		{
        			num++;
        			current = current->next;
				}
				cout << "   "<<item[i]<<" : "<< num<<endl;
				j++;
}
}
}
void Items::Check(int code) {
    Node* current = head;
    int count = 0;
    if(isEmpty())
    {
      cout << "The inventory is empty"<<endl;
      return;
  }
    while (current) {
        if (current->code == code) {
            count++;
        }
        current = current->next;
    }
    cout << "You have " << count << " of the "  <<item[code-1]<<endl;
}

void Items::Delete(int code) {
    if (isEmpty()) {
        cout << "The inventory is empty!" << endl;
        return;
    } else if (head->code == code) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    } else {
        Node* current = head;
        while (current->next) {
            if (current->next->code == code) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }
    num--;
}

void Items :: SetMenu(){

  item[0]="HP+10";
  item[1]="Attack+10";
  item[2]="Revive stone";
  price[0]=10;
  price[1]=10;
  price[2]=100;
}


void Items :: DisplayMenu()const{
	cout << "\n-------------------------------------"<<endl;
    cout << "Welcome to the Shake of Sugar Boom!!"<<endl;
    cout << "-------------------------------------"<<endl;
    cout << "0. quit"<<endl;
    for(int i=0;i<3;i++)
    {
      cout << i+1<<". "<<item[i]<<" : "<<price[i]<<endl;
    }
    cout << "99. check inventory"<<endl;

}
int Items :: itemDrop(int a)
{
	
}
void Items ::randomDrop(int &a)
{
	unsigned seed = time(0);
	srand(seed);
	int probability = rand()%100;
	switch(probability)
	{
		case 0 ... 4 : 
			Insert(3);
			cout <<item[2]<<" has dropped!!"<<endl<<endl;
			a=3;
			break;
		case 5 ... 20 :
			Insert(2);
			cout <<item[1]<<" has dropped!!"<<endl<<endl;
		a=2;
			break;
		case 21 ... 60 :
			Insert(1);
			cout <<item[0]<<" has dropped!!"<<endl<<endl;
		a=1;
			break;
		default :
			cout <<" Nothing has dropped!!"<<endl<<endl;
			break;
			}
}

void Items :: enterShop(int &c, int& d)
{
	                // Visit the item shop after clearing every 5 levels
                string a;
                int choice;
                coins += 100;
                do{
                	DisplayMenu();
                		cout << "Enter the item code you want to buy (1-3) or 0 to skip: ";
                		cin >> a;
                	while(!checkValidInt(a))
                	{
                		cout << "Please enter an integer!!!!"<<endl;
                		DisplayMenu();
                		cout << "Enter the item code you want to buy (1-3) or 0 to skip: ";
                		cin >> a;	
					}

					choice = stoi(a);
                if (choice >= 1 && choice <= 3) {
                    if (coins >= price[(choice-1)]) {
                       coins -= price[(choice-1)];
                    	Insert(choice);
                    	if(choice==1)
                    	{
                    		c+=1;
						}
						else if(choice==2)
						{
							d+=2;
						}
                        cout << "Congratulations! You purchased the item." << endl;
                    } else {
                        cout << "Insufficient coins. Cannot purchase the item." << endl;
                    }
                } 
				
				else if(choice==99)
				{
					Display();
				}
				else if(choice==0)
					break;
				else {
                    cout << "Invalid input." << endl;
                }
            }while(choice!=0);
}

bool Items :: ableRevive()
{
	Node *nodeptr = nullptr;
	nodeptr = head;
	while(nodeptr)
	{
		if(nodeptr->code=3)
		{
			return true;
		}
		nodeptr = nodeptr->next;
	}
	
	return false;
}

//void Items::intoArray(int *arr)
//{
//	Node *nodeptr=nullptr;
//	nodeptr = head;
//	for(int i=0;i<num;i++)
//	{
//		arr[i]=nodeptr->code;
//		nodeptr=nodeptr->next;
//	 } 
//}

int Items::getNum()
{
	return num;
}

int Items::copyValue(int count)
{
	Node *nodeptr=nullptr;
	nodeptr = head;
	for(int i=0;i<count;i++)
	{
		nodeptr=nodeptr->next;
	}
	return nodeptr->code;
}

void Items::saveItems()
{
	Node *nodeptr=nullptr;
	nodeptr=head;
	fstream outFile;
	outFile.open("Items.txt",ios::out);
	while(nodeptr != nullptr)
	{
		outFile<<nodeptr->code<<"  ";
		nodeptr=nodeptr->next;
	}
	outFile.close();
	}

void Items::loadItems()
{
	Node *newNode = nullptr,*nodeptr;
	nodeptr=head;
	int code;
	fstream inFile;
	inFile.open("Items.txt",ios::in);
	while(inFile>>code)
	{
	 	Insert(code);
	}
}
