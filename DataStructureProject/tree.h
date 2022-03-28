#pragma once
#include "treenode.h"

enum treeprinttype
{
	pre,
	in,
	post
};

template<class T>
class tree {
private:
	treenode<T>* root; // root (head) of the tree
public:
	tree(T d) {
		root = new treenode<T>;
		root->setdata(d);
		root->setleft(NULL);
		root->setright(NULL);
	}
	treenode<T>* getroot() { // get pointer to the root
		return root;
	}
	tree<T>* addleft(T lv) { // add left branch to current tree
		tree<T>* l = new tree<T>(lv);
		root->setleft(l->getroot());
		return l;
	}
	tree<T>* addright(T rv) { // add right branch to current tree
		tree<T>* r = new tree<T>(rv);
		root->setright(r->getroot());
		return r;
	}
	void print(treenode<T>* trav, treeprinttype tpt) { // print tree depending on printing style (preorder,inorder,postorder)
		if (trav == NULL)
		{
			return;
		}
		if (tpt == 0)
		{
			cout << trav->getdata() << endl;
			print(trav->getleft(), tpt);
			print(trav->getright(), tpt);
		}
		else if (tpt == 1)
		{
			print(trav->getleft(), tpt);
			cout << trav->getdata() << endl;
			print(trav->getright(), tpt);
		}
		else if (tpt == 2)
		{
			print(trav->getleft(), tpt);
			print(trav->getright(), tpt);
			cout << trav->getdata() << endl;
		}
		else
		{
			cout << "wrong type,try again !" << endl;
		}
	}
};