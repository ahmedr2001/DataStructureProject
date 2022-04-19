#pragma once
#include "node.h"

template<class T>
class linkedlist {
protected:
	node<T>* head; //start of linked list
	node<T>* tail; //end of linked list
	int size;
public:
	linkedlist()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	node<T>* gethead() { // get head of linked list
		return head;
	}
	node<T>* gettail() { // get tail of linked list
		return tail;
	}
	int getSize() const {
		return size;
	}
	void add(T* d) { // add from the end of linked liast
		node<T>* add = new node<T>;
		add->setdata(d);
		add->setnext(nullptr);
		if (head == nullptr)
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
		size++;
	}
	void addWithPriority(T* data) // place highest priorities at the front
	{
		Time currentTime;
		node<T>* newNode = new node<T>;
		newNode->setdata(data);
		int priority = data->getPriority();
		bool done = 0;
		node<T>* headCopy = head;
		if (!headCopy) {
			newNode->setnext(nullptr);
			newNode->setprevious(nullptr);
			head = newNode;
			tail = newNode;
			done = 1;
		}
		else if (!headCopy->getnext()) {
			if (headCopy->getdata()->getPriority() > priority) {
				newNode->setnext(nullptr);
				newNode->setprevious(head);
				head->setnext(newNode);
				tail = newNode;
				done = 1;
			}
			else {
				newNode->setnext(head);
				newNode->setprevious(nullptr);
				head->setprevious(newNode);
				tail = head;
				head = newNode;
				done = 1;
			}
		}
		else {
			while (headCopy) {
				if (headCopy->getdata()->getPriority() <= priority) {
					if (headCopy == head) {
						newNode->setnext(head);
						newNode->setprevious(nullptr);
						head->setprevious(newNode);
						head = newNode;
						done = 1;
						break;
					}
					else {
						newNode->setnext(headCopy);
						newNode->setprevious(headCopy->getprevious());
						headCopy->setprevious(newNode);
						newNode->getprevious()->setnext(newNode);
						done = 1;
						break;
					}
				}
				headCopy = headCopy->getnext();
			}
			if (!done) {
				newNode->setnext(nullptr);
				newNode->setprevious(tail);
				tail->setnext(newNode);
				tail = newNode;
				done = 1;
			}
		}
		size++;
	}
	void addfromtop(T* d) { // add from the start of linked list
		node<T>* add = new node<T>;
		add->setdata(d);
		add->setnext(head);
		if (head == nullptr)
		{
			head = add;
			tail = add;
		}
		else
		{
			add->setprevious(nullptr);
			head = add;
		}
		size++;
	}
	node<T>* deletenode(node<T>* todel) { // delete node by its pointer
		if (todel->getnext() != nullptr)
		{
			todel->getnext()->setprevious(todel->getprevious());
		}
		else
		{
			tail = todel->getprevious();
		}
		if (todel->getprevious() != nullptr)
		{
			todel->getprevious()->setnext(todel->getnext());
		}
		else
		{
			head = todel->getnext();
		}
		node<T>* nexttodel = todel->getnext();
		delete todel;
		size--;
		return nexttodel;
	}
	node<T>* getpointerto(T* d) { // find pointer to node with value d
		node<T>* a = this->gethead();
		while (a != nullptr)
		{
			if (a->getdata() == d)
			{
				return a;
			}
			a = a->getnext();
		}
		return nullptr;
	}
	void print() { // print the linked list
		node<T>* x = head;
		while (x != nullptr)
		{
			cout << x->getdata() << " ";
			x = x->getnext();
		}
		cout << endl;
	}
	bool isempty()
	{
		return (head == nullptr);
	}
	node<T>* GetAllNodes(int& size)
	{
		int lSize = this->getSize();
		node<T>* arr = new node<T>[lSize];
		int i = 0;
		while (!isempty()) {
			arr[i] = *(this->head);
			this->deletenode(this->head);
			i++;
		}
		size = i;
		for (int j = 0; j < size; j++) {
			this->add(arr[j].getdata());
		}
		return arr;
	}
};