#pragma once
#define red 0;
template <typename T>
class TreeNode
{
public:
	TreeNode();
	T data;
	TreeNode<T>* lchild, * rchild;
	int color;
};