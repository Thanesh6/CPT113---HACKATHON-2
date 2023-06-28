#include<iostream>
#include "2p.h"
#include "items.h"
#include"Question.cpp"
using namespace std;

Game2P :: Game2P (){

			tail1 = nullptr;
			tail2 = nullptr;
		}
void Game2P ::clear()
{
	    player1 *nodeptr1 = nullptr,*temp1 = nullptr;
	    player2 *nodeptr2 = nullptr,*temp2 = nullptr;
    nodeptr1 = tail1;
    while (nodeptr1) {
        nodeptr1->back = temp1;
        delete nodeptr1;
        nodeptr1 = temp1;
		}		
		nodeptr2=tail2;
	while(nodeptr2)
	{
		nodeptr2->back = temp2;
        delete nodeptr2;
        nodeptr2 = temp2;
	}
}	

Game2P::~Game2P(){
			clear();
		}
		
void Game2P ::initial(string name1,string name2){
	player1 *newNode1;
	newNode1 = new player1;
	newNode1->hp=100;
	newNode1->attack = 10;
	newNode1->name=name1;
	newNode1->back= nullptr;
	tail1=newNode1;
	player2 *newNode2;
	newNode2 = new player2;
	newNode2->hp=100;
	newNode2->attack = 10;
	newNode2->name=name2;
	newNode2->back=nullptr;
	tail2=newNode2;

}	

void Game2P :: displayStat()
{
	player1 *nodeptr1=nullptr;
	player2 *nodeptr2=nullptr;
	nodeptr1=tail1;
	nodeptr2=tail2;
	
	if(!nodeptr1)
	{
		cout << "\n\nPlayer 1 not exist."<<endl;
	}
	
	else
	{
		cout << "\n\n   -------------------"<<endl;	
		cout << "   Player1: "<<nodeptr1->name<<endl;
		cout << "   -------------------"<<endl;
		cout << "   HP: "<<nodeptr1->hp<<endl;
		cout << "   Attack: "<<nodeptr1->attack<<endl;
		item1.Display2P();
		cout << endl;
	}
		if(!nodeptr2)
	{
		cout << "Player 1 not exist."<<endl;
	}
	
	else
	{
		cout << "\n   -------------------"<<endl;			
		cout << "   Player2: "<<nodeptr2->name<<endl;
		cout << "   -------------------"<<endl;
		cout << "   HP: "<<nodeptr2->hp<<endl;
		cout << "   Attack: "<<nodeptr2->attack<<endl;
		item2.Display2P();
	}
	
	
}
	void Game2P::p1Attack()
	{
			cout<<"Answer correct, Player 1 attack!!"<<endl;
			player1*nodeptr1=nullptr;
			player2*nodeptr2=nullptr,*newNode;
			nodeptr1=tail1;
			nodeptr2=tail2;
			if(!nodeptr1)
			{
				cout <<"No data for player1!!!"<<endl;
				return;
			}
			else
			{
				
				int attack = nodeptr1->attack;	
				if(!nodeptr2)
				{
					cout << "No data for player2!!!"<<endl;
					return;
				}
				
				else
				{

					
					newNode=new player2;
						newNode->back=nodeptr2;
					newNode->attack = nodeptr2->attack;
					newNode->name = nodeptr2->name;
					newNode->hp = ((nodeptr2->hp )- attack);
					tail2 = newNode;
				
						
					
				}
					
				
			}
			
			
		}
		
			void Game2P::p2Attack()
	{
			cout<<"Player 2 attack!!"<<endl;
			player1*nodeptr1=nullptr,*newNode;
			player2*nodeptr2=nullptr;
			nodeptr2=tail2;
			nodeptr1=tail1;
			if(!nodeptr2)
			{
				cout <<"No data for player1!!!"<<endl;
				return;
			}
			else
			{

				
				int attack = nodeptr2->attack;	
				if(!nodeptr1)
				{
					cout << "No data for player2!!!"<<endl;
					return;
				}
				
				else
				{

					
					newNode = new player1;
					newNode->back=nodeptr1;
					newNode->attack = nodeptr1->attack;
					newNode->name = nodeptr1->name;
					newNode->hp = ((nodeptr1->hp )- attack);
					newNode->back=nodeptr1;
					tail1 = newNode;
					
					
						
					
				}
					
				
			}
			
			
		}
		

bool Game2P::isGameOver()
{
	player1*nodeptr1=nullptr;
	player2*nodeptr2=nullptr;
	bool state;
	nodeptr1=tail1;
	nodeptr2=tail2;
	
	if(!nodeptr1)
	{
		cout << "no player 1";
		return true;
	}

		if(!nodeptr2)
	{
		cout << "no player 2";
		return true;
	}

	
	if(nodeptr1->hp<=0||nodeptr2->hp<=0)
		return true;
	else
		return false;
		}		
		
void Game2P::endGame()
{
	player1*nodeptr1=nullptr;
	player2*nodeptr2=nullptr;
	nodeptr1=tail1;
	nodeptr2=tail2;
if(!nodeptr1)
	{
		cout << "no player 1";
		return;
	}

		if(!nodeptr2)
	{
		cout << "no player 2";
		return ;
	}

	
	if(nodeptr2->hp<=0)
	{
		cout <<"\n------------------------------------------"<<endl;
		cout <<"               Game over!!!!"<<endl;
		cout <<"------------------------------------------"<<endl;
		cout << nodeptr1->name<<" has won the game!!!"<<endl;
	}
	else
		{
					cout <<"\n------------------------------------------"<<endl;
		cout <<"               Game over!!!!"<<endl;
		cout <<"------------------------------------------"<<endl;
		cout << nodeptr2->name<<" has won the game!!!"<<endl;
		}
	}

