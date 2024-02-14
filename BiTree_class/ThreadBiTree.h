#pragma once
#include<iostream>
using namespace std;
template <typename T>
class ThNode
{
public:
	ThNode<T>* lchild, * rchild;
	bool ltag, rtag;
	T data;
	ThNode();
};

template <typename T>
class ThTree
{
public:
	ThNode<T>* root;
	int tag;
	void PreInTh(ThNode<T>* p, ThNode<T>*& pre, void(*visit)(ThNode<T>*&, ThNode<T>*&));
	void PreInTh(ThNode<T>* p, ThNode<T>*& pre, ThNode<T>* q, ThNode<T>*& goal);
	void MidInTh(ThNode<T>* p, ThNode<T>*& pre, void(*visit)(ThNode<T>*&, ThNode<T>*&));
	void PostInTh(ThNode<T>* p, ThNode<T>*& pre, void(*visit)(ThNode<T>*&, ThNode<T>*&));
	void PostInTh(ThNode<T>* p, ThNode<T>*& pre, ThNode<T>* q, ThNode<T>*& goal);
	static void visit1(ThNode<T>*& p, ThNode<T>*& pre);
	ThNode<T>* FirstLNode(ThNode<T>*p);//input a ptr, get the ptr of leftest child
	ThNode<T>* LastRNode(ThNode<T>* p);//input a ptr, get the ptr of rightest child
public:
	ThTree();
	bool CreatPreThTree();
	bool CreatMidThTree();
	bool CreatPostThTree();
	ThNode<T>* GetNext(ThNode<T>* p);
	ThNode<T>* GetPre(ThNode<T>* p);
};

template<typename T>
inline ThNode<T>::ThNode()
{
	this->lchild = nullptr;
	this->rchild = nullptr;
	this->ltag = true;
	this->rtag = true;
}

template<typename T>
inline ThTree<T>::ThTree()
{
	root = new ThNode<T>;
	this->root->lchild = nullptr;
	this->root->rchild = nullptr;
	this->tag = 0;
}

template<typename T>
inline bool ThTree<T>::CreatPreThTree()
{
	if (root == nullptr)
		return false;
	ThNode<T>* pre = nullptr, * p = this->root;
	PreInTh(p, pre,visit1);
	if (pre->rchild == nullptr)
		pre->rtag = false;
	this->tag = 1;
	return true;
}

template<typename T>
bool ThTree<T>::CreatMidThTree()
{
	if(root==nullptr)
	return false;
	ThNode<T>* pre = nullptr,*p=this->root;
	MidInTh(p, pre,visit1);
	if (pre->rchild == nullptr)
		pre->rtag = false;
	this->tag = 2;
	return true;
}

template<typename T>
inline bool ThTree<T>::CreatPostThTree()
{
	if (root == nullptr)
		return false;
	ThNode<T>* pre = nullptr, * p = this->root;
	PostInTh(p, pre,visit1);
	if (pre->rchild == nullptr)
		pre->rtag = false;
	this->tag = 3;
	return true;
}

template<typename T>
inline ThNode<T>* ThTree<T>::GetNext(ThNode<T>* p)
{
	if (p == nullptr)
	{
		return nullptr;
		cerr << "input nullptr";
	}
	if (this->tag == 1)
	{
		if (!p->rtag)
			return p->rchild;
		else if (p->ltag)
			return p->lchild;
		else
			return p->rchild;
	}
	else if (this->tag == 2)
	{
		if (p->rtag)
			return FirstLNode(p->rchild);
		else
			return p->rchild;
	}
	else if (this->tag == 3)
	{
		if (!p->rtag)
			return p->rchild;
		else
		{
			ThNode<T>* next =nullptr;
			ThNode<T>* pre = nullptr;
			PostInTh(this->root, pre, p, next);
			return next;
		}
	}
	else
	{
		cerr << "Wrong Tag";
		return nullptr;
	}
}

