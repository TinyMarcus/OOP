#ifndef BASE_ITERATOR_H
#define BASE_ITERATOR_H

#include <memory>

template<typename ValueType>
class base_iterator
{
public:
    base_iterator();
    base_iterator(const base_iterator<ValueType>&);
//    base_iterator(ValueType*);
    virtual ~base_iterator();

    base_iterator<ValueType>& operator =(const base_iterator<ValueType>&);

    base_iterator<ValueType>& operator ++();
    base_iterator<ValueType> operator ++(int);
    base_iterator<ValueType>& operator --();
    base_iterator<ValueType> operator --(int);

    bool operator ==(const base_iterator<ValueType>&) const;
    bool operator !=(const base_iterator<ValueType>&) const;
protected:
    std::weak_ptr<ValueType> ptr;
    size_t ind = 0;

    void _check();
//    ValueType *ptr;
};

#include "base_iterator.hpp"

#endif
