#ifndef NODESTACK_H
#define NODESTACK_H
#include "TreeNode.h"

class nodeStack
{
private:
	TreeNode *stack[25];
	int size;
	int top;
public:
	nodeStack();
	void push(char c);
	void pushNode(TreeNode &n);
	TreeNode pop();
	char getTop();
	TreeNode getTopObj();
	int getTopInt();
};

#endif NODESTACK_H