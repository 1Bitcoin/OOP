#include <iostream>
#include <vector>
#include <math.h>
#include <memory>
#include <time.h>
#include <cstdlib>

#include "Vector.h"
#include "Errors.h"

#define EPS 1e-5

template<typename DataType>
Vector<DataType> Vector<DataType>::norm() const
{
    if (!length())
    {
        time_t t_time = time(NULL);
        throw DivisionByZeroError(__FILE__, __LINE__, ctime(&t_time));
    }

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

    if (!size() || !other.size()){
        throw EmptyError(__FILE__, __LINE__, ctime(&t_time));
    }

    for (int i = 0; i < size(); i++)
        angle = angle + (coords.get()[i] * other.coords.get()[i]);

    return angle / (length() * other.length());
}

template<typename DataType>
Vector<DataType>::Vector(const std::vector<DataType> &data)
{
    setSize(data.size());
    new_memory(data.size());
    
    if (coords.get() == nullptr) {
        time_t t_time = time(NULL);
		throw MemoryError(__FILE__, __LINE__, ctime(&t_time));
    }
    
    for (size_t i = 0; i < data.size(); i++)
        coords.get()[i] = data[i];
}

template<typename DataType>
Vector<DataType>::Vector(size_t count, DataType* data)
{
    setSize(count);
    new_memory(count);

    if (coords.get() == nullptr) {
        time_t t_time = time(NULL);
        throw MemoryError(__FILE__, __LINE__, ctime(&t_time));
    }

    for (size_t i = 0; i < count; i++)
        coords.get()[i] = data[i];
}

template<typename DataType>
Vector<DataType>::Vector()
{
    setSize(0);
    coords.reset();
    std::shared_ptr<DataType> coords = nullptr;
}

template<typename DataType>
Vector<DataType>::Vector(Vector<DataType> &&other)
{
    this->coords = other.coords;
    this->setSize(other.size());
    other.coords = nullptr;
    other.resize(0);
}

template<typename DataType>
Vector<DataType>::Vector(size_t size)
{
    setSize(size);

    new_memory(size);

    if (coords.get() == nullptr) {
        time_t t_time = time(NULL);
		throw MemoryError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    Iterator<DataType> iter(*this);
    for (; iter; iter++)
        *iter = 0;
}

template<typename DataType>
Vector<DataType>::Vector(std::initializer_list<DataType> data)
{
    setSize(data.size());

    new_memory(data.size());

    if (coords.get() == nullptr) {
        time_t t_time = time(NULL);
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
    new_memory(other.size());

    if (coords.get() == nullptr) {
        time_t t_time = time(NULL);
        throw MemoryError(__FILE__, __LINE__, ctime(&t_time));

    }

    for (size_t i = 0; i < other.size(); i++)
        coords.get()[i] = other[i];
}

template<typename DataType>
Vector<DataType>::~Vector()
{
}

template<typename DataType>
Vector<DataType> & Vector<DataType>::operator += (const Vector<DataType> &other)
{
    if (size() != other.size()) {
        time_t t_time = time(NULL);
        throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }

    for (size_t i = 0; i < size(); i++)
        coords.get()[i] += other.coords.get()[i];

    return *this;
}

template<typename DataType>
Vector<DataType> & Vector<DataType>::operator -= (const Vector<DataType> &other)
{
    if (size() != other.size()) {
        time_t t_time = time(NULL);
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
    if (size() != other.size()) {
        time_t t_time = time(NULL);
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }

    for (size_t i = 0; i < size(); i++)
        coords.get()[i] *= other.coords.get()[i];

    return *this;
}

template<typename DataType>
Vector<DataType> & Vector<DataType>::operator /= (DataType k)
{
    if (abs(k) < EPS) {
        time_t t_time = time(NULL);
		throw DivisionByZeroError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    for (size_t i = 0; i < size(); i++)
        coords.get()[i] /= k;

    return *this;
}

template<typename DataType>
bool Vector<DataType>::operator == (const Vector<DataType> &other) const
{
    if (size() != other.size()) {
        time_t t_time = time(NULL);
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
    if (size() != other.size()) {
        time_t t_time = time(NULL);
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    return ! (*this == other);
}

template<typename DataType>
bool Vector<DataType>::operator >= (const Vector<DataType> &other) const
{
    if (size() != other.size()) {
        time_t t_time = time(NULL);
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    return length() >= other.length();
}

template<typename DataType>
bool Vector<DataType>::ort(const Vector<DataType> &other) const
{
    if (size() != other.size()) {
        time_t t_time = time(NULL);
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }

    DataType sum = 0;

    for (size_t i = 0; i < size(); i++)
        sum += this->coords.get()[i] * other.coords.get()[i];

    return (sum == 0);
}

template<typename DataType>
DataType Vector<DataType>::operator * (const Vector<DataType> &other) const
{;
    if (size() != other.size()) {
        time_t t_time = time(NULL);
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
    if (size() != other.size()) {
        time_t t_time = time(NULL);
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
    if (size() != other.size()) {
        time_t t_time = time(NULL);
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    for (size_t i = 0; i < size(); i++)
        this->coords.get()[i] = other.coords.get()[i];
    
    return *this;
}

template<typename DataType>
Vector<DataType>& Vector<DataType>::operator = (Vector<DataType> &&other)
{
    if (size() != other.size()) {
        time_t t_time = time(NULL);
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    this->coords = other.coords;
    this->setSize(other.size());
    other.coords = nullptr;
    other.resize(0);

    return *this;
}

template<typename DataType>
Vector<DataType> & Vector<DataType>::operator = (std::initializer_list<DataType> data)
{
    if (size() != data.size()) {
        time_t t_time = time(NULL);
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    
    size_t i = 0;
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
    if (size() != other.size()) {
        time_t t_time = time(NULL);
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
    if (size() != other.size()) {
        time_t t_time = time(NULL);
		throw SizeError(__FILE__, __LINE__, ctime(&t_time));

    }
    Vector<DataType> tmp(*this);
    
    for (size_t i = 0; i < size(); i++)
        tmp.coords.get()[i] -= other.coords.get()[i];
    
    return tmp;
}

template<typename DataType>
Vector<DataType> Vector<DataType>::operator-() const
{
	return Vector<DataType>();
}

template<typename DataType>
Vector<DataType> Vector<DataType>::operator / (DataType k) const
{
    if (abs(k) < EPS) {
        time_t t_time = time(NULL);
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
    return Vector<DataType>();
}

template<typename DataType>
DataType& Vector<DataType>::operator [](std::size_t i)
{
    if ((i < 0) || (i >= size())) {
        time_t t_time = time(NULL);
		throw BoundariesError(__FILE__, __LINE__, ctime(&t_time));

    }
    return coords.get()[i];
}

template<typename DataType>
const DataType & Vector<DataType>::operator [](std::size_t i) const
{
    if ((i < 0) || (i >= size())) {
        time_t t_time = time(NULL);
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
    return IteratorConst<DataType>(*this);
}

template <typename DataType>
IteratorConst<DataType> Vector<DataType>::end() const
{
    return IteratorConst<DataType>(*this + size());
}

template <typename DataType>
void Vector<DataType>::new_memory(size_t num_elements)
{
    coords.reset();
    std::shared_ptr<DataType> temp(new DataType[num_elements], std::default_delete<DataType[]>());
    coords = temp;
}
