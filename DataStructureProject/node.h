#pragma once
#include<iostream>
using namespace std;
template<class T>
class node
{
private:
	T data;
	node<T>* next;
	node<T>* previous;
public:
	node() {
		next = NULL;
		previous = NULL;
	}
	void setdata(T d) {
		data = d;
	}
	void setnext(node<T>* n) {
		next = n;
	}
	void setprevious(node<T>* p) {
		previous = p;
	}
	T getdata() {
		return data;
	}
	node<T>* getnext() {
		return next;
	}
	node<T>* getprevious() {
		return previous;
	}
};
