#ifndef IteratorBase_h
#define IteratorBase_h

#include <iostream>
#include <memory>

class IteratorBase
{
public:
	IteratorBase(size_t size = 0) {  position = 0; }
	IteratorBase(const IteratorBase& iter) { this->num_elem = iter.num_elem; this->position = iter.position; }

	virtual ~IteratorBase() {};

protected:
    std::weak_ptr<size_t> num_elem;
    size_t position = 0;
};

#endif /* IteratorBase_h */
