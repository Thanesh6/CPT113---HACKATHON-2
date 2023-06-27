// Items.h
#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
using namespace std;

class Items{
private:
    struct Node {
        int code;
        Node* next;
    };

    Node* head;
    int coin;
	string item[3];
    int price[3];
public:
    Items();
    ~Items();
    void Insert(int code);
    void Display();
    void Check(int code);
    void Delete(int code);
    bool isEmpty();
    void clear();
        	void SetMenu();
    	void DisplayMenu()const;
};

#endif


