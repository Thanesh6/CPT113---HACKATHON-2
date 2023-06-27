#include<iostream>
#include "Items.h"
#include "Shop.h"
using namespace std;

int main(){
	
//		Shop s;
//	s.SetMenu();
//	s.DisplayMenu();
//	
	Items I;
		I.SetMenu();
	I.Check(2);
	I.Insert(1);
	I.Insert(2);
	I.Insert(2);
	I.Insert(3);
	I.Insert(3);
	I.Insert(3);
	I.Insert(0);

	I.Display();
	I.Check(2);
	I.Delete(1);
	I.Check(3);
	I.Display();

	I.DisplayMenu();
	

	return 0;
}
