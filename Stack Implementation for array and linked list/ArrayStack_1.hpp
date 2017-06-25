
#ifndef _ARRAYSTACK_1_HPP_
#define _ARRAYSTACK_1_HPP_

#include <stddef.h>
#include "StackADT.h"
#define DEFAULT_SIZE 50



template<class T>
class ArrayStack_1 : public StackADT<T> {      // accessing functions in stack adt

private:  // accessible only by class it is defined in
T *arrayStack; // stores variable array-stack as pointer (saves in memory address)
int index; // creates variable for position
int maxSize; // variable for capacity of array

public:
// a constructor for the arrayStack that creates and arrayStack of a given size
ArrayStack_1(int size = DEFAULT_SIZE) {  // arrays tack takes in an integer size, this size is initialized to the default size of 50
    maxSize = size; //max size is the size of the array
    index = 0;  //starting index is 0
    arrayStack = new T[size]; // Create new array-stack with new size
}


//a destructor that deletes the arrayStack
~ArrayStack_1() {
    delete[] arrayStack;
}

// true/false condition to determine if stack is empty. returns true if stack index is still 0
bool Empty() {
    return index==0;
}

void Push(T& item = 0) { //takes in array with 0 items
    if (index<maxSize) // if there is still space in the index of 50
        {
        arrayStack[index]= item; // set index of array stack to a new item
        index+=1; //increment
    }else {
        T* tempArrayStack = arrayStack; //making a copy of the array stack
        maxSize+=1; // increment size
        arrayStack = new T[maxSize]; // create new stack with new max size

//check condition
        for (int i=0; i<maxSize; i++){
            arrayStack[i]=tempArrayStack[i];
        }
        arrayStack[index]=item;
        index+=1;
        delete[] tempArrayStack;

    }
}

T Pop() {
        if(arrayStack[index]==0){
            return 0;
        }else {
            T element = arrayStack[index];
            index--;
            return element;
        }

   }
}
