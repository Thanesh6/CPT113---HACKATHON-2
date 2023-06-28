#ifndef QUESTION_H
#define QUESTION_H
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;





class question{
	private:
		bool status;
	
		int index;
		
		
	public:
		bool checkValidInt(string d)
		{
			  bool status = true;
    for (char c: d) {
      if (!isdigit(c)) {
        status = false;
        break;
      }
    }
    return status;
		}
void generateNumber(int &num1, int &num2,int min, int max ){
	srand(time(0));
    num1 =  rand() % (max - min + 1) + min;
    num2 =  rand() % (max - min + 1) + min;
    
    if(num2>num1)
	{
		int temp;
		temp = num2;
		num2 = num1;
		num1 = temp;
	}
}

char generateOperator() {
    char operators[] = {'+', '-', '*'};
    index = rand() % 3;
    return operators[index];
}
bool isTrue()

{
 	return status;
}


int calculateResult(int num1, int num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        default:
            return 0;
    }
}

void generateQuestion(int difficulty,int min, int max) {
    int num1, num2;
    char op;
    switch (difficulty) {
        case 1:
               generateNumber(num1,num2 ,min, max);
            op ='+';
            break;
        case 2:
              generateNumber(num1,num2 ,min, max);
            op = '-';
            break;
        case 3:
               generateNumber(num1,num2 ,min, max);
            op = '*';
            break;

        // Add more cases for increasing difficulty levels as needed
        default:
           generateNumber(num1,num2 ,min, max);
            op = generateOperator();
            break;
    }
    
    int result = calculateResult(num1, num2, op);
    
    cout << "\n\nWhat is " << num1 << " " << op << " " << num2 << "? "<<endl;
    cout << "Answer: ";
    
    string input;
    int userAnswer;
    cin >> input;
    while(!checkValidInt(input))
    {
    	cout << "Please enter an integer!!"<<endl;
    	cout << "Answer: ";
    	cin >> input;
	}
	userAnswer = stoi(input);
    
    
    
    
//    if (userAnswer == result) {
//        cout << "Correct!\n";
//    } else {
//        cout << "Incorrect. The correct answer is " << result << "\n";
//    }
    
    if(userAnswer!=result)
		status=false;
	
	else
		status = true;
  
//    answer(result);
}

};


#endif

