
// Items.h
#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
using namespace std;

class Items{
	private:
		int num;
protected:
    struct Node {
        int code;
        Node* next;
    };

    Node* head;
    

public:
	  string item[3];
    int price[3];
     int coins;
    Items();
    ~Items();
    void Insert(int code);
    void Display();
    void Display2P();
    void Check(int code);
    void Delete(int code);
    bool isEmpty();
    void clear();
	void SetMenu();
    void DisplayMenu()const;
    void enterShop(int&,int&);
    bool checkValidInt(string d);
    bool ableRevive();
    void randomDrop(int&);
    int itemDrop(int);
    int getNum();
    int copyValue(int);
    void saveItems();
    void loadItems();
};

#endif


