#pragma once
#include<iostream>
#include "Cargo.h"
using namespace std;
template<class T>
class node
{
protected:
	T data; // data of node
	node<T>* next; // pointer to next node
	node<T>* previous; // pointer to previous node
public:
	node() {
		next = nullptr;
		previous = nullptr;
	}
	void setdata(T d) { // set data of the node
		data = d;
	}
	void setnext(node<T>* n) { // set next node to current node
		next = n;
	}
	void setprevious(node<T>* p) { // set previous node to current node
		previous = p;
	}
	T getdata() { // get data of the node
		return data;
	}
	node<T>* getnext() { // get pointer to next node 
		return next;
	}
	node<T>* getprevious() { // get pointer to previous node 
		return previous;
	}
};