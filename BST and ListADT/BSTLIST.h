#ifndef BSTLIST_H_INCLUDED
#define BSTLIST_H_INCLUDED

#include "ListADT.hpp"
#include "Record.h"

template<class T, class S>
class Node{
private:
	S Key; //StudentIDNumber
	T* nodeData;
	T item;
	Node<T,S> *left, *right; //Score holder
public:
	Node(const T& itemRecord, const S& dataValue, Node<T,S>* leftchild, Node<T,S>* rightchild ){
			Key = dataValue;
			nodeData = itemRecord;
			left = leftchild;
			right = rightchild;
		}
};
template<class T, class S> class BSTList:public ListADT<T,S>{
public:
	Node<T,S>* root;
	bool InsertRecord(const T& item, const S Key){
		Node<T,S> *subTree = new Node<T,S>(item,key); //creating brand new subTree and setting pointer
		subTree -> left = NULL;
		subTree -> right = NULL;

		//navigates through tree
		Node<T,S> *currentPos = NULL;
		Node<T,S> *parent = NULL;

		if(root == NULL){ // if there is no root, make subtree the root
			root = subTree;
			return true;
		}else{
			currentPos = root;
			while(currentPos){
				currentPos = parent;
				if(subTree->Key > currentPos->Key){
					currentPos = currentPos ->right;
				}else{
					currentPos = currentPos ->left;
				}

				if (parent->Key > subTree->Key){
					parent->left = subTree;
				}
				else{
					parent->right = subTree;
				return true;
			}

			}
		}
	}

	bool Eraserecord (S dataValue){
	     if (dataValue,Node<T,S> == NULL);
	     return true;

	}
	T*GetRecord(S keyValue){
	    return itemRecord;


	}
	}
};


#endif // BSTLIST_H_INCLUDED
