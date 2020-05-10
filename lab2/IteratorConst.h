#ifndef ITERATORCONST_H
#define ITERATORCONST_H

#include "IteratorBase.h"

template <typename DataType>
class IteratorConst : public IteratorBase<DataType>
{
public:
    IteratorConst(const IteratorConst<DataType>& iter);
    IteratorConst(const std::shared_ptr<DataType> p, size_t position = 0);

    const DataType operator*() const;
    const DataType *operator->() const;
};

template <typename DataType>
IteratorConst<DataType>::IteratorConst(const IteratorConst<DataType>& iter)
{
    this->position = iter.position;
    this->ptr = iter.ptr;
}

template <typename DataType>
IteratorConst<DataType>::IteratorConst(const std::shared_ptr<DataType> p, size_t position)
{
    this->ptr = p;
    this->position = position;
}

template <typename DataType>
const DataType IteratorConst<DataType>::operator*() const
{
    auto thisPtr = this->ptr.lock();
    time_t t_time = time(NULL);

    if (!thisPtr) {
        throw WeakPointerError(__FILE__, __LINE__, ctime(&t_time));

    }

    DataType *rawData = thisPtr.get();
    DataType *pointedData = rawData + this->position;
    return *(pointedData);
}

template <typename DataType>
const DataType *IteratorConst<DataType>::operator->() const
{
    auto thisPtr = this->ptr.lock();
    time_t t_time = time(NULL);

    if (!thisPtr) {
        throw WeakPointerError(__FILE__, __LINE__, ctime(&t_time));

    }

    DataType *rawData = thisPtr.get();
    DataType *pointedData = rawData + this->position;
    return pointedData;
}

#endif // ITERATORCONST_H
