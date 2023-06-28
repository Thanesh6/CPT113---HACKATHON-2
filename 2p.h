#ifndef GAME2P_H
#define GAME2P_H
#include <iostream>
#include "items.h"
using namespace std;


class Game2P{
	
	private:
		struct player1{
			string name;
			int hp;
			int attack;	
			player1 *back;
		};
			Items item1;
	Items item2;
		
		struct player2{
			string name;
			int hp;
			int attack;
			player2 *back;
		};
		

		player1 *tail1;
		player2 *tail2;
	
	public:
		Game2P();
		~Game2P();
		void initial(string,string); 
		void clear();
		void startGame();
		void displayStat();
		void p1Revive();
		void p2Revive();
		void p1Attack();
			void p2Attack();
		bool isGameOver();
		void endGame();
		void functionItemP2(int);
		void functionItemP1(int);
	
		
};

#endif
