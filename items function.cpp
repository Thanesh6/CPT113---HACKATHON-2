#include <iostream>
#include "Items.h"
using namespace std;

Items::Items()
{
	head = nullptr;
	coin = 0;
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
}


void Items::Display() {
    Node* nodeptr = head;
   cout << "Coin = " << coin << endl;
    if (isEmpty()) {
        cout << "The inventory is empty!" << endl;
        return;
    } else {
        while (nodeptr) {
        	int num = 0;
        	int code;
    			do{
    				code = nodeptr->code;
    				nodeptr = nodeptr->next;
    				num++;
				}while (nodeptr->code == code);
		cout << item[code-1]<<" : "<<num<<endl;
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
		cout << "\nWelcome to the Shake of Sugar Boom!!"<<endl;
		cout << "-------------------------------------"<<endl;
		for(int i=0;i<3;i++)
		{
			cout << item[i]<<" : "<<price[i]<<endl;
		}

}