template<typename T>
inline ThNode<T>* ThTree<T>::GetPre(ThNode<T>* p)
{
	if (p == nullptr)
	{
		return nullptr;
		cerr << "input nullptr";
	}
	if (this->tag == 1)
	{
		
		if (!p->ltag)
			return p->lchild;
		else
		{
			ThNode<int>* pre = nullptr;
			ThNode<int>* Pre = nullptr;
			PreInTh(this->root, pre, p, Pre);
			return Pre;
		}
	}
	else if (this->tag == 2)
	{
		if(p->ltag)
			return LastRNode(p->lchild);
		else
			return p->lchild;
	}
	else if (this->tag == 3)
	{
		if (!p->ltag)
			return p->lchild;
		else if (p->rtag)
			return p->rchild;
		else
			return p->lchild;
	}
	else
	{
		cerr << "Wrong Tag";
		return nullptr;
	}
}

template<typename T>
inline void ThTree<T>::PreInTh(ThNode<T>* p, ThNode<T>*& pre, void(*visit)(ThNode<T>*&, ThNode<T>*&))
{
	if (p != nullptr)
	{
		visit(p,pre);
		if(p->ltag)
		PreInTh(p->lchild, pre,visit);
		if(p->rtag)
		PreInTh(p->rchild, pre,visit);
	}
}

template<typename T>
inline void ThTree<T>::PreInTh(ThNode<T>* p, ThNode<T>*& pre, ThNode<T>* q, ThNode<T>*& goal)
{
	if (p != nullptr)
	{	if (p == q)
		{
			goal = pre;
			return;
		}
	pre = p;
	if (p->ltag)
		PreInTh(p->lchild, pre, q, goal);
	if (p->rtag)
		PreInTh(p->rchild, pre, q, goal);
	}
}

template<typename T>
inline void ThTree<T>::MidInTh(ThNode<T>* p, ThNode<T>* &pre, void(*visit)(ThNode<T>*&, ThNode<T>*&))
{
	if (p != nullptr)
	{
		if(p->ltag)
		MidInTh(p->lchild, pre,visit);
		visit(p, pre);
		if(p->rtag)
		MidInTh(p->rchild, pre,visit);
	}
}

template<typename T>
inline void ThTree<T>::PostInTh(ThNode<T>* p, ThNode<T>*& pre, void(*visit)(ThNode<T>*&, ThNode<T>*&))
{
	if (p != nullptr)
	{
		if (p->ltag)
			PostInTh(p->lchild, pre, visit);
		if (p->rtag)
			PostInTh(p->rchild, pre, visit);
		visit(p, pre);
	}
}

template<typename T>
inline void ThTree<T>::PostInTh(ThNode<T>* p, ThNode<T>*& pre, ThNode<T>* q, ThNode<T>*& goal)
{
	if (p != nullptr) 
	{
		if (p->ltag)
			PostInTh(p->lchild, pre, q, goal);
		if (p->rtag)
			PostInTh(p->rchild, pre, q, goal);
		if (pre == q)
		{
			goal = p;
			pre = p;
			return;
		}
		pre = p;
	}
}

template<typename T>
inline void ThTree<T>::visit1(ThNode<T>* &p, ThNode<T>* &pre)
{
	if (p->lchild == nullptr||(!p->ltag))
	{
		p->lchild = pre;
		p->ltag = false;
	}
	if (pre!=nullptr&&(pre->rchild == nullptr || (!pre->rtag)))
	{
		pre->rchild = p;
		pre->rtag = false;
	}
	pre = p;
}

template<typename T>
ThNode<T>* ThTree<T>::FirstLNode(ThNode<T>* p)
{
	if (p == nullptr)
		return nullptr;
	else if (!p->ltag)
		return p;
	else
		return FirstLNode(p->lchild);
}

template<typename T>
inline ThNode<T>* ThTree<T>::LastRNode(ThNode<T>* p)
{
	if (p == nullptr)
		return nullptr;
	else if (!p->rtag)
		return p;
	else
		return LastRNode(p->rchild);
}
