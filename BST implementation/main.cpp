#include <iostream>
#include "Underflow.h"
#include "QueueADT.h"
#include "Queue.hpp"
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

void RunOnQueue(QueueADT<int>*,int);

int main(int argc,char** argv)
{
	QueueADT<int>* queue=new Queue<int>();
	RunOnQueue(queue,10000000);
    delete queue;
	cout<<"****************************************"<<endl;

}



void EnqueueOfSize(QueueADT<int>* queue,int size)
{
	for (int i=0;i<size;i++)
		queue->Enqueue(i);
	cout<<"Enqueued "<<size<<" records"<<endl;
}

void DequeueOfSize(QueueADT<int>* queue,int size)
{
	while (!queue->Empty())
	{
		queue->Dequeue();
	}
	cout<<"Dequeued "<<size<<" records"<<endl;

}

void RunOnQueue(QueueADT<int>* queue,int maxSize)
{
    for (int i=100;i<maxSize*10;i*=10)
    {
    	clock_t elapsed_time=0;
    	test_time(EnqueueOfSize,elapsed_time).call(queue,i);
    	cout<<"Elapsed Time: "<<elapsed_time<<endl;
    	elapsed_time=0;
    	test_time(DequeueOfSize,elapsed_time).call(queue,i);
    	cout<<"Elapsed Time: "<<elapsed_time<<endl;
    }
}
