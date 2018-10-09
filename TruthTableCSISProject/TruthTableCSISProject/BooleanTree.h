#ifndef BOOLEANTREE_H
#define BOOLEANTREE_H
#include "TreeNode.h"
#include "nodeStack.h"

static bool isStartingPtAssigned = false;//checks turns to true once the 
static bool switching = false;										//first node has been assigned left and right children
class BooleanTree
{
private: 
	TreeNode *root;
	TreeNode *startingNode;
public:
	BooleanTree();
	void setStartingNode(TreeNode &newStartingNode);
	void setRoot(TreeNode &newRoot);
	void constructTree(char *expression, nodeStack *&stack,
		nodeStack *&garbageStack, BooleanTree *&BTree, int length);
	TreeNode getRoot();
	TreeNode getStartingNode();
	int height(TreeNode *node);
	void printLevelOrder(TreeNode *root);
	void printGivenLevel(TreeNode *root, int level);
	void giveValues();
	void inOrder(TreeNode &node,char keyValue,
		char currentVariable, int oneOrZero);
	void initilizeAndCalculate(TreeNode &node, int rowNum, int vc,
						char myVari[], int **tArray, char *exprsn);
};

#endif BOOLEANTREE_H