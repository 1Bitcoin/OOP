#ifndef VectorBase
#define VectorBase_h

#include <stdio.h>

class VectorBase
{
private:
    size_t _size = 0;
protected:
    void setSize(size_t newSize) { _size = newSize; };
public:
    virtual size_t size() const { return _size; };
    virtual void resize(size_t newSize) { setSize(newSize); };
};


#endif /* VectorBase_h */
