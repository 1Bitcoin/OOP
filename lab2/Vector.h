#ifndef class_Vector_h
#define class_Vector_h

#include <iostream>
#include <vector>

#include "VectorBase.h"
#include "Iterator.h"
#include "IteratorConst.h"


template<typename DataType>
class Vector : public VectorBase
{
public:
    friend class Iterator<DataType>;
	friend class IteratorConst<DataType>;

    Vector();
	explicit Vector(size_t size);
    Vector(const std::vector<DataType> &data);
    Vector(size_t count, DataType* data);
    Vector(std::initializer_list<DataType> data);
	Vector(Vector<DataType> &&other);
	explicit Vector(const Vector<DataType> &other);

	virtual ~Vector(); // override // err

	Vector<DataType>& operator =(const Vector<DataType> &other);
	Vector<DataType>& operator =(Vector<DataType> &&other);
	Vector<DataType>& operator =(std::initializer_list<DataType> data);
	Vector<DataType>& operator =(const std::vector<DataType> &data);

	DataType length() const;
	DataType& operator [](std::size_t i);
	const DataType& operator [](std::size_t i) const;

	void norm();
	Vector<DataType>& operator *=(DataType k);
	Vector<DataType>& operator /=(DataType k);
	Vector<DataType> operator *(DataType k) const;
	Vector<DataType> operator /(DataType k) const;
	Vector<DataType> operator -() const;
	Vector<DataType> operator +() const;

	DataType operator *(const Vector<DataType> &other) const;
	Vector<DataType>& operator +=(const Vector<DataType> &other);
	Vector<DataType>& operator -=(const Vector<DataType> &other);
	Vector<DataType> operator +(const Vector<DataType> &other) const;
	Vector<DataType> operator -(const Vector<DataType> &other) const;

	DataType angle(const Vector<DataType> &other) const;
	bool ort(const Vector<DataType> &other) const;
	bool collinear(const Vector<DataType>& vec) const;

	Iterator<DataType> begin();
	Iterator<DataType> end();

	IteratorConst<DataType> cbegin();
	IteratorConst<DataType> cend();

    IteratorConst<DataType> const cbegin() const;
    IteratorConst<DataType> const cend() const;

	bool operator ==(const Vector<DataType> &other) const;
	bool operator !=(const Vector<DataType> &other) const;
	bool operator >=(const Vector<DataType> &other) const;
	bool operator <=(const Vector<DataType> &other) const;

    void new_memory(size_t num_elements);

private:
	std::shared_ptr<DataType[]> coords;

};

template<class DataType>
std::ostream & operator <<(std::ostream &os, const Vector<DataType> &vector)
{
	os << "\n" << "Vector<" << typeid(DataType).name() << "> { ";
	for (size_t i = 0; i < vector.size(); i++)
	{
		os << vector[i];
		if (i != vector.size() - 1) {
			os << ", ";
		}
	}
	os << " }" << std::endl;
	return os;
}

#endif 
