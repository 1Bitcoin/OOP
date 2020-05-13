#ifndef Iterator_h
#define Iterator_h


#include <iostream>
#include <memory>
#include <ctime>
#include <iterator>

#include "IteratorBase.h"
#include "Errors.h"


template<class DataType>
class Vector;

template <typename DataType>
class Iterator : public IteratorBase, public std::iterator <std::input_iterator_tag, DataType>
{
public:
	Iterator(const Iterator<DataType>& iter);
    Iterator(Vector<DataType>& vec, size_t index = 0);

	DataType& operator*();
    const DataType& operator*() const;
    DataType* operator->();
    const DataType* operator->() const;
	operator bool() const;

    Iterator<DataType>& operator=(const Iterator<DataType>& iter);

	Iterator<DataType>& operator+=(int n);
	Iterator<DataType> operator+(int n);
    Iterator<DataType>& operator++();
    Iterator<DataType> operator++(int);

	Iterator<DataType>& operator-=(int n);
	Iterator<DataType> operator-(int n);
	Iterator<DataType>& operator--();
	Iterator<DataType> operator--(int);

    bool operator<=(const Iterator<DataType>& b) const;
    bool operator<(const Iterator<DataType>& b) const;
    bool operator>=(const Iterator<DataType>& b) const;
    bool operator>(const Iterator<DataType>& b) const;
    bool operator==(const Iterator<DataType>& b) const;
    bool operator!=(const Iterator<DataType>& b) const;

    bool control(int string) const;

private:
	std::weak_ptr<DataType[]> ptr;

};

template <typename DataType>
Iterator<DataType>::Iterator(Vector<DataType>& vec, size_t index)
{
    this->num_elem = vec._size;
    this->ptr = vec.coords;
    this->position = index;
}

template <typename DataType>
Iterator<DataType>::Iterator(const Iterator<DataType>& iter)
{
    this->ptr = iter.ptr;
    this->position = iter.position;
    this->num_elem = iter.num_elem;
}

template <typename DataType>
DataType& Iterator<DataType>::operator*()
{
    control(__LINE__);
	auto thisPtr = this->ptr.lock();

	DataType *rawData = thisPtr.get();
	DataType *pointedData = rawData + this->position;
	return *(pointedData);
}

template <typename DataType>
const DataType& Iterator<DataType>::operator*() const
{
    control(__LINE__);
	auto thisPtr = this->ptr.lock();

	DataType *rawData = thisPtr.get();
	DataType *pointedData = rawData + this->position;
	return *(pointedData);
}

template <typename DataType>
DataType* Iterator<DataType>::operator->()
{
    control(__LINE__);
	auto thisPtr = this->ptr.lock();

	DataType *rawData = thisPtr.get();
	DataType *pointedData = rawData + this->position;

	return pointedData;
}

template <typename DataType>
const DataType* Iterator<DataType>::operator->() const
{
    control(__LINE__);
	auto thisPtr = this->ptr.lock();

	DataType *rawData = thisPtr.get();
	DataType *pointedData = rawData + this->position;

	return pointedData;
}

template <typename DataType>
Iterator<DataType>& Iterator<DataType>::operator=(const Iterator<DataType>& iter)
{
    control(__LINE__);

    this->ptr = iter.ptr;
    this->position = iter.position;
    this->num_elem = iter.num_elem;

    return *this;
}

template <typename DataType>
Iterator<DataType>& Iterator<DataType>::operator++()
{
    control(__LINE__);

    ++position;

    return *this;
}

template <typename DataType>
Iterator<DataType>& Iterator<DataType>::operator+=(int n)
{
	control(__LINE__);
	this->position += n;

	return *this;
}

template <typename DataType>
Iterator<DataType> Iterator<DataType>::operator++(int)
{
    control(__LINE__);

    Iterator<DataType> tmp(*this);
    this->operator++();
    return tmp;
}

template <typename DataType>
Iterator<DataType> Iterator<DataType>::operator+(int n)
{
	control(__LINE__);
	Iterator<DataType> iter(*this);
	iter += n;

	return iter;
}

template <typename DataType>
Iterator<DataType>& Iterator<DataType>::operator--()
{
    control(__LINE__);

    --position;
    return *this;
}

template <typename DataType>
Iterator<DataType> Iterator<DataType>::operator--(int)
{
    control(__LINE__);

    Iterator<DataType> tmp(*this);
    this->operator--();
    return tmp;
}

template <typename DataType>
Iterator<DataType>& Iterator<DataType>::operator-=(int n)
{
	control(__LINE__);
	position -= n;

	return *this;
}

template <typename DataType>
Iterator<DataType> Iterator<DataType>::operator-(int n)
{
	control(__LINE__);

	Iterator<DataType> iter(*this);
	iter.position = this->position - n;

	return iter;
}

template <typename DataType>
Iterator<DataType>::operator bool() const
{
    control(__LINE__);

    auto thisPtr = this->num_elem.lock();

    if (position >= *thisPtr || position < 0 || (*thisPtr == 0))
        return false;
    else
        return true;
}

template <typename DataType>
bool Iterator<DataType>::operator<=(const Iterator<DataType>& b) const
{
    control(__LINE__);

    return ptr <= b.ptr;
}

template <typename DataType>
bool Iterator<DataType>::operator<(const Iterator<DataType>& b) const
{
    control(__LINE__);

    return ptr < b.ptr;
}

template <typename DataType>
bool Iterator<DataType>::operator>=(const Iterator<DataType>& b) const
{
    control(__LINE__);

    return ptr >= b.ptr;
}

template <typename DataType>
bool Iterator<DataType>::operator>(const Iterator<DataType>& b) const
{
    control(__LINE__);

    return ptr > b.ptr;
}

template <typename DataType>
bool Iterator<DataType>::operator==(const Iterator<DataType>& b) const
{
    control(__LINE__);

    auto thisPtr = ptr.lock();
    auto iterPtr = b.ptr.lock();

    return (thisPtr.get() == iterPtr.get()) && (position == b.position);
}

template <typename DataType>
bool Iterator<DataType>::operator!=(const Iterator<DataType>& b) const
{
    control(__LINE__);

    return !(*this == b);
}

template <typename DataType>
bool Iterator<DataType>::control(int string) const
{
    if (!ptr.expired())
        return true;

    time_t t_time = time(NULL);
    throw DeletedObj(__FILE__, string, ctime(&t_time));
    return false;
}

#endif /* Iterator_h */

