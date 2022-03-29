#include "queue.h"

template <class T>
class priority_queue : public queue<T>
{
public:
	void enqueue(T data)
	{
		linkedlist<T>* Q = this->q;
		Q->addWithPriority(data);
		this->front = Q->gethead();
		this->rear = Q->gettail();
	}
};