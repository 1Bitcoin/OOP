#ifndef IteratorBase_h
#define IteratorBase_h

#include <iostream>

class IteratorBase
{
public:
    IteratorBase();
    IteratorBase(const IteratorBase& iter);

    virtual ~IteratorBase();


protected:
    size_t position = 0;
    int num_elem = 0;
};

IteratorBase::IteratorBase()
{
    position = 0;
    num_elem = 0;
}

IteratorBase::IteratorBase(const IteratorBase& iter)
{
    position = iter.position;
    num_elem = iter.num_elem;
}

IteratorBase::~IteratorBase()
{
}


#endif /* IteratorBase_h */
