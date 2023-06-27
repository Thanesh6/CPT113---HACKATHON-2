#include "question_generator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int generateNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char generateOperator() {
    char operators[] = {'+', '-', '*', '/'};
    int index = rand() % 4;
    return operators[index];
}

int calculateResult(int num1, int num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0;
    }
}

void generateQuestion(int difficulty) {
    int num1, num2;
    char op;
    
    switch (difficulty) {
        case 1:
            num1 = generateNumber(1, 10);
            num2 = generateNumber(1, 10);
            op = generateOperator();
            break;
        case 2:
            num1 = generateNumber(10, 100);
            num2 = generateNumber(10, 100);
            op = generateOperator();
            break;
        case 3:
            num1 = generateNumber(100, 1000);
            num2 = generateNumber(100, 1000);
            op = generateOperator();
            break;
        // Add more cases for increasing difficulty levels as needed
        default:
            num1 = generateNumber(1, 10);
            num2 = generateNumber(1, 10);
            op = generateOperator();
            break;
    }
    
    int result = calculateResult(num1, num2, op);
    
    std::cout << "What is " << num1 << " " << op << " " << num2 << "? ";
    
    int userAnswer;
    std::cin >> userAnswer;
    
    if (userAnswer == result) {
        std::cout << "Correct!\n";
    } else {
        std::cout << "Incorrect. The correct answer is " << result << "\n";
    }
}
