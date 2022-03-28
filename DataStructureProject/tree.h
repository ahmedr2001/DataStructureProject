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
	treenode<T>* root;
public:
	tree(T d) {
		root = new treenode<T>;
		root->setdata(d);
		root->setleft(NULL);
		root->setright(NULL);
	}
	treenode<T>* getroot() {
		return root;
	}
	tree<T>* addleft(T lv) {
		tree<T>* l = new tree<T>(lv);
		root->setleft(l->getroot());
		return l;
	}
	tree<T>* addright(T rv) {
		tree<T>* r = new tree<T>(rv);
		root->setright(r->getroot());
		return r;
	}
	void print(treenode<T>* trav, treeprinttype tpt) {
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