void Game2P::p1Revive()
{
	player1 *nodeptr=nullptr;
	nodeptr=tail1;
	tail1=nodeptr->back;
	delete nodeptr;
	cout << "------------------------"<<endl;
	cout << "   "<<tail1->name<<" revived!!"<<endl;
	cout << "------------------------"<<endl;

}
void Game2P::p2Revive()
{
	player2 *nodeptr=nullptr;
	nodeptr=tail2;
	tail2=nodeptr->back;
	delete nodeptr;
	cout << "------------------------"<<endl;
	cout << "   "<<tail2->name<<" revived!!"<<endl;
	cout << "------------------------"<<endl;
}
	
void Game2P::functionItemP1(int a)
{
	player1 *nodeptr=nullptr,*newNode;
	nodeptr=tail1;
	if(a==1)
	{
			newNode = new player1;
			newNode->hp = (nodeptr->hp+10);
			newNode->attack=nodeptr->attack;
			newNode->name=nodeptr->name;
			newNode->back = nodeptr;
			tail1 = newNode;
	}
	
		else if(a==2)
	{
			newNode = new player1;
			newNode->hp = nodeptr->hp;
			newNode->attack=(nodeptr->attack+10);
			newNode->name=nodeptr->name;
			newNode->back = nodeptr;
			tail1 = newNode;
	}
}

void Game2P::functionItemP2(int a)
{
	player2 *nodeptr=nullptr,*newNode;
	nodeptr=tail2;
	if(a==1)
	{
			newNode = new player2;
			newNode->hp = (nodeptr->hp+10);
			newNode->attack=nodeptr->attack;
			newNode->name=nodeptr->name;
			newNode->back = nodeptr;
			tail2 = newNode;
	}
	
		else if(a==2)
	{
			newNode = new player2;
			newNode->hp = nodeptr->hp;
			newNode->attack=(nodeptr->attack+10);
			newNode->name=nodeptr->name;
			newNode->back = nodeptr;
			tail2 = newNode;
	}
}
void Game2P::startGame(){
	int mark1, mark2;
	question q;
	item1.SetMenu();
	item2.SetMenu();
	string player1, player2;
	mark1=0;
	mark2=0;
	cout << "\n\nPlease enter your name..."<<endl;
	cout << "Player 1: ";
	cin.ignore();
	getline(cin,player1);
	cout <<"Player2: ";
	getline(cin,player2);
	initial(player1,player2);
	displayStat();
	
	cout << "\n\nPress enter to start the game...";
	getchar();
	
	while(true){
		  if(isGameOver())
            break;
			cout <<"Player 1 turn.\nPress enter to start...."<<endl;
			cin.ignore();
	getchar();
	for(int i =1;i<6;i++){
	            clock_t start = clock();
            q.generateQuestion(i,1,100);
            
            // Stop the timer
            clock_t end = clock();

            // Calculate the elapsed time in seconds
            double elapsedSeconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;

            if (q.isTrue()&&elapsedSeconds<=7){
                cout << "Congratulations! Your answer is correct." << endl;

                // Update monster's HP based on player's attack
                p1Attack();
                mark1+=10;
                int a;
                item1.randomDrop(a);
                functionItemP1(a);
            
                if(isGameOver()){
                  		if(!item2.ableRevive())
                	{
                			break;
					}
					else
					{
						p2Revive();
						item2.Delete(3);
					}
				
				  }
                	
            } else {
                cout << "Oops! Your answer is incorrect. "<<endl;

                // Update player's HP based on monster's attack
                  p2Attack();
                  mark2+=10;
                  
                  if(isGameOver()){
                  		if(!item1.ableRevive())
                	{
                			break;
					}
					else
					{
						p1Revive();
						item1.Delete(3);
					}
				
				  }
                  
                
            }

            // Display the elapsed time
            cout << "Elapsed Time: " << elapsedSeconds << " seconds" << endl;
            displayStat();
	
}
	  if(isGameOver())
                	break;
	cout <<"Player 2 turn.\nPress enter to start...."<<endl;
		cin.ignore();
	getchar();
	for(int i =1;i<6;i++){
	            clock_t start = clock();
            q.generateQuestion(i,1,100);
            
            // Stop the timer
            clock_t end = clock();

            // Calculate the elapsed time in seconds
            double elapsedSeconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;

            if (q.isTrue()&&elapsedSeconds<=6){
                cout << "Congratulations! Your answer is correct." << endl;

                // Update monster's HP based on player's attack
                p2Attack();
                mark1+=10;
                int a;
                item2.randomDrop(a);
                functionItemP2(a);
                if(isGameOver()){
                	if(!item1.ableRevive())
                	{
                			break;
					}
					else
					{
						p1Revive();
						item1.Delete(3);
					}
				}
                
                
            } else {

                // Update player's HP based on monster's attack
                  p1Attack();
                  mark2+=10;
                  if(isGameOver()){
                  		if(!item2.ableRevive())
                	{
                			break;
					}
					else
					{
						p2Revive();
						item2.Delete(3);
					}
				
				  }
                	break;
            }

            // Display the elapsed time
            cout << "Elapsed Time: " << elapsedSeconds << " seconds" << endl;
            displayStat();
	
}
	}
	
endGame();

}
	
		

