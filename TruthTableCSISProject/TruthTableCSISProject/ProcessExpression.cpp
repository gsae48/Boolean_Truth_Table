#include "ProcessExpression.h"
#include <iostream>
#include <cstring>

using namespace std;

ProccessExpression :: ProccessExpression(int *myU, int *o, char *op, char *v)
{
	myVariables = v;
	operators = o;
	ops = op;
	variableCount =0;
	skippedAlphas =0;
	myUppers = myU;
	asciiRepresentation =0;
	punctCount =0;
	expressionLength = 0;
}
//processes the char array
void ProccessExpression :: proccessExprs()
{
	/*
	this for loop goes through the whole char array and calulates the 
	total number of operands, the total number of operators, the possible
	number of equation results, it converts all operands in char array to 
	upper case, and it places the operands in an array in the order in 
	which they were found in the expression with no repeats.
	*/
	for(int x=0; x<size; x++)
	{		
		if(ispunct(expression[x]))//if its an OR or AND
		{
			expressionLength++;
			asciiRepresentation = int(expression[x]);
			
			operators[asciiRepresentation-33]++;
		}

		//IF THE EXPRESSION AT INDEX X IS A LETTER OF THE ALPHABET
		if(isalpha(expression[x]))
		{
			expressionLength++;
			
			//CONVERT TO UPPER CASE
			if(islower(expression[x]))
				expression[x] = toupper(expression[x]);

			//POSITION = THE ASCII REPRESENTATION OF THE LETTER
			asciiRepresentation = int(expression[x]);
			
			//POST INCREMENT VALUE IN MYUPPERS ARRAY; KEEPS TRACK OF HOW MANY OF EACH VARIABLE THERE ARE
			myUppers[asciiRepresentation-65] ++;
		
			//IF A CHAR IS ACCOUNTED FOR IN THE ARRAY INCREMENT VARIABLE COUNT BY ONE
			if(myUppers[asciiRepresentation-65] == 1)
			{
				//INSERT INTO THE ARRAY ALL THE VALUES OF ALL THE CHARS
				myVariables[variableCount] = expression[x];
				variableCount++;
			}
		}
		else
		{
			//NUMBER OF CHARS THAT DID NOT GO THROUGH THE IF STATEMENT
			skippedAlphas++;
		}
	}
	
	//possible values equals the number of operands to the power of 2
	possibleValues = pow(2,variableCount);
	
	//createTable creates a truthVariable object and initilizes it's constructor
	createTable();
}
void ProccessExpression :: createTable()
{
	TruthVariable myTable(possibleValues, variableCount, myVariables, expression, size);

	myTable.initilizeArray();
}
//converts string into char array
void ProccessExpression :: setUpThenProcess(string text)
{
	size = text.length();
	
	//dynamic allocation of char array
	expression = new char[size+1];
	int index;
	for(index= 0; index<size;index++)
		expression[index] = text[index];
	
	//inserting null terminator
	expression[index] = 0;
}
//over loaded istream operator
istream &operator >> (istream &strm, ProccessExpression &expressionObj)
{
	string text;
	//string text = "a+b*(b+c+!(b+c)+a)*e";
	cout << "This program calculates the truth table of a boolean equation.\n"
		<< "'+' is the OR operator.\n'*' is the AND operator.\n'!' is the NOT operator.\n"
		<<"Operands may only be alphabetical letters Aa-Zz\n"
		<<"You may use parenthesis, but they must open and close '(',')'\n"
		<<"Every operand must have an operator next to it, except operands next\n"
		<<"to the inside part of a parenthesis, example: c+(A+.....*B) \n"
		<<"It is not case sensitive with the operands\n"
		<<"An good example boolean equation would be: A+B*(B+C+!(B+C)+A)*E \n"
		<<"Type in a boolean equation: ";
	strm >> text;
	
	//input validation for string text
	int rightParenthesis=0, leftParenthesis=0;
	for(int x=0; x< text.length();x++)
	{
		if(text[x] == '(')
			leftParenthesis++;
		if(text[x] == ')')
			rightParenthesis++;
		//makes sure all input values are appropriate
		while(!isalpha(text[x]) && text[x] != '!' && text[x] != '+'
			&& text[x] != '*' && text[x] != '(' & text[x] != ')')
		{	
			cout << "Wrong input. Re-enter equation: ";
			strm >> text;
			x=0;
		}
		//makes sure there are no operands next to each other
		while(isalpha(text[x]) && isalpha(text[x+1]))
		{
			cout << "Operands have to be seperated by operators. Re-enter equation: ";
				strm >> text;
			x=0;
		}
		//makes sure there are no operators next to each other
		while((text[x] == '!' || text[x] == '*' || text[x] == '+') && 
			(text[x+1] == '*' || text[x+1] == '+'))
		{
			cout << "Operators have to be seperated by operands. Re-enter equation: ";
				strm >> text;
			x=0;
		}
		//makes sure that parenthesis match and close
		while(leftParenthesis-rightParenthesis != 0 && x==(text.length()-1))
		{
			cout << "Incomplete parenthesis. Re-enter equation: ";
				strm >> text;
			x=0;
			rightParenthesis=0;
			leftParenthesis=0;
		}
	}
	
	//converts the string into a char array
	expressionObj.setUpThenProcess(text);

	return strm;
}