#include <iostream>
#include <string>
#include <cstdlib> // For random number generation
#include <ctime>   // For timing
#include "items.h"
#include"2p.h"
#include<fstream>
#include"Question.cpp"

using namespace std;
struct Player {
    int hp;
    int attack;
};

struct Monster {
    string name;
    int hp;
    int attack;
};


  bool checkValidInt(string d) {
    bool status = true;
    for (char c: d) {
      if (!isdigit(c)) {
        status = false;
        break;
      }
    }
    return status;
  }
  


struct Node {
    Player playerStats;
    Node* next;
    Node *back;
};

class LinkedList {
	private:
    	Node* head;
    		Node* tail;
    
	public:
    	LinkedList() 
    	{
    		head = nullptr;
    		tail = nullptr;
		}

    	void append(const Player& stats) {
        	Node* newNode = new Node;
        	newNode->playerStats = stats;
        	newNode->next = nullptr;

       		if (head == nullptr) {
        	    head = tail = newNode;
        	} else {
           	 tail->next = newNode;
            	newNode->back = tail;
            	tail = newNode;
       	 }
   	 }
   	 
   	 	void revive(Player & player)
   	 	{
   	 		Node *nodeptr = nullptr, *temp = nodeptr;
   	 		
   	 		nodeptr=tail;
   	 		tail=tail->back;
   	 		delete nodeptr;
   	 		tail->next=nullptr;
   	 		
   	 		player=tail->playerStats;

			}
	
	
    	void displayLatestStats() {
        	if (tail != nullptr) {
         	   cout << "\nPlayer's Latest Stats:\n";
          	  cout << "- HP: " << tail->playerStats.hp << "\n";
           	 cout << "  Attack: " << tail->playerStats.attack << "\n\n";
       	 } else {
        	    cout << "No player stats available.\n";
        	}
   	 }


};


