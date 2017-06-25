/*
 * LinkedList.hpp
 *
 *  Created on: 16 Oct 2015
 *      Author: Akuma Akuma-Ukpo
 */

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_
#ifndef NULL
#define NULL   ((void *) 0)
#endif


#include "Underflow.hpp"
#include "Node.hpp"



template<class T> class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList(){
		head = NULL;
		tail = NULL;
	}
	~LinkedList(){
	for (Node<T>* temp=head; temp!=NULL;)
	{
		Node<T>* next = temp-> next;
		delete temp;
		temp = next;
	}
}
	void Enqueue(T& obj){
	Node<T> *temp = new Node<T>;
	temp->data = obj;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
	}
	else{
		tail->next = temp;
	}
	tail = temp;
	}

	void Dequeue(){

		Node<T>* temp = new Node<T>;
		if(head == NULL){
			throw Underflow();
		}
		else{
			temp = head;
			head = head->next;
			delete temp;
		}
	}

	bool check_empty(){
			return (head==NULL);
		}



};
#endif /* LINKEDLIST_HPP_ */

