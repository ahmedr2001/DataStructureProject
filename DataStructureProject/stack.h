#pragma once
#include "linkedlist.h"

template<class T>
class stack {
private:
	node<T>* Top;
	linkedlist<T>* st;
	int size;
public:
	stack()
	{
		st = new linkedlist<T>;
		Top = st->gethead();
		size = 0;
	}
	T top() {
		return Top->getdata();
	}
	void push(T d) {
		st->addfromtop(d);
		Top = st->gethead();
		size++;
	}
	bool pop() {
		if (this->isempty())
		{
			return false;

		}
		else
		{
			st->deletenode(st->gethead());
			Top = st->gethead();
			size--;
		}
		return true;
	}
	bool isempty() {
		if (size == 0)
		{
			return true;
		}
		return false;
	}
	void print() {
		st->print();
	}
};