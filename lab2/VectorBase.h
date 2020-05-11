#ifndef VectorBase
#define VectorBase_h

#include <stdio.h>
#include <memory>

class VectorBase
{ 
protected:
    std::shared_ptr<size_t> _size;
    void setSize(size_t newSize);
public:
    VectorBase(size_t size = 0) { _size = std::shared_ptr<size_t>(new size_t(size)); }
    virtual size_t size() const;
    virtual void resize(size_t newSize);
};

void VectorBase::setSize(size_t newSize)
{
    *_size = newSize; // nullptr??
}

size_t VectorBase::size() const
{
    return bool(_size) ? *_size : 0;
}

void VectorBase::resize(size_t newSize)
{
    setSize(newSize);
}

#endif /* VectorBase_h */
