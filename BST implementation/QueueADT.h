
template<class T> class QueueADT
{
public:
	virtual ~QueueADT(){}
	virtual bool Empty()=0;
	virtual void Enqueue(T& item)=0;
	virtual T Dequeue()=0;
};

