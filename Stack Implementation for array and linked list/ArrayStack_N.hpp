#ifndef ARRAYSTACK_N_HPP_INCLUDED
#define ARRAYSTACK_N_HPP_INCLUDED



#endif // ARRAYSTACK_N_HPP_INCLUDED

template<class T>
class ArrayStack_1 : public StackADT<T> {

private:
T *arrayStack;
int index;
int maxSize;

public:
// a constructor for the arrayStack that creates and arrayStack of a given size
ArrayStack_1(int size = DEFAULT_SIZE) {
    maxSize = size;
    index = 0;
    arrayStack = new T[size];
}

public:

// a constructor for the arrayStack that creates and arrayStack of a given size
ArrayStack_1(int size = DEFAULT_SIZE) {
    maxSize = size;
    index = 0;
    arrayStack = new T[size];
}

//a destructor that deletes the arrayStack
~ArrayStack_1() {
    delete[] arrayStack;
}

bool Empty() {
    return index==0;
}

void Push(T& item = 0) {
    if (index<maxSize) {
        arrayStack[index]= item;
        index+=1;
    }else {
        T* arrayStack = new T[maxSize]; //making a copy of the array stack
        maxSize+=1;
        arrayStack = new T[++maxSize];

        for (int i=0; i<maxSize; i++){
            arrayStack[i]=tempArrayStack[i];
        }
        arrayStack[index++]=item;
        index+=1;
        delete[] tempArrayStack;

    }
}

T Pop() {
        if([index]==0){
            return 0;
        }else {
            T element = arrayStack[index];
            index--;
            return element;
        }

   }
}
