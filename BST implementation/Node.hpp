/*
 * Node.hpp
 *
 *  Created on: Oct 15, 2015
 *      Author: Akuma Akuma-Ukpo
 */

#ifndef NODE_HPP_
#define NODE_HPP_


template<class T> class LinkedList;
template<class T> class Node{
public:
	T data;
	Node<T>* next;
public:
	Node(const T& obj, Node<T>* n){
		data = obj;
		next = n;
	}

~Node(){};


};
#endif /* NODE_HPP_ */
