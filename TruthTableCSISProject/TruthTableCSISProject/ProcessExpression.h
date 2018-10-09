#ifndef PROCCESSEXPRESSION_H
#define PROCCESSEXPRESSION_H
#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <ctype.h>
#include <cmath>
#include "truthVariable.h"

using namespace std;

/*
**This class will be responsible for proccessing the entire expression.
**It will record the number of operators and store them in an array, It
**will record the number of alphabetical characters and store them in an
**array, and it will calculate the possible outcomes to determine the size
**of the truth table. So for example three variables equals 2^3 outcomes or
**eight outcomes. so the size of the truth table will be 8 X 3.
*/

class ProccessExpression
{
private:
	int variableCount;//ARRAY TO STORE CHAR VALUES IN ORDER : ~(A*B+A*C+z) = [A,B,A,C,Z]
	char *myVariables;//KEEPS TACK OF TOTAL NUMBER OF VARIABLES : A=2,B=1,C=1,Z=1; SO VARAIBLE COUNT = 4
	int *myUppers;
	int skippedAlphas;
	int asciiRepresentation;		
	int possibleValues;
	int punctCount;
	int size;
	int *operators;
	char *ops;
	char *expression;
	int expressionLength;
	//int **truthArry;
public:
	ProccessExpression(int *myU, int *o, char *op, char *v);
	void setUpThenProcess(string text);
	void proccessExprs();
	void createTable();
	int getLength(){return expressionLength;}
	friend istream &operator >> (istream &strm, ProccessExpression &expressionObj);
};

#endif // !PROCCESSEXPRESSION_H