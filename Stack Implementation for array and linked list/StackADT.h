
template<class T>


class StackADT
{
    public:
        virtual ~StackADT(){}
        virtual bool Empty()=0;
        virtual void Push(T& item)=0;
        virtual T Pop()=0;
        virtual T Top()=0;
};

