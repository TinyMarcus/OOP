#ifndef BASE_ITERATOR_HPP
#define BASE_ITERATOR_HPP

#include "base_iterator.h"

template<typename ValueType>
void base_iterator<ValueType>::_check()
{
    if (ptr.expired() || ptr.lock().use_count() == 0)
        throw bad_iterator_exception();
}

template<typename ValueType>
base_iterator<ValueType>::base_iterator(const base_iterator<ValueType> &iter)
{
    this->_check();
    this->ptr = iter.ptr;
}

template<typename ValueType>
base_iterator<ValueType>::base_iterator()
{
    this->_check();
    this->ptr = nullptr;
}

//template<typename ValueType>
//base_iterator<ValueType>::base_iterator(ValueType *ptr)
//{
//    this->ptr.lock() = ptr;
//}

template<typename ValueType>
base_iterator<ValueType>::~base_iterator()
{
    this->_check();
    this->ptr.reset();
}

template<typename ValueType>
base_iterator<ValueType>& base_iterator<ValueType>::operator =(const base_iterator<ValueType> &iter)
{
    this->_check();
    if (this != & iter)
    {
        this->ptr = iter.ptr;
    }
    return *this;
}

template<typename ValueType>
base_iterator<ValueType>& base_iterator<ValueType>::operator ++()
{
    this->_check();
    ++this->ind;

    return *this;
}

template<typename ValueType>
base_iterator<ValueType> base_iterator<ValueType>::operator ++(int)
{
    this->_check();
    base_iterator<ValueType> temp(*this);
    this->operator ++();

    return *temp;
}

template<typename ValueType>
base_iterator<ValueType>& base_iterator<ValueType>::operator --()
{
    this->_check();
    --this->ptr;

    return *this;
}

template<typename ValueType>
base_iterator<ValueType> base_iterator<ValueType>::operator --(int)
{
    this->_check();
    base_iterator<ValueType> temp(*this);
    this->operator --();

    return *temp;
}

template<typename ValueType>
bool base_iterator<ValueType>::operator ==(const base_iterator<ValueType>& iter) const
{
    this->_check();
    return this->ind == iter.ind;
}

template<typename ValueType>
bool base_iterator<ValueType>::operator !=(const base_iterator<ValueType>& iter) const
{
    return ind != iter.ind;
}

#endif
