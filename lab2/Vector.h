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

	virtual ~Vector();

	Vector<DataType>& operator =(const Vector<DataType> &other);
	Vector<DataType>& operator =(Vector<DataType> &&other);
	Vector<DataType>& operator =(std::initializer_list<DataType> data);
	Vector<DataType>& operator =(const std::vector<DataType> &data);

	DataType length() const;
	DataType& operator [](std::size_t i);
	const DataType& operator [](std::size_t i) const;

	void norm();
	Vector<DataType>& operator *=(const DataType& k);
	Vector<DataType>& multiply_to_number(const DataType& k);

	Vector<DataType>& operator /=(const DataType& k);
	Vector<DataType>& devide_by_number(const DataType& k);

	Vector<DataType> operator *(const DataType& k) const;
	Vector<DataType> multiply_to_number_with_assigment(const DataType& k);

	Vector<DataType> operator /(const DataType& k) const;
	Vector<DataType> devide_by_number_with_assigment(const DataType& k);

	Vector<DataType> operator -() const;
	Vector<DataType> make_vector_negative() const;

	Vector<DataType> operator +() const;
	Vector<DataType> make_vector_positive() const;

	DataType operator *(const Vector<DataType> &other) const;
	DataType multiply_vector(const Vector<DataType> &other);

	Vector<DataType>& operator +=(const Vector<DataType> &other);
	Vector<DataType>& add_vector(const Vector<DataType> &other);

	Vector<DataType>& operator -=(const Vector<DataType> &other);
	Vector<DataType>& substract_vector(const Vector<DataType> &other);

	Vector<DataType> operator +(const Vector<DataType> &other) const;
	Vector<DataType> add_vector_with_assigment(const Vector<DataType> &other) const;

	Vector<DataType> operator -(const Vector<DataType> &other) const;
	Vector<DataType> substract_vector_with_assigment(const Vector<DataType> &other) const;

	DataType angle(const Vector<DataType> &other) const;
	bool ort(const Vector<DataType> &other) const;
	bool collinear(const Vector<DataType>& vec) const;

	Iterator<DataType> begin(); // на некост.вектор создаем неконст. итератор.
	Iterator<DataType> end();

	IteratorConst<DataType> cbegin(); // на неконст. вектор создаем конст.итератор
	IteratorConst<DataType> cend();

    IteratorConst<DataType> const begin() const; // на конст.вектор создаем конст.вектор
    IteratorConst<DataType> const end() const;

	bool operator ==(const Vector<DataType> &other) const;
	bool operator !=(const Vector<DataType> &other) const;
	bool operator >=(const Vector<DataType> &other) const;
	bool operator <=(const Vector<DataType> &other) const;

private:
	void new_memory(size_t num_elements);
	std::shared_ptr<DataType[]> coords;

};

#endif 
