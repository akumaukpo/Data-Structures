/*
 * Queue.hpp
 *
 *  Created on: Oct 14, 2015
 *      Author: Akuma Akuma-Ukpo
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include "LinkedList.hpp"

template<class T> class Queue:public QueueADT<T>
{
private:
	LinkedList<T> list;

public:
	Queue(){}
	~Queue(){}

	bool Empty(){
			return list.check_empty();
		};
	void Enqueue(T& item){
		list.Enqueue(item);
	}
	T Dequeue(){
		return list.Dequeue();
	}


};


#endif /* QUEUE_HPP_ */
