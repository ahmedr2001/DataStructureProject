 #pragma once
#include "linkedlist.h"

template<class T>
class stack {
private:
	node<T>* Top; // pointer to the top node
	linkedlist<T>* st; // linked list to store data in
	int size; // size of stack
public:
	stack()
	{
		st = new linkedlist<T>;
		Top = st->gethead();
		size = 0;
	}
	T top() { // return data of the top
		return Top->getdata();
	}
	void push(T d) { // add element on top of the stack
		st->addfromtop(d);
		Top = st->gethead();
		size++;
	}
	bool pop() { // remove element from the top of the stack
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
	bool isempty() { // chack if the stack is empty
		if (size == 0)
		{
			return true;
		}
		return false;
	}
	void print() { //print the stack
		st->print();
	}
};