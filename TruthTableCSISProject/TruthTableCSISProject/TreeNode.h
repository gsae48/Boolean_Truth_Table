#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>

using namespace std;

class TreeNode
{
private:
	char key;
	char rightValue;
	char leftValue;
	TreeNode *parent;
	TreeNode *leftChild;
	TreeNode *rightChild;
	int oneOrZero;

public:
	TreeNode();
	TreeNode(char k);
	void setKey(char k);
	char getKey();
	void set1or0(int n);
	int get1or0();
	TreeNode(const TreeNode &obj);
	void setLChild(TreeNode &lc);
	void setRChild(TreeNode &rc);
	void setParent(TreeNode &p);
	TreeNode * getLChild();
	TreeNode * getRChild();
	TreeNode * getParent();
	const void operator=(const TreeNode &right);
	friend int operator*(TreeNode operand1, TreeNode operand2);
	friend int operator+(TreeNode operand1, TreeNode operand2);
	void setRightValue(char k);
	void setLeftValue(char k);
	char getRightValue();
	char getLeftValue();
	void calculateOp();
};
#endif TREENODE_H