#include "queue.h"
template <class T>
class priority_queue : public queue<T>
{
public:
	void enqueue(T data)
	{
		this->q->addWithPriority(data);
		this->front = this->q->gethead();
		this->rear = this->q->gettail();
	}
};