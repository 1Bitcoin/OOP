#ifndef VectorBase
#define VectorBase_h

#include <stdio.h>
#include <memory>

class VectorBase 
{ 
public:
	VectorBase() { _size = std::shared_ptr<size_t>(new size_t(0)); };
	virtual ~VectorBase() = 0;

	void resize(size_t newSize) { setSize(newSize); };

	bool is_empty() const { return size() == 0; };
	virtual size_t size() const { return bool(_size) ? *_size : 0; };

protected:
	std::shared_ptr<size_t> _size;
	void setSize(size_t newSize) { *_size = newSize; };
};

VectorBase::~VectorBase() {}; // in cpp

#endif /* VectorBase_h */