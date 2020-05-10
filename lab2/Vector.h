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
private:
    std::shared_ptr<DataType> coords;

public:
    friend class Iterator<DataType>;

    Vector(const std::vector<DataType> &data);
    Vector();
    Vector(DataType* data);
    Vector(std::initializer_list<DataType> data);
    Vector(const Vector<DataType> &other); //explicit
    Vector(Vector<DataType> &&other);
	Vector(size_t size);

	virtual ~Vector();

	DataType length() const;
	Vector<DataType> norm() const;
	DataType angle(const Vector<DataType> &other) const;
	Vector<DataType> vectorMult(const Vector<DataType> &other) const;

	bool ort(const Vector<DataType> &other) const;
    DataType operator *(const Vector<DataType> &other) const;

	Iterator<DataType> begin();
	Iterator<DataType> end();
    IteratorConst<DataType> begin() const;
    IteratorConst<DataType> end() const;

    Vector<DataType>& operator =(const Vector<DataType> &other);
    Vector<DataType>& operator =(Vector<DataType> &&other);
    Vector<DataType>& operator =(std::initializer_list<DataType> data);

    Vector<DataType>& operator +=(const Vector<DataType> &other);
    Vector<DataType>& operator -=(const Vector<DataType> &other);
    Vector<DataType>& operator *=(DataType k);
    Vector<DataType>& operator /=(DataType k);

	bool operator == (const Vector<DataType> &other) const;
	bool operator != (const Vector<DataType> &other) const;
	bool operator >= (const Vector<DataType> &other) const;
	bool operator <= (const Vector<DataType> &other) const;

	Vector<DataType> operator *(DataType k) const;
	Vector<DataType> operator /(DataType k) const;
	Vector<DataType> operator +(const Vector<DataType> &other) const;
	Vector<DataType> operator -(const Vector<DataType> &other) const;
	Vector<DataType> operator -() const;
	Vector<DataType> operator +() const;
	Vector<DataType> operator -();
	Vector<DataType> operator +();

	DataType & operator [] (std::size_t i);
	const DataType & operator [] (std::size_t i) const;
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
