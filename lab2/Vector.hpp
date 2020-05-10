#include <iostream>
#include <vector>
#include <math.h>
#include <memory>
#include <time.h>

#include "Vector.h"
#include "Errors.h"


template<typename DataType>
Vector<DataType> Vector<DataType>::norm() const
{
    for (size_t i = 0; i < size(); i++)
        coords.get()[i] = coords.get()[i] / length();
    return *this;
}

template<typename DataType>
DataType Vector<DataType>::angle(const Vector<DataType> &other) const
{
    DataType angle = 1;
	time_t t_time = time(NULL);	
    if (size() != other.size()) {
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));
    }
    for (int i = 0; i < size(); i++)
        angle = angle + (coords.get()[i] * other.coords.get()[i]);
    return angle / (length() * other.length());
}

template<typename DataType>
Vector<DataType>::Vector(const std::vector<DataType> &data)
{
    setSize(data.size());
    coords = std::shared_ptr<DataType>((DataType *)malloc(data.size() * sizeof(DataType)), free);
    
	time_t t_time = time(NULL);
    if (coords.get() == nullptr) {
		throw MemoryError(__FILE__, __LINE__, ctime(&t_time));
    }
    
    for (size_t i = 0; i < data.size(); i++)
        coords.get()[i] = data[i];
}

template<typename DataType>
Vector<DataType>::Vector(DataType* data)
{
    setSize(data->size());
    coords = std::shared_ptr<DataType>((DataType *)malloc(data->size() * sizeof(DataType)), free);

	time_t t_time = time(NULL);
    if (coords.get() == nullptr) {
		throw MemoryError(__FILE__, __LINE__, ctime(&t_time));
    }
    
    for (size_t i = 0; i < data->size(); i++)
        coords.get()[i] = data[i];
}

template<typename DataType>
Vector<DataType>::Vector()
{
    setSize(0);
    coords = std::shared_ptr<DataType>((DataType *)malloc(0 * sizeof(DataType)), free);
	time_t t_time = time(NULL);

    if (coords.get() == nullptr) {
		throw MemoryError(__FILE__, __LINE__, ctime(&t_time));

    }
}

