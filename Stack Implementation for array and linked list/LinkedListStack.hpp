#ifndef LINKEDLISTSTACK_HPP_INCLUDED
#define LINKEDLISTSTACK_HPP_INCLUDED


template <class Item>
class LinkedListStack
{
  public:
    // Constructor
    LinkedListStack(void)
    : _numberOfItems(0),
      _first(NULL)
    {
    }

    ~LinkedListStack(void)
    {
      // Delete all nodes.
      while(_first)
      {
        SingleNode<Item> *nodeToRemove = _first;
        _first = _first->_next;
        delete nodeToRemove;
      }
    }

    bool Empty(void)
    {
      return _numberOfItems == 0;
    }

    unsigned int size(void)
    {
      return _numberOfItems;
    }

    void push(Item *object)
    {
      SingleNode<Item> *oldFirst = _first;
      _first = new SingleNode<Item>(object);
      _first->_next = oldFirst;

      _numberOfItems++;
    }

    Item* pop(void)
    {
      Item *poppedItem = _first->_object;
      SingleNode<Item> *nodeToRemove = _first;
      _first = _first->_next;
      delete nodeToRemove;

      _numberOfItems--;
      return poppedItem;
    }

  private:
    unsigned int _numberOfItems;
    SingleNode<Item> *_first;
};
#endif
