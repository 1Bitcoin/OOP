#ifndef ITERATORCONST_H
#define ITERATORCONST_H


#include <iostream>
#include <memory>
#include "IteratorBase.h"
#include <ctime>


#include "IteratorBase.h"
#include "Errors.h"


template<class Type>
class Vector;

template <typename DataType>
class IteratorConst : public IteratorBase
{
private:
      std::weak_ptr<DataType> ptr;

public:
    IteratorConst(const IteratorConst<DataType>& iter);
    IteratorConst(const Vector<DataType>& vec, size_t index = 0);

    const DataType& operator*() const;
    const DataType *operator->() const;

    operator bool() const;

    IteratorConst<DataType>& operator=(const IteratorConst<DataType>& iter);

    IteratorConst<DataType>& operator+=(int n);
    IteratorConst<DataType> operator+(int n) const;
    IteratorConst<DataType>& operator++();
    IteratorConst<DataType> operator++(int);

    IteratorConst<DataType>& operator-=(int n);
    IteratorConst<DataType> operator-(int n) const;
    IteratorConst<DataType>& operator--();
    IteratorConst<DataType> operator--(int);

    bool operator<=(const IteratorConst<DataType>& b) const;
    bool operator<(const IteratorConst<DataType>& b) const;
    bool operator>=(const IteratorConst<DataType>& b) const;
    bool operator>(const IteratorConst<DataType>& b) const;
    bool operator==(const IteratorConst<DataType>& b) const;
    bool operator!=(const IteratorConst<DataType>& b) const;

    bool control(int string) const;
};

template <typename DataType>
IteratorConst<DataType>::IteratorConst(const Vector<DataType>& vec, size_t index)
{
    num_elem = vec.num_elem;
    ptr = vec.coords;
    position = index;
}

template <typename DataType>
IteratorConst<DataType>::IteratorConst(const IteratorConst<DataType>& iter)
{
    ptr = iter.ptr;
    position = iter.index;
    num_elem = iter.num_elem;
}

template <typename DataType>
const DataType& IteratorConst<DataType>::operator*() const
{
    control(__LINE__);

    auto thisPtr = this->ptr.lock();

    DataType *rawData = thisPtr.get();
    DataType *pointedData = rawData + this->position;

    return *(pointedData);
}

template <typename DataType>
const DataType *IteratorConst<DataType>::operator->() const
{
    control(__LINE__);

    auto thisPtr = this->ptr.lock();

    DataType *rawData = thisPtr.get();
    DataType *pointedData = rawData + this->position;
    return pointedData;
}

template <typename DataType>
IteratorConst<DataType>::operator bool() const
{
    control(__LINE__);

    auto thisPtr = this->num_elem.lock();
    if (position >= *thisPtr || position < 0 || (*thisPtr == 0))
        return false;
    else
        return true;
}


template <typename DataType>
IteratorConst<DataType>& IteratorConst<DataType>::operator=(const IteratorConst<DataType>& iter)
{
    control(__LINE__);

    ptr = iter.ptr;
    return *this;
}

template <typename DataType>
IteratorConst<DataType>& IteratorConst<DataType>::operator+=(int n)
{
    control(__LINE__);
    ptr += n;

    return *this;
}

template <typename DataType>
IteratorConst<DataType> IteratorConst<DataType>::operator+(int n) const
{
    control(__LINE__);
    IteratorConst<DataType> iter(*this);
    iter += n;

    return iter;
}

template <typename DataType>
IteratorConst<DataType> IteratorConst<DataType>::operator++(int)
{
    control(__LINE__);
    ++(*this);

    return *this;
}

template <typename DataType>
IteratorConst<DataType>& IteratorConst<DataType>::operator++()
{
    control(__LINE__);
    ++position;

    return *this;
}

template <typename DataType>
IteratorConst<DataType>& IteratorConst<DataType>::operator-=(int n)
{
    control(__LINE__);
    position -= n;

    return *this;
}

template <typename DataType>
IteratorConst<DataType> IteratorConst<DataType>::operator-(int n) const
{
    control(__LINE__);

    IteratorConst<DataType> iter(*this);
    iter -= n;

    return iter;
}

template <typename DataType>
IteratorConst<DataType> IteratorConst<DataType>::operator--(int)
{
    control(__LINE__);
    --(*this);

    return *this;
}

template <typename DataType>
IteratorConst<DataType>& IteratorConst<DataType>::operator--()
{
    control(__LINE__);
    --position;

    return *this;
}

template <typename DataType>
bool IteratorConst<DataType>::operator<=(const IteratorConst<DataType>& b) const
{
    control(__LINE__);

    return ptr <= b.ptr;
}

template <typename DataType>
bool IteratorConst<DataType>::operator<(const IteratorConst<DataType>& b) const
{
    control(__LINE__);

    return ptr < b.ptr;
}

template <typename DataType>
bool IteratorConst<DataType>::operator>=(const IteratorConst<DataType>& b) const
{
    control(__LINE__);

    return ptr >= b.ptr;
}

template <typename DataType>
bool IteratorConst<DataType>::operator>(const IteratorConst<DataType>& b) const
{
    control(__LINE__);

    return ptr > b.ptr;
}

template <typename DataType>
bool IteratorConst<DataType>::operator==(const IteratorConst<DataType>& b) const
{
    control(__LINE__);

    return ptr == b.ptr;
}

template <typename DataType>
bool IteratorConst<DataType>::operator!=(const IteratorConst<DataType>& b) const
{
    control(__LINE__);

    return ptr != b.ptr;
}

template <typename DataType>
bool IteratorConst<DataType>::control(int string) const
{
    if (!ptr.expired())
        return true;

    time_t t_time = time(NULL);
    throw DeletedObj(__FILE__, string, ctime(&t_time));
    return false;
}

#endif // ITERATORCONST_H
