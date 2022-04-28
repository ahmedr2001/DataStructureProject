#pragma once
#include "queue.h"

template <class T>
class priority_queue : public queue<T>
{
public:
	void enqueue(T* data, int distanceWeight=1, int costWeight=1, int prepTimeWeight=-1)
	{
		linkedlist<T>* Q = this->q;
		Q->addWithPriority(data, distanceWeight, costWeight, prepTimeWeight);
		this->front = Q->gethead();
		this->rear = Q->gettail();
	}
};