#pragma once
inline int max(int a, int b)
{
	return a > b ? a : b;
}
template <typename T>
class AVLNode
{
public:
	AVLNode();
	T key;
	int Height;
	AVLNode<T>* lchild, * rchild;
};
template <typename T>
class AVL
{
	AVLNode<T>** GetAVLNoP(T goal);
	AVLNode<T>** FirstLNode(AVLNode<T>* p);
	bool AVLDelete(AVLNode<T>** p);
public:
	AVLNode<T>* root;
	AVL();
	AVLNode<T>* AVLSearch(T goal);
	void LRotates(AVLNode<T>** k);
	void RRotates(AVLNode<T>** k);
	int GetHeight(AVLNode<T>* k);
	bool AVLInsert(T goal);
	bool AVLDelete(T goal);
};
template<typename T>
inline AVLNode<T>::AVLNode() :lchild(nullptr), rchild(nullptr), Height(1)
{}

template<typename T>
inline AVLNode<T>* AVL<T>::AVLSearch(T goal)
{
	return nullptr;
}

/* LeftRotates(k1 rotates to the left):

		k2                       k1
	   /  \                     /  \
	  X    k1         ==>      k2   Z
		  /  \                /  \
		 Y    Z              X    Y
 */
template<typename T>
inline void AVL<T>::LRotates(AVLNode<T>** k)
{
	AVLNode<T>* k1 = (*k)->rchild;
	(*k)->rchild = k1->lchild;
	k1->lchild = *k;
	*k = k1;
	k1->lchild->Height = GetHeight(k1->lchild->lchild) + GetHeight(k1->lchild->rchild)+1;
	k1->Height = GetHeight(k1->lchild) + GetHeight(k1->rchild) + 1;
}
/* RightRotates(k1 rotates to the right):

		k2                   k1
	   /  \                 /  \
	  k1   Z     ==>       X   k2
	 / \                      /  \
	X   Y                    Y    Z
*/
template<typename T>
inline void AVL<T>::RRotates(AVLNode<T>** k)
{
	AVLNode<T>* k1 = (*k)->lchild;
	(*k)->lchild = k1->rchild;
	k1->rchild = *k;
	*k = k1;
	k1->rchild->Height = GetHeight(k1->rchild->lchild) + GetHeight(k1->rchild->rchild) + 1;
	k1->Height = GetHeight(k1->lchild) + GetHeight(k1->rchild) + 1;
}

template<typename T>
inline int AVL<T>::GetHeight(AVLNode<T>* k)
{
	return k==nullptr ? 0 : k->Height;
}

template<typename T>
inline bool AVL<T>::AVLInsert(T goal)
{
	AVLNode<T>* p = this->root;
	while (p != nullptr && p->key != goal)
	{
		if (goal < p->key)p = p->lchild;
		else p = p->rchild;
	}
	return p;
	return false;
}

