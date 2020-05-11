#ifndef IteratorBase_h
#define IteratorBase_h

#include <iostream>
#include <memory>

class IteratorBase
{
public:
    IteratorBase();
    IteratorBase(const IteratorBase& iter);

    virtual ~IteratorBase();

protected:
    std::weak_ptr<size_t> num_elem;
    size_t position = 0;
};

IteratorBase::IteratorBase()
{
    position = 0;
}

IteratorBase::IteratorBase(const IteratorBase& iter)
{
    this->num_elem = iter.num_elem;
    this->position = iter.position;
}

IteratorBase::~IteratorBase()
{
}


#endif /* IteratorBase_h */
