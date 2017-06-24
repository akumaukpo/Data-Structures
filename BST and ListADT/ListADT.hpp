#ifndef __LISTADT_H__
#define __LISTADT_H__
template <class T,class S>
class ListADT{
public:
	ListADT(){}
	virtual ~ListADT(){}
	virtual bool InsertRecord(const T& item,const S& key)=0;
	virtual T* GetRecord(S keyValue)=0;
	virtual bool EraseRecord(S keyValue)=0;
	virtual bool Empty()=0;
};
#endif