template<typename DataType>
Vector<DataType>::Vector(Vector<DataType> &&other)
{
    setSize(other.size());
    coords = std::shared_ptr<DataType>((DataType *)malloc(other.size() * sizeof(DataType)), free);
	time_t t_time = time(NULL);

    if (coords.get() == nullptr) {
		throw MemoryError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    for (size_t i = 0; i < other.size(); i++)
        coords.get()[i] = other[i];
    other.coords = nullptr;
    other.resize(0);
}

template<typename DataType>
Vector<DataType>::Vector(size_t size)
{
    setSize(size);
    coords = std::shared_ptr<DataType>((DataType *)malloc(size * sizeof(DataType)), free);
	time_t t_time = time(NULL);

    if (coords.get() == nullptr) {
		throw MemoryError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    for (size_t i = 0; i < size; i++)
        coords.get()[i] = 0;
}

template<typename DataType>
Vector<DataType>::Vector(std::initializer_list<DataType> data)
{
    setSize(data.size());
    coords = std::shared_ptr<DataType>((DataType *)malloc(data.size() * sizeof(DataType)), free);
	time_t t_time = time(NULL);

    if (coords.get() == nullptr) {
		throw MemoryError(__FILE__,  __LINE__, ctime(&t_time));

    }
    
    size_t i = 0;
    for(auto& coord : data)
    {
        coords.get()[i] = coord;
        i++;
    }
}

template<typename DataType>
Vector<DataType>::Vector(const Vector<DataType> &other)
{
    setSize(other.size());
    coords =  std::shared_ptr<DataType>((DataType *)malloc(other.size() * sizeof(DataType)), [=](DataType *rawCoords)
                                        {
                                            free(rawCoords);
                                        });
	time_t t_time = time(NULL);

    if (coords.get() == nullptr) {
		throw MemoryError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    for (size_t i = 0; i < other.size(); i++)
        coords.get()[i] = other[i];
}

template<typename DataType>
Vector<DataType>::~Vector()
{
}

//template<typename DataType>
//void Vector<DataType>::resize(size_t newSize)
//{
//    VectorBase::resize(newSize);
//    coords = (DataType *)realloc(coords, newSize * sizeof(DataType));
//
//    if (coords == NULL) {
//        throw MemoryError();
//    }
//}

template<typename DataType>
Vector<DataType> & Vector<DataType>::operator += (const Vector<DataType> &other)
{
	time_t t_time = time(NULL);

    if (size() != other.size()) {
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    for (size_t i = 0; i < size(); i++)
        coords.get()[i] += other.coords.get()[i];
    return *this;
}

template<typename DataType>
Vector<DataType> & Vector<DataType>::operator -= (const Vector<DataType> &other)
{
	time_t t_time = time(NULL);

    if (size() != other.size()) {
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    for (size_t i = 0; i < size(); i++)
        coords.get()[i] -= other.coords.get()[i];
    return *this;
}

template<typename DataType>
Vector<DataType> & Vector<DataType>::operator *= (DataType k)
{
    for (size_t i = 0; i < size(); i++)
        coords.get()[i] *= k;
    return *this;
}

template<typename DataType>
Vector<DataType> Vector<DataType>::vectorMult (const Vector<DataType> &other) const
{
	time_t t_time = time(NULL);

    if (size() != other.size()) {
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }

    for (size_t i = 0; i < size(); i++)
        coords.get()[i] *= other.coords.get()[i];
    return *this;
}

template<typename DataType>
Vector<DataType> & Vector<DataType>::operator /= (DataType k)
{
	time_t t_time = time(NULL);

    if (k == 0.) {
		throw DivisionByZeroError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    for (size_t i = 0; i < size(); i++)
        coords.get()[i] /= k;
    return *this;
}

template<typename DataType>
bool Vector<DataType>::operator == (const Vector<DataType> &other) const
{
	time_t t_time = time(NULL);

    if (size() != other.size()) {
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    bool equal = true;
    for (size_t i = 0; i < size(); i++) {
        if (coords.get()[i] != other.coords.get()[i]) {
            equal = false;
            break;
        }
    }
    
    return equal;
}

template<typename DataType>
bool Vector<DataType>::operator != (const Vector<DataType> &other) const
{
	time_t t_time = time(NULL);

    if (size() != other.size()) {
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    return ! (*this == other);
}

template<typename DataType>
bool Vector<DataType>::operator >= (const Vector<DataType> &other) const
{
	time_t t_time = time(NULL);

    if (size() != other.size()) {
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    return length() >= other.length();
}

template<typename DataType>
bool Vector<DataType>::ort(const Vector<DataType> &other) const
{
	time_t t_time = time(NULL);
    if (size() != other.size()) {
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    DataType sum = 0;
    for (size_t i = 0; i < size(); i++)
        sum += this->coords.get()[i]*other.coords.get()[i];
    return (sum == 0);
}

template<typename DataType>
DataType Vector<DataType>::operator * (const Vector<DataType> &other) const
{
	time_t t_time = time(NULL);
    if (size() != other.size()) {
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    DataType sum = 0;
    for (size_t i = 0; i < size(); i++)
        sum += coords.get()[i] * other.coords.get()[i];
    return sum;
}

template<typename DataType>
bool Vector<DataType>::operator <= (const Vector<DataType> &other) const
{
	time_t t_time = time(NULL);

    if (size() != other.size()) {
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    return length() <= other.length();
}

template<typename DataType>
DataType Vector<DataType>::length() const
{
    DataType sum = 0;

    for (size_t i = 0; i < size(); i++)
        sum += coords.get()[i] * coords.get()[i];
    sum = sqrt(sum);

    return sum;
}

template<typename DataType>
Vector<DataType> & Vector<DataType>::operator = (const Vector<DataType> &other)
{
	time_t t_time = time(NULL);

    if (size() != other.size()) {
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    for (size_t i = 0; i < size(); i++)
        this->coords.get()[i] = other.coords.get()[i];
    
    return *this;
}

template<typename DataType>
Vector<DataType> & Vector<DataType>::operator = (Vector<DataType> &&other)
{
	time_t t_time = time(NULL);

    if (size() != other.size()) {
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    for (size_t i = 0; i < size(); i++)
        this->coords.get()[i] = other.coords.get()[i];
    
    other.coords = nullptr;
    other.resize(0);
    return *this;
}

template<typename DataType>
Vector<DataType> & Vector<DataType>::operator = (std::initializer_list<DataType> data)
{
	time_t t_time = time(NULL);

    if (size() != data.size()) {
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    int i = 0;
    for(auto& coord : data)
    {
        coords.get()[i] = coord;
        i++;
    }
    
    return *this;
}

template<typename DataType>
Vector<DataType> Vector<DataType>::operator +(const Vector<DataType> &other) const
{
	time_t t_time = time(NULL);

    if (size() != other.size()) {
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    Vector<DataType> tmp(*this);
    
    for (size_t i = 0; i < size(); i++)
        tmp.coords.get()[i] += other.coords.get()[i];
    
    return tmp;
}

template<typename DataType>
Vector<DataType> Vector<DataType>::operator - (const Vector<DataType> &other) const
{
	time_t t_time = time(NULL);

    if (size() != other.size()) {
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    Vector<DataType> tmp(*this);
    
    for (size_t i = 0; i < size(); i++)
        tmp.coords.get()[i] -= other.coords.get()[i];
    
    return tmp;
}

template<typename DataType>
inline Vector<DataType> Vector<DataType>::operator-() const
{
	return Vector<DataType>();
}

template<typename DataType>
Vector<DataType> Vector<DataType>::operator / (DataType k) const
{
	time_t t_time = time(NULL);

    if (k == 0.) {
		throw DivisionByZeroError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    Vector<DataType> tmp(*this);
    return tmp /= k;
}

template<typename DataType>
Vector<DataType> Vector<DataType>::operator *(DataType k) const
{
    Vector<DataType> tmp(*this);
    return tmp *= k;
}

template<typename DataType>
Vector<DataType> Vector<DataType>::operator -()
{
    Vector<DataType> tmp(*this);
    return tmp *= -1;
}

template<typename DataType>
Vector<DataType> Vector<DataType>::operator +()
{
    Vector<DataType> tmp(*this);
    return tmp *= 1;
}

template<typename DataType>
DataType & Vector<DataType>::operator [](std::size_t i)
{
	time_t t_time = time(NULL);

    if ((i < 0) || (i >= size())) {
		throw BoundariesError(__FILE__, __LINE__, ctime(&t_time));

    }
    return coords.get()[i];
}

template<typename DataType>
const DataType & Vector<DataType>::operator [](std::size_t i) const
{
	time_t t_time = time(NULL);

    if ((i < 0) || (i >= size())) {
		throw BoundariesError(__FILE__, __LINE__, ctime(&t_time));

    }
    return coords.get()[i];
}


template <typename DataType>
Iterator<DataType> Vector<DataType>::begin()
{
    Iterator<DataType> it(*this);
    return it;
}

template <typename DataType>
Iterator<DataType> Vector<DataType>::end()
{
    return Iterator<DataType>(*this, size());
}

template <typename DataType>
IteratorConst<DataType> Vector<DataType>::begin() const
{
    return IteratorConst<DataType>(coords.get());
}

template <typename DataType>
IteratorConst<DataType> Vector<DataType>::end() const
{
    return IteratorConst<DataType>(coords + size());
}


