#pragma once
#include "linkedlist.h"

template<class T>
class queue {
private:
	linkedlist<T>* q;
	node<T>* front;
	node<T>* rear;
public:
	queue() {
		q = new linkedlist<T>;
		front = q->gethead();
		rear = q->gettail();
	}
	void enqueue(T data) {
		q->add(data);
		front = q->gethead();
		rear = q->gettail();
	}
	bool dequeue() {
		if (front == NULL)
		{
			return false;
		}
		else
		{
			q->deletenode(front);
			front = q->gethead();
			rear = q->gettail();
			return true;
		}
	}
	bool isempty() {
		if (front == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	node<T>* peek() {
		return front;
	}
	void print() {
		node<T>* traverse = front;
		while (traverse != NULL) {
			cout << traverse->getdata() << endl;
			traverse = traverse->getnext();
		}
	}
	void destroyqueue() {
		node<T>* traverse = front;
		while (front) {
			dequeue();
		}
	}
};