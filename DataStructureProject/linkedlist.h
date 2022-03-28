#pragma once
#include "node.h"

template<class T>
class linkedlist {
private:
	node<T>* head;
	node<T>* tail;
public:
	linkedlist()
	{
		head = NULL;
		tail = NULL;
	}
	node<T>* gethead() {
		return head;
	}
	node<T>* gettail() {
		return tail;
	}
	void add(T d) {
		node<T>* add = new node<T>;
		add->setdata(d);
		add->setnext(NULL);
		if (head == NULL)
		{
			head = add;
			tail = add;
		}
		else
		{
			tail->setnext(add);
			add->setprevious(tail);
			tail = tail->getnext();
		}
	}
	void addfromtop(T d) {
		node<T>* add = new node<T>;
		add->setdata(d);
		add->setnext(head);
		if (head == NULL)
		{
			head = add;
			tail = add;
		}
		else
		{
			add->setprevious(NULL);
			head = add;
		}
	}
	node<T>* deletenode(node<T>* todel) {
		if (todel->getnext() != NULL)
		{
			todel->getnext()->setprevious(todel->getprevious());
		}
		else
		{
			tail = todel->getprevious();
		}
		if (todel->getprevious() != NULL)
		{
			todel->getprevious()->setnext(todel->getnext());
		}
		else
		{
			head = todel->getnext();
		}
		node<T>* nexttodel = todel->getnext();
		delete todel;
		return nexttodel;
	}
	node<T>* getpointerto(T d) {
		node<int>* a = this->gethead();
		while (a != NULL)
		{
			if (a->getdata() == d)
			{
				return a;
			}
			a = a->getnext();
		}
		return NULL;
	}
	void print() {
		node<T>* x = head;
		while (x != NULL)
		{
			cout << x->getdata() << " ";
			x = x->getnext();
		}
		cout << endl;
	}
};