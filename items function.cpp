#include<iostream>
#include "Items.h"

using namespace std;

Items::Items(){
	head = nullptr;
}

void Items::Clear(){
	items *nodeptr = nullptr, *temp = nullptr;	
	
	nodeptr = head;
	if(isEmpty())
	{
		return;
	}
	
	else
	{
		while(nodeptr->next)
		{
			temp= nodeptr->next;
			delete nodeptr;
			nodeptr = temp;
		}
	}
}
Items::~Items(){
	Clear();
}

bool Items::isEmpty()
{
	if(head)
		return false;
	
	else
		return true;
}
void Items::Append(int a)
{
	items *nodeptr = nullptr, *newNode;
	
	newNode = new items;
	newNode->next = nullptr;
	newNode->code = a;
	nodeptr=head;
	if(isEmpty()) {
		head = newNode;
	} else {
		while(nodeptr->next) {
			nodeptr = nodeptr->next;
		}
		
		nodeptr->next = newNode;
	}
}



void Items::Display()
{
	items *nodeptr=nullptr;
	
	nodeptr = head;
	if(isEmpty())
	{
		cout << "The inventory is empty!"<<endl;
		return;
	}
	
	else
	{
		while(nodeptr)
		{
			cout << nodeptr->code<<endl;
			nodeptr = nodeptr->next;
		}
	}
}

void Items::Check(int a)
{
	items *nodeptr=nullptr;
	int num;
	
	nodeptr = head;

	if(isEmpty())
	{
		cout << "Your inventory is empty!"<<endl;
		return;
	}
	
	else
	{
		while(nodeptr->next)
		{
			if(nodeptr->code == a)
				{
					num ++;
				}
			nodeptr = nodeptr->next;
		}
		
		cout << "You have "<<num<<" of the item."<<endl;
		
	
	}
}

void Items::Delete(int a)
{
	items *nodeptr = nullptr, *temp = nullptr;
	bool found=false;
	
	nodeptr = head;
	temp = nodeptr;
	if(isEmpty())
	{
		cout << "The inventory is empty!"<<endl;
		return;
	}
	
	else
	{
		if(nodeptr->code == a)
		{
			head = nodeptr->next;
			delete nodeptr;
		}
		
		else
		{
			while(nodeptr)
			{
				temp = nodeptr->next;
				if(temp->code==a)
				{
					nodeptr->next = temp->next;
					delete temp;
				}
			}
		}

	}
}



