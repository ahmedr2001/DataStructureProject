#pragma once
#include "linkedlist.h"

template<class T>
class queue {
private:
	linkedlist<T>* q; //linked list to store data in 
	node<T>* front; // pointer to front node
	node<T>* rear; // pointer to end node
public:
	queue() {
		q = new linkedlist<T>;
		front = q->gethead();
		rear = q->gettail();
	}
	void enqueue(T data) { // add element to end of queue
		q->add(data);
		front = q->gethead();
		rear = q->gettail();
	}
	bool dequeue() { // remove element from the start of queue
		if (front == nullptr)
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
	bool isempty() { // check of queue is empty
		if (front == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	node<T>* peek() { // get pointer to front node
		return front;
	}
	void print() { //print queue
		node<T>* traverse = front;
		while (traverse != nullptr) {
			cout << traverse->getdata() << endl;
			traverse = traverse->getnext();
		}
	}
	void destroyqueue() { // delete all nodes of queue
		node<T>* traverse = front;
		while (front) {
			dequeue();
		}
	}
};