int main() {
	question q;
	Game2P z;
	bool start=false;
	string l;
	int k;
	    Items items;
	do{    
	cout << "--------------------------------------"<<endl;
	cout << "      Welcome to Math Slayer          "<<endl;
	cout << "--------------------------------------"<<endl;
	cout << "\n1. Play game\n2. Rules\n";
	cout << "Enter your choice:";
	cin >>l;
	while(!checkValidInt(l)&&l!="1"&&l!="2")
	{
		cout << "Please enter a valid input: ";
		cin>>l;
	}
	k = stoi(l);
	if(k==1)
	{
		start=true;
	}
	else if(k==2)
	{
		string o;
		cout << "\n1. 1 Player\n2. 2 Player"<<endl;
		cin>>o;
			while(!checkValidInt(o)&&o!="1"&&o!="2")
		{
			cout << "Please enter a valid input: ";
			cin>>o;
		}
		int p = stoi(o);
		if(p==1)
		{
			cout << "Rules:\n1. After entering each level, you will be attacked by a monster in the form of a mathematical question.\n2. If you answer it wrongly / exceed the time limit, the attack will hit you and deal damage to your health.\n3. If you answer it correctly & in time, you can perform a counterattack and deal damage to the monster health."; 
			cout << "\n4. When your health point is down to 0, you will be defeated unless you have a revive stone which will restore health point to keep you going.\n\nPress enter to return to main page..."<<endl;
			cin.ignore();
			getchar();
			continue;
		}
		
		else if(p==2)
		{
			cout << "Rules: Two players will attack opponent if getting true to the mathematical question and each true answer will has a chance in dropping an items.\n";
			cout << "\n\nPress enter to return to main page....";
			cin.ignore();
			getchar();
			continue;
		}
	
}
	}while(!start);
	cout << "--------------------------------------"<<endl;
	cout << "      Welcome to Math Slayer          "<<endl;
	cout << "--------------------------------------"<<endl;
	int level;
	cout << "1. 1 player\n2. 2 player"<<endl;
	cout << "Enter your choice:";
	cin >> l;
	while(!checkValidInt(l)&&l!="1"&&l!="2")
	{
		cout << "Please enter a valid input: ";
		cin>>l;
	}
	k = stoi(l);
	if(k==2)
	{
		z.startGame(); 
	}
	else{
    Player player;
    Monster monster;

    level = 1;

    player.hp=100;
    player.attack=10;

	//Intro
			cout << "\nAs a fearless slayer, you bravely venture into the treacherous depths of the dungeon,\n"
                 "where menacing monsters lie in wait. The air crackles with anticipation as you take your first step,\n"
                 "knowing that danger lurks around every corner.\n\n";
            cout << "With each level you enter, the monsters waste no time in launching their relentless attacks.\n"
                 "Their assault takes the form of mathematical questions, designed to test your speed and mental acuity.\n"
                 "The pressure mounts as the seconds tick away, urging you to think swiftly and act decisively.\n"
                 "A wrong answer or hesitation leaves you vulnerable to their vicious strikes, dealing damage to your health.\n\n";
            cout << "As fortune would have it, every fifth level reveals a welcome sanctuary—an ancient shop nestled within the depths.\n"
                 "Here, you can catch your breath, replenish your supplies, and explore a variety of upgrades and artifacts.\n"
                 "The shopkeeper, wise and enigmatic, offers you a chance to enhance your skills, purchase new weapons,\n"
                 "or acquire revive stones—a precious lifeline that grants you a second chance at survival, even after suffering a fatal blow.\n\n";
            cout << "The levels stretch into infinity, presenting an ever-increasing challenge.\n"
                 "Yet, you press forward, driven by an unyielding determination to conquer the dungeon\n"
                 "and prove your mettle as the ultimate slayer. With every monster felled, every mathematical question conquered,\n"
                 "you inch closer to an elusive victory.\n\n";
            cout << "In this unforgiving realm, where battles are waged with both mind and blade,\n"
                 "you embrace the thrill of the unknown and defy the limitations of possibility.\n"
                 "With each level overcome, you redefine your limits and soar to new heights.\n"
                 "The dungeon awaits, filled with peril and untold treasures.\n"
                 "Will you emerge victorious, a legend in the annals of slayers, or succumb to the relentless onslaught?\n"
                 "The choice is yours, brave adventurer.\n\n\n";
    	cout << "Press enter to start the game........\n\n";
    	cin.ignore();
    	getchar();
            
            

    // Display the player's state
    cout << "------------------------------------"<<endl;
    cout << "Player's state:\n";
    cout << "- HP: " << player.hp << "\n";
    cout << "  Attack: " << player.attack << "\n";


   


    int difficulty ;
    int min, max;
   LinkedList playerStatsList;
    bool playerTurn = true;
    int clearedLevels = 0;
    question q;
    items.SetMenu();
    while (player.hp > 0 || items.ableRevive()) {
    	  if((level)%10<6&&(level)%10!=0)
    {
    	min = 1,max=9;
	}
	else
	{
		min =10, max = 99;
	}
	if(level>=50)
	{
		min = (level-40)*10;
		max = (level-40)*100;
	}
    difficulty = ((level-1)/10)+1;
        // Create a new monster for each level
        monster.name = "Monster Level " + to_string(level);
        monster.hp = 100+level * 10; // Increase monster's HP with each level
        monster.attack = 10+level *2 ;// Increase monster's attack with each level

        // Display the monster's stat
        cout << "------------------------------------"<<endl;
        cout << "" << monster.name << " stats:\n";
        cout << "- HP: " << monster.hp << "\n";
        cout << "  Attack: " << monster.attack << "\n";
         cout << "------------------------------------"<<endl;

        while (player.hp > 0 && monster.hp > 0) {
            // Start the timer
            clock_t start = clock();
            
           // Generate and display a math question
            q.generateQuestion(difficulty,min,max);

            // Stop the timer
            clock_t end = clock();

            // Calculate the elapsed time in seconds
            double elapsedSeconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;


            if (q.isTrue()&&elapsedSeconds<=10){
                cout << "Congratulations! Your answer is correct." << endl;

                // Update monster's HP based on player's attack
                monster.hp -= player.attack;
            } else {
                cout << "Oops! Your answer is incorrect."<< endl;

                // Update player's HP based on monster's attack
                player.hp -= monster.attack;
            }

            // Display the elapsed time
            cout << "Elapsed Time: " << elapsedSeconds << " seconds" << endl;

            // Display the updated player's state
            cout << "\nUpdated Player's state:\n";
            cout << "- HP: " << player.hp << "\n";
            cout << "  Attack: " << player.attack << "\n";

            // Display the updated monster's stats
            cout << "\nUpdated " << monster.name << " stats:\n";
            cout << "- HP: " << monster.hp << "\n";
            cout << "  Attack: " << monster.attack << "\n";

            playerStatsList.append(player);

            playerTurn = !playerTurn;
        }

        if (player.hp > 0) {
            // Player defeated the monster
            cout << "\nCongratulations! You defeated " << monster.name << "." << endl;
			level++;
            clearedLevels++;
            if ((level-1) % 5 == 0) {
            	int a=0, b=0;
            	items.enterShop(a,b); 
            	player.hp+=(a*10);
            	player.attack+=(a*10);
            }

            // Check if the player wants to continue to the next level
            char choice;
            cout << "Do you want to continue to the next level? (y/n): ";
            cin >> choice;
            if (choice == 'n' || choice == 'N') {
                cout << "\nCongratulations! You completed " << level << " level(s)." << endl;
                break;
            }

          
            
           
        } 
		 else if(player.hp <=0 && items.ableRevive())
            {
				//player hp is lower than 1 but has revive stone can revive
				playerStatsList.revive(player);
            	cout << "\n\nYou had revived!!";
            	items.Delete(3);
            	cout << "Press any key to continue..."<<endl;
   	 			getchar();getchar();
   	 			cout << "Let's continue..."<<endl<<endl;
            	
			}else {
				//Players hp lower than 1 and has no revive stone
            cout << "\nGame Over! The monster defeated you." << endl;
        }
    }

    playerStatsList.displayLatestStats();
}
    return 0;
}

