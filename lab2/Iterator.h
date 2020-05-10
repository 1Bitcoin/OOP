#ifndef Iterator_h
#define Iterator_h

#include <iostream>
#include "IteratorBase.h"

template <typename DataType>
class Iterator : public IteratorBase<DataType>
{
public:
	Iterator(const Iterator<DataType>& iter);
	Iterator(std::shared_ptr<DataType> p, size_t position = 0);

	DataType& operator*();
	const DataType operator*() const;
	DataType *operator->();
	const DataType *operator->() const;
};

template <typename DataType>
Iterator<DataType>::Iterator(const Iterator<DataType>& iter) : IteratorBase<DataType>(std::shared_ptr<DataType>(iter.ptr))
{
	this->position = iter.position;
}

template <typename DataType>
Iterator<DataType>::Iterator(std::shared_ptr<DataType> p, size_t position) : IteratorBase<DataType>(p)
{
	this->position = position;
}

template <typename DataType>
DataType& Iterator<DataType>::operator*()
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
const DataType Iterator<DataType>::operator*() const
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
DataType *Iterator<DataType>::operator->()
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

template <typename DataType>
const DataType *Iterator<DataType>::operator->() const
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

#endif /* Iterator_h */

