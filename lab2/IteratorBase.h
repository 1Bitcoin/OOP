#ifndef IteratorBase_h
#define IteratorBase_h

#include <iostream>
#include <time.h>
#include <memory>

#include "Errors.h"

template <typename DataType>
class IteratorBase
{
public:
    IteratorBase(const IteratorBase<DataType>& iter);
    IteratorBase(std::shared_ptr<DataType> p){ptr = p;}

    virtual ~IteratorBase();

    IteratorBase<DataType>& operator=(const IteratorBase<DataType>& iter);
    IteratorBase<DataType>& operator++();
    IteratorBase<DataType> operator++(int);
    IteratorBase<DataType>& operator--();
    IteratorBase<DataType> operator--(int);

    operator bool() const;

    bool operator <=(const IteratorBase<DataType>& b) const;
    bool operator <(const IteratorBase<DataType>& b) const;
    bool operator >=(const IteratorBase<DataType>& b) const;
    bool operator >(const IteratorBase<DataType>& b) const;
    bool operator ==(const IteratorBase<DataType>& b) const;
    bool operator !=(const IteratorBase<DataType>& b) const;
    
    bool operator ==(const IteratorBase& iter);
    bool operator !=(const IteratorBase& iter);

    bool check(int line) const;
protected:
    std::weak_ptr<DataType> ptr;
    size_t position;
    int num_elem = 0;
};

template <typename DataType>
IteratorBase<DataType>::IteratorBase(const IteratorBase<DataType>& iter) : position(iter.position), num_elem(iter.num_elem)
{
    check(__LINE__);

    ptr = iter.ptr;
}

template <typename DataType>
IteratorBase<DataType>::~IteratorBase()
{
}

template <typename DataType>
IteratorBase<DataType>& IteratorBase<DataType>::operator=(const IteratorBase<DataType>& iter)
{
    check(__LINE__);

    ptr = iter.ptr;
    position = iter.position;
    num_elem = iter.num_elem;
    return *this;
}

template <typename DataType>
IteratorBase<DataType>& IteratorBase<DataType>::operator++()
{
    check(__LINE__);

    ++position;
    return *this;
}

template <typename DataType>
IteratorBase<DataType> IteratorBase<DataType>::operator++(int)
{
    check(__LINE__);

    IteratorBase<DataType> tmp(*this);
    this->operator++();
    return tmp;
}

template <typename DataType>
IteratorBase<DataType>& IteratorBase<DataType>::operator--()
{
    check(__LINE__);

    --position;
    return *this;
}

template <typename DataType>
IteratorBase<DataType> IteratorBase<DataType>::operator--(int)
{
    check(__LINE__);

    IteratorBase<DataType> tmp(*this);
    this->operator--();
    return tmp;
}

template <typename DataType>
bool IteratorBase<DataType>::operator==(const IteratorBase &iter)
{
    check(__LINE__);

    auto thisPtr = ptr.lock();
    auto iterPtr = iter.ptr.lock();

    return (thisPtr.get() == iterPtr.get()) && (position == iter.position);
}

template <typename DataType>
bool IteratorBase<DataType>::operator!=(const IteratorBase &iter)
{
    check(__LINE__);

    return !(*this == iter);
}

template <typename DataType>
bool IteratorBase<DataType>::operator<=(const IteratorBase<DataType>& b) const
{
    check(__LINE__);

    return ptr <= b.ptr;
}

template <typename DataType>
bool IteratorBase<DataType>::operator<(const IteratorBase<DataType>& b) const
{
    check(__LINE__);

    return ptr < b.ptr;
}

template <typename DataType>
bool IteratorBase<DataType>::operator>=(const IteratorBase<DataType>& b) const
{
    check(__LINE__);

    return ptr >= b.ptr;
}

template <typename DataType>
bool IteratorBase<DataType>::operator>(const IteratorBase<DataType>& b) const
{
    check(__LINE__);

    return ptr > b.ptr;
}

template <typename DataType>
IteratorBase<DataType>::operator bool() const
{
    check(__LINE__);

    if (position >= num_elem || position < 0 || (num_elem == 0))
        return false;
    else
        return true;
}

template <typename DataType>
bool IteratorBase<DataType>::check(int line) const
{
    if (!ptr.expired())
        return true;

    time_t t_time = time(NULL);
    throw DeletedObj(__FILE__, line, ctime(&t_time));
    return false;
}

#endif /* IteratorBase_h */
