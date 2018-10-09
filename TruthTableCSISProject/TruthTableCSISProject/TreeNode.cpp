#include "TreeNode.h"

TreeNode :: TreeNode()
{
	//parent = new TreeNode();
	parent = nullptr;
	//leftChild = new TreeNode();
	leftChild = nullptr;
	//rightChild = new TreeNode();
	rightChild = nullptr;
	key = 'n';
	leftValue = 'n';
	rightValue = 'n';
}

TreeNode :: TreeNode(char k)
{
	//parent = new TreeNode();
	parent = nullptr;
	//leftChild = new TreeNode();
	leftChild = nullptr;
	//rightChild = new TreeNode();
	rightChild = nullptr;
	key = k;
	leftValue = 'n';
	rightValue = 'n';
}

void TreeNode :: setKey(char k)
{
	key = k;
}

char TreeNode :: getKey()
{
	return key;
}

void TreeNode :: set1or0(int n)
{
	oneOrZero = n;
}

int TreeNode :: get1or0()
{
	return oneOrZero;
}

TreeNode :: TreeNode(const TreeNode &obj)
{
	key = obj.key;
	parent = obj.parent;
	leftChild = obj.leftChild;
	rightChild = obj.rightChild;
	oneOrZero = obj.oneOrZero;
}

void TreeNode :: setLChild(TreeNode &lc)
{
	leftChild = new TreeNode();
	*leftChild = lc;
}

void TreeNode :: setRChild(TreeNode &rc)
{
	rightChild = new TreeNode();
	*rightChild = rc;
}

void TreeNode :: setParent(TreeNode &p)
{
	parent = new TreeNode();
	*parent = p;
}

TreeNode * TreeNode :: getLChild()
{	
	return leftChild;
}

TreeNode * TreeNode :: getRChild()
{
	return rightChild;
}

TreeNode * TreeNode :: getParent()
{
	return parent;
}

const void TreeNode :: operator=(const TreeNode &right)
{
	key = right.key;
	parent = right.parent;
	leftChild = right.leftChild;
	rightChild = right.rightChild;
	oneOrZero = right.oneOrZero;
}

int operator*(TreeNode operand1, TreeNode operand2)
{
	return (operand1.get1or0() && operand2.get1or0());
}
int operator+(TreeNode operand1, TreeNode operand2)
{
	return (operand1.get1or0() | operand2.get1or0());
}

void TreeNode :: setRightValue(char k)
{
	rightValue = k;
}
void TreeNode :: setLeftValue(char k)
{
	leftValue = k;
}
char TreeNode :: getLeftValue()
{
	return leftValue;
}
char TreeNode :: getRightValue()
{
	return rightValue;
}
void TreeNode :: calculateOp()
{
	switch(key)
	{
	case '!':
		set1or0(!(getRChild()->get1or0()));
		break;
	case '*':
		set1or0(*getRChild() * *getLChild());
		break;
	case '+':
		set1or0(*getRChild() + *getLChild());
		break;
	}
}