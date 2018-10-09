#include "BooleanTree.h"
#include <iostream>
#include <cstring>

using namespace std;

BooleanTree :: BooleanTree()
{
	root = nullptr;
}

void BooleanTree :: setStartingNode(TreeNode &newStartingNode)
{
	startingNode = new TreeNode();
	*startingNode = newStartingNode;
}

void BooleanTree :: setRoot(TreeNode &newRoot)
{
	root = new TreeNode();
	*root = newRoot;
}

void BooleanTree :: constructTree(char *expression, nodeStack *&stack,
		nodeStack *&garbageStack, BooleanTree *&BTree, int length)
{
	TreeNode *popped;
	TreeNode popNode;
	
	TreeNode *leftOperand;
	TreeNode *rightOperand;
	TreeNode *operatorr;
	int stackLen = 0;

	for(int x=0;x<length;x++)
	{
		stack->push(expression[x]);

		//cout <<stack->getTop();

		if(expression[x] == ')' || x == length-1)
		{
			
			//cout << endl;

			//pass #1: look for '!'
			while( stack->getTopInt() != -1 && stack->getTop() != '(')
			{
				if(stack->getTop() != '!')
				{
					popped = &stack->pop();
					garbageStack->pushNode(*popped); 
				}
				else	//if(stack.getTop() == '!')
				{
					
					rightOperand = &garbageStack->pop();
					operatorr = &stack->pop();

					rightOperand->setParent(*operatorr);
					operatorr->setRChild(*rightOperand);

					//cout << " " << operatorr->getKey();
					//cout << " " << rightOperand->getKey() << endl;

					garbageStack->pushNode(*operatorr);
				}
			}
			if(stack->getTopInt() != -1 && stack->getTop() == '(')
				garbageStack->pushNode(stack->pop()); //-->garbageStack.push(stack.pop().getKey());

			//cout << endl;
			/*
			pass #2: look for '*', while garbage stack is not empty and top of garbage stack
			!= ')' then we will pop nodes of the garbage stack and push them into the stack
			*/
			while( garbageStack->getTopInt() != -1 && garbageStack->getTop() != ')')
			{
				//if top of garbage stack != '*' then we will continue popping nodes off
				//the garbage stack and pushing them into the stack
				if(garbageStack->getTop() != '*')
				{
					popped = &garbageStack->pop();
					stack->pushNode(*popped);
				}
				else	//if(garbageStack.getTop() == '*')
				{
					//setting the operator and operand objects equal to the appropriate 
					//popped stack nodes
					operatorr = &garbageStack->pop();
					leftOperand = &stack->pop();
					rightOperand = &garbageStack->pop();
					
					//setting the appropriate links to each node based of order of operations
					leftOperand->setParent(*operatorr);
					rightOperand->setParent(*operatorr);
					operatorr->setLChild(*leftOperand);
					operatorr->setRChild(*rightOperand);

					//pushing the operatorr onto the stack, will not push the operands onto the 
					//stack, therefore getting rid of them, although they are now child nodes of
					//the operatorr node
					stack->pushNode(*operatorr);
				}
			}
			//pushing the ')' sign into the stack
			if(garbageStack->getTopInt() != -1 && garbageStack->getTop() == ')')
				stack->pushNode(garbageStack->pop());

			cout << endl;
			//pass #3 look for: '+', while stack is not empty and top of stack != '('
			while( stack->getTopInt() != -1 && stack->getTop() != '(')
			{
				//if top of stack doesn't equal '+', we will continue popping off nodes
				//from stack and pushing them onto the garbage stack.
				if(stack->getTop() != '+')	
				{
					popped = &stack->pop();
					garbageStack->pushNode(*popped);
				}
				//else top of stack equals '+'
				else	//if(stack.getTop() == '+')
				{
					//again setting objects equal to popped nodes
					operatorr = &stack->pop();
					leftOperand = &stack->pop();
					rightOperand = &garbageStack->pop();

					leftOperand->setParent(*operatorr);
					rightOperand->setParent(*operatorr);
					operatorr->setLChild(*leftOperand);
					operatorr->setRChild(*rightOperand);

					//pushing operatorr node onto garbage stack, excluding operand nodes
					garbageStack->pushNode(*operatorr);
				}
					
			}
			//perminantly getting rid of the '(' sign
			if(stack->getTopInt() != -1 && stack->getTop() == '(')
				stack->pop();

			while(garbageStack->getTopInt() != -1 && garbageStack->getTop() != ')')
			{
				popped = &garbageStack->pop();
				stack->pushNode(*popped);
				//cout << "pushed back onto stack : " << stack->getTop() << endl;
			}
			
			if(garbageStack->getTopInt() != -1)
				garbageStack->pop();

			//cout << endl;

			while(stack->getTopInt() != -1)
			{
				popNode = stack->pop();
				stackLen++;
				garbageStack->pushNode(popNode);
			}
			//cout <<"the stack: ";
			for(int i=0; i< stackLen; i++)
			{
				popNode = garbageStack->pop();
				//cout << popNode.getKey();
				stack->pushNode(popNode);
			}
			stackLen = 0;

			//cout <<endl;
	}
}
	//cout << endl;
	//cout << stack->getTopObj().getRChild()->getKey() << endl;
	BTree->setRoot(stack->getTopObj());
}
//Returns the root
TreeNode BooleanTree :: getRoot()
{
	return *root;
}
void BooleanTree :: initilizeAndCalculate(TreeNode &node, int rowNum, int vc,
										  char myVari[], int **tArray, char *exprsn)
{
		int row = rowNum;
		int column = vc;
		//int variableCount = vc;
		int oneOrZero;
		char keyValue = 'n';
		char currentVariable = 'n';
		char *myVariables = myVari;
		int **truthArry = tArray;
		char *expression = exprsn;
		TreeNode root = node;
		int answer;
		
		cout << endl;
		for(int i=0; i< column;i++)
			cout << " " << myVariables[i] << " ";
		
		cout << " |  " << expression 
			<< "\n----------------------------------------------------------------" << endl;
		
		for(int r=0;r<row;r++)
		{
			for(int c=0;c<column;c++)
			{
				oneOrZero = tArray[c][r];
				currentVariable = myVariables[c];
				inOrder(node, keyValue, currentVariable, oneOrZero);
				cout << " " << truthArry[c][r] << " ";
			}
			/*
			once the for loop has gone through the whole column, then that '
			means that all the operand nodes have been initialized to thier 
			corresponding one or zero vlaues
			*/
			printLevelOrder(&root);
			answer = root.get1or0();
			cout << " |  " << answer <<endl;
		}
}
void BooleanTree :: inOrder(TreeNode &node,char keyValue,
char currentVariable, int oneOrZero)
{
	if (node.getLChild() != nullptr)
	{
		keyValue = node.getLChild()->getKey();
		//if(isalpha(node.getLChild()->getKey()))
		if(isalpha(keyValue) && keyValue == currentVariable)
			node.getLChild()->set1or0(oneOrZero);

		inOrder(*node.getLChild(), keyValue, currentVariable, oneOrZero);
	}
	//cout << node.getKey();
	if (node.getRChild() != nullptr)
	{
		keyValue = node.getRChild()->getKey();
		if(isalpha(keyValue) && keyValue == currentVariable)
			node.getRChild()->set1or0(oneOrZero);

		inOrder(*node.getRChild(), keyValue, currentVariable, oneOrZero);
	}
}

int BooleanTree :: height(TreeNode *node)
{
	if(node == nullptr)
		return 0;
	else
	{
		int lheight = height(node->getLChild());
		int rheight = height(node->getRChild());

		if(lheight > rheight)
			return (lheight +1);
		else return (rheight+1);
	}
}
void BooleanTree :: printLevelOrder(TreeNode *root)
{
	int h = height(root);
	int i;
	for(i = h;i>0;i--)
	{
		printGivenLevel(root,i);
		//cout << endl;
	}
}
void BooleanTree :: printGivenLevel(TreeNode *root, int level)
{
	if(root == nullptr)
		return;
	if(level == 1)
	{
		if(!(isalpha(root->getKey())))
		{
			root->calculateOp();
		}
	}
	else if(level > 1)
	{
		printGivenLevel(root->getLChild(),level-1);
		printGivenLevel(root->getRChild(),level-1);
	}
}