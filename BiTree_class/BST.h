#pragma once
template <typename T>
class BSTNode
{
public:
	BSTNode();
	T key;
	BSTNode<T>* lchild, * rchild;
};
template <typename T>
class BST
{
	BSTNode<T>** GetBSTNoP(T goal);
	BSTNode<T>** FirstLNode(BSTNode<T>* p);
	bool BSTDelete(BSTNode<T>** p);
public:
	BSTNode<T>* root;
	BST();
	BSTNode<T>* BSTSearch(T goal);
	bool BSTInsert(T goal);
	bool BSTDelete(T goal);
};

template<typename T>
inline BST<T>::BST()
{
	this->root = nullptr;
}

template<typename T>
inline BSTNode<T>* BST<T>::BSTSearch(T goal)
{
	BSTNode<T>* p = this->root;
	while (p != nullptr&&p->key!=goal)
	{
		if (goal < p->key)p = p->lchild;
		else p = p->rchild;
	}
	return p;
}

template<typename T>
inline BSTNode<T>** BST<T>::GetBSTNoP(T goal)
{
	BSTNode<T>** p = &this->root;
	while (*p != nullptr && (*p)->key != goal)
	{
		if (goal < (*p)->key)p = &((*p)->lchild);
		else p = &((*p)->rchild);
	}
	return p;
}



template<typename T>
inline bool BST<T>::BSTInsert(T goal)
{
	BSTNode<T>* p = this->root;
	while (p != nullptr)
	{
		if (p->key == goal)
			return false;
		else if (goal < p->key)
			p = p->lchild;
		else
			p = p->rchild;
	}
	p = new BSTNode<T>;
	p->key = goal;
	return true;
}
template<typename T>
BSTNode<T>** BST<T>::FirstLNode(BSTNode<T>* q)
{
	BSTNode<T>** p = &q;
	if (*p == nullptr)
		return nullptr;
	else if ((*p)->lchild==nullptr)
		return p;
	else
		return FirstLNode((*p)->lchild);
}
template<typename T>
inline bool BST<T>::BSTDelete(BSTNode<T>** p)
{
	if (*p == nullptr)
		return false;
	else 
	{
		if ((*p)->lchild == nullptr)
		{
			BSTNode<T>* temp = *p;
			*p = temp->rchild;
			delete temp;
		}
		else if ((*p)->rchild == nullptr)
		{
			BSTNode<T>* temp = *p;
			*p = temp->lchild;
			delete temp;
		}
		else
		{
			BSTNode<T>** temp = FirstLNode((*p)->rchild);
			(*p)->key = (*temp)->key;
			BSTDelete(temp);
		}
		return true;
	}
}

template<typename T>
inline bool BST<T>::BSTDelete(T goal)
{
	BSTNode<T>** p = GetBSTNoP(goal);
	bool b = BSTDelete(p);
	return b;
}

template<typename T>
inline BSTNode<T>::BSTNode()
{
	lchild = nullptr;
	rchild = nullptr;
}
