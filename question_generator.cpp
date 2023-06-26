#ifndef QUESTION_GENERATOR_H
#define QUESTION_GENERATOR_H

int generateNumber(int min, int max);
char generateOperator();
int calculateResult(int num1, int num2, char op);
void generateQuestion(int difficulty);

#endif  // QUESTION_GENERATOR_H
