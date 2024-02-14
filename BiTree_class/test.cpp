#include<iostream>
#include"ThreadBiTree.h"
int main()
{
	ThTree<int> a;
	a.root = new ThNode<int>;
	a.root->data = 1;
	a.root->lchild = new ThNode<int>;
	a.root->rchild = new ThNode<int>;
	a.root->lchild->lchild = new ThNode<int>;
	a.root->lchild->rchild = new ThNode<int>;
	a.root->rchild->lchild = new ThNode<int>;
	a.root->rchild->rchild = new ThNode<int>;
	a.root->lchild->data = 2;
	a.root->rchild->data = 3;
	a.root->lchild->lchild->data = 4;
	a.root->lchild->rchild->data = 5;
	a.root->rchild->lchild->data = 6;
	a.root->rchild->rchild->data = 7;
	a.CreatPostThTree();
	for(ThNode<int>* p = a.root;p!=nullptr;p=a.GetPre(p))
		cout <<p->data;
	cout << endl;
	for (ThNode<int>* p = a.root->lchild->lchild; p != nullptr; p = a.GetNext(p))
		cout << p->data;
	a.CreatMidThTree();
	a.CreatPostThTree();
	for (ThNode<int>* p = a.root; p != nullptr; p = a.GetPre(p))
		cout << p->data;
	cout << endl;
	for (ThNode<int>* p = a.root->lchild->lchild; p != nullptr; p = a.GetNext(p))
		cout << p->data;
}