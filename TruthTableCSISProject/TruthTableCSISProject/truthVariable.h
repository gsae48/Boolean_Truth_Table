#ifndef TRUTHVARIABLE_H
#define	TRUTHVARIABLE_H
#include <iostream>
#include "BooleanTree.h"
#include "TreeNode.h"
#include "nodeStack.h"
using namespace std;

/*
**This class is responsible for building the truth table. Ideally I would use
**a two demensional array to represent the truth table, but since the size of 
**the truth table is variable, then I would need something the behaves more like 
**a dynamically allocated 2d array. So i created a pointer to pointers array which 
**can imitate the behavior of a two demensional array. I then populate the array
**with ones and zeros representing binary values. The ones and zeros are populated
**in such a way that the table counts from zero to 2^n in binary. These binary values
**will be fed into the class which calculates the binary values.
*/
class TruthVariable
{
private:
	//bool *truthV;
	bool on;
	bool off;
	int swFreq;//SWITCH FREQUENCY, HOW OFTEN THE VALUES WILL SWITCH
	int **truthArry;
	char *variableArray;
	int onCounter;
	int offCounter;
	int possibilites;
	int variableCounts;
	int lenOfText;
	BooleanTree *BTree;
	TreeNode root;
	nodeStack *stack;
	nodeStack *garbageStack;
	char *expression;
public:
	TruthVariable(int p, int variableCount, char myVari[], char *exprsn, int lengthText);
	void initilizeArray();
	void calculateBooleanExpression();
};


#endif // !TRUTHVARIABLE.H
