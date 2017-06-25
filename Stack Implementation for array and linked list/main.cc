#include <iostream>
#include "Underflow.h"
#include "StackADT.h"
#include "LinkedListStack.hpp"
#include "ArrayStack_1.hpp"
#include "ArrayStack_N.hpp"
#include "time.h"

using namespace std;
template <typename TFunction>
class Timer
{
public:
    Timer(TFunction function, clock_t& elapsedTime):
        call(function),
        startTime_(::clock()),
        elapsedTime_(elapsedTime)
    {
    }

    ~Timer()
    {
        const clock_t endTime_ = ::clock();
        const clock_t diff = (endTime_ - startTime_);
        elapsedTime_ += diff;
    }

    TFunction call;
private:
    const clock_t startTime_;
    clock_t& elapsedTime_;
};


template <typename TFunction>
Timer<TFunction> test_time(TFunction function, clock_t& elapsedTime)
{
    return Timer<TFunction>(function, elapsedTime);
}

void RunOnStack(StackADT<double>*,int);

int main(int argc,char** argv)
{
	StackADT<double>* llStack=new LinkedListStack<double>();
    cout<<"Linked List"<<endl;
    RunOnStack(llStack,1000000);
    delete llStack;
	cout<<"****************************************"<<endl;

	cout<<"Array Grow by 1"<<endl;
	llStack=new ArrayStack_1<double>();
    RunOnStack(llStack,100000);
    delete llStack;
	cout<<"****************************************"<<endl;
	cout<<"Array Grow by N"<<endl;
	llStack=new ArrayStack_N<double>();
    RunOnStack(llStack,10000000);
    delete llStack;
	cout<<"****************************************"<<endl;

}



void PushOfSize(StackADT<double>* stack,int size)
{
	for (double i=0;i<size;i++)
		stack->Push(i);
	cout<<"Pushed "<<size<<" records onto the stack"<<endl;
}

void PopOfSize(StackADT<double>* stack,int size)
{
	while (!stack->Empty())
	{
		stack->Pop();
	}
	cout<<"Popped "<<size<<" records from the stack"<<endl;

}

void RunOnStack(StackADT<double>* stack,int maxSize)
{
    for (int i=100;i<maxSize*10;i*=10)
    {
    	clock_t elapsed_time=0;
    	test_time(PushOfSize,elapsed_time).call(stack,i);
    	cout<<"Elapsed Time: "<<elapsed_time<<endl;
    	elapsed_time=0;
    	test_time(PopOfSize,elapsed_time).call(stack,i);
    	cout<<"Elapsed Time: "<<elapsed_time<<endl;
    }
}
