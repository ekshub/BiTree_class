#pragma once
#include<iostream>
template <typename T>
class TreeNode
{
public:
	TreeNode();
	T data;
	TreeNode<T>* lchild, *rchild;
};

template <typename T>
class BiTree
{
	TreeNode<T>* root;
public:
	BiTree();
};

template<typename T>
inline BiTree<T>::BiTree()
{
	root = new TreeNode<T>;
	this->root->lchild = nullptr;
	this->root->rchild = nullptr;
}

template<typename T>
inline TreeNode<T>::TreeNode()
{
	this->lchild = nullptr;
	this->rchild = nullptr;
}
