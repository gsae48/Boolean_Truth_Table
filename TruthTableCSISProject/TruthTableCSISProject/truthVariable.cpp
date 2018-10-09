#include "truthVariable.h"
#include <iostream>
using namespace std;

TruthVariable :: TruthVariable(int possibleCombos, int variableCount, char myVari[],
							   char *exprsn, int lengthText)
{
	variableCounts = variableCount;
	truthArry = new int*[variableCounts];
	variableArray = myVari;
	possibilites = possibleCombos;
	expression = exprsn;
	lenOfText = lengthText;


	//creating new 2d array
	for(int k=0;k<variableCounts;k++)
		truthArry[k] = new int[possibilites];
	
	//CALLING FUNCTION TO INITIALIZE ARRAY
	//initilizeArray(truthArry, possibilites, variableCounts);	
}

void TruthVariable :: initilizeArray()
{
	on = false;
	swFreq =possibilites/2;
	onCounter = 0;
	offCounter =0;

	//THIS FOR LOOP WORKS LIKE A NESTED FOR LOOP, AS IT INITILIZES THE VALUES IN ARRAY
	for(int y=0,p=0;(y<=possibilites) && (p<variableCounts);y++)
	{
		if(y==possibilites)
		{
			p++;
			swFreq = (swFreq/2);
			on = false;
			onCounter=0;
			offCounter=0;
			y = 0;
		}
		if((y<possibilites) && (p<variableCounts))
		{
			if(onCounter == swFreq)
			{	
				on = false;
				onCounter=0;
			}
			if(offCounter == swFreq)
			{
				on = true;
				offCounter=0;
			}
			if(on)
			{
				truthArry[p][y] = 1;
				onCounter++;
			}
			if(!on)
			{
				truthArry[p][y] = 0;
				offCounter++;
			}

		}
	}
		//creates a BooleanTree and two nodeStack objects on the heap
		calculateBooleanExpression();
}

void TruthVariable :: calculateBooleanExpression()
{
	BTree = new BooleanTree();
	stack = new nodeStack();
	garbageStack = new nodeStack();

	//constructs the binary tree
	BTree->constructTree(expression, stack, garbageStack, BTree, lenOfText);

	root = BTree->getRoot();
	
	//initilizes the operand nodes in the binary tree and calculates the equation
	BTree->initilizeAndCalculate(root, possibilites, variableCounts,
										  variableArray, truthArry, expression);
}
