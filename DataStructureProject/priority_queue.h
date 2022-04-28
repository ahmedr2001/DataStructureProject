#pragma once
#include "queue.h"

template <class T>
class priority_queue : public queue<T>
{
public:
	void enqueue(T* data, int distanceWeight, int costWeight, int prepTimeWeight)
	{
		linkedlist<T>* Q = this->q;
		Q->addWithPriority(data, distanceWeight, costWeight, prepTimeWeight);
		this->front = Q->gethead();
		this->rear = Q->gettail();
	}
};