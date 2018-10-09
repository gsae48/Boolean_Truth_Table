/*
Author: Ali Esparza
CSIS 297 Final Project
*/

#include <iostream>
#include "ProcessExpression.h"
#include <cstring>
#include <string>

using namespace std;

int main()
{	
	//char expression[SIZE] = "A+A*D*C+A+B*C*D";//"(A+B(C*D)+A+C(A*B))";//= {'/0'};
	char myVariables[26] = {'/0'};//HOLDS ONE VALUE OF EACH CHAR: A+A+A+B*C-> [A,B,C]-> VARIABLE COUNT = 3
	int myUppers[26] = {0};/*HOLDS A NUMBER CORRESPONDING TO THE NUMBER OF TIMES THAT OPERAND APPEARS AND 
						   ITS PLACEMENT IN THE ALPHABET-> A+A+A+C-> [3,0,1,0..]*/		
	int operators[12] = {0};/*HOLDS A NUMBER CORRESPONDING TO THE NUMBER OF TIMES THAT OPERATOR APPEARS AND 
						   ITS PLACEMENT-> A+A+A+C-> [3,0,1,0..]*/
	char op[12] = {'!','/0','/0','/0','/0','&','/0','(',')','*','+'};
	
	//CREATES PROCEESSEXPRESSION OBJECT AND INITILIZES ITS CONSTRUCTOR
	ProccessExpression processMyexpn(myUppers, operators, op, myVariables);

	//MAKING USE OF THE OVERLOADED ISTREAM OPERATOR
	cin >> processMyexpn;

	/*
	Program Flow of Control:
	ProccessExpression object calls proccessExprs() fucntion
	proccessExprs() calls createTable() function which creates a truthVaribale object
	truthVariable object calls initilizeArray() funciton
	initilizeArray() funciton calls calculateBooleanExpression() function
	calculateBooleanExpression() funciton creates two nodeStack and one BooleanTree objects
	calculateBooleanExpression() funciton calls constructTree(...) function
	calculateBooleanExpression() funciton calls initilizeAndCalculate(...) function
	initilizeAndCalculate(...) function calls inorder(...) fucntion to initilize the operands
	initilizeAndCalculate(...) function calls printLevelOrder(...) funciton to perform operations
	*/
	processMyexpn.proccessExprs();
	
	return 0;
}
