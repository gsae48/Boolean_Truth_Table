#include "nodeStack.h"

nodeStack :: nodeStack()
{
	top = -1;
	
	for(int x =0;x<25;x++)
		stack[x] = new TreeNode();
}

void nodeStack :: push(char c)
{
	top++;
	stack[top]->setKey(c);
}

void nodeStack :: pushNode(TreeNode &n)
{
	top++;
	*stack[top] = n;
}

TreeNode nodeStack :: pop()
{
	TreeNode popped;

	popped = *(stack[top]);
	top--;

	return popped;
}
char nodeStack :: getTop()
{
	char topC;
	
	topC = stack[top]->getKey();

	return topC;
}
int nodeStack :: getTopInt()
{
	return top;
}
TreeNode nodeStack :: getTopObj()
{
	TreeNode topObj;
	topObj = *(stack[top]);
	return topObj;
}