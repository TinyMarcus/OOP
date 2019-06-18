#ifndef MATRIX_ITERATOR_HPP
#define MATRIX_ITERATOR_HPP

template <typename T>
T& matrix_iterator<T>::operator*() const
{
    if (ptr.expired() || ptr.lock() == nullptr || &ptr.lock().use_count == 0) throw bad_iterator_exception();
    return ptr.lock().get()[cur_ind];
}

template <typename T>
T& matrix_iterator<T>::operator*()
{
    if (ptr.expired() || ptr.lock() == nullptr || &ptr.lock().use_count == 0) throw bad_iterator_exception();
    return ptr.lock().get()[cur_ind];
}

template <typename T>
T* matrix_iterator<T>::operator ->() const
{
    if (ptr.expired() || ptr.lock() == nullptr || ptr.lock().use_count == 0) throw bad_iterator_exception();
    return ptr.lock().get() + cur_ind;
}

template <typename T>
T* matrix_iterator<T>::operator ->()
{
    if (ptr.expired() || ptr.lock() == nullptr || ptr.lock().use_count == 0) throw bad_iterator_exception();
    return ptr.lock().get() + cur_ind;
}

template <typename T>
matrix_iterator<T>::operator bool() const
{
    return !(ptr.expired() || ptr.lock() == nullptr || &ptr.lock().use_count == 0);
}

template <typename T>
bool matrix_iterator<T>::operator !=(matrix_iterator const& iter) const
{
    return cur_ind != iter.cur_ind;
}

template <typename T>
bool matrix_iterator<T>::operator ==(matrix_iterator const& iter) const
{
    return cur_ind == iter.cur_ind;
}

template <typename T>
matrix_iterator<T>& matrix_iterator<T>::operator ++()
{
    if (++cur_ind > length) throw iterator_out_of_range_exception();
    return *this;
}

template <typename T>
matrix_iterator<T> matrix_iterator<T>::operator ++(int)
{
    if (++cur_ind > length) throw iterator_out_of_range_exception();
    return *this;
}

template <typename T>
matrix_iterator<T>& matrix_iterator<T>::operator --()
{
    if (--cur_ind < 0) throw iterator_out_of_range_exception();
    return *this;
}

template <typename T>
matrix_iterator<T> matrix_iterator<T>::operator --(int)
{
    if (--cur_ind < 0) throw iterator_out_of_range_exception();
    return *this;
}

#include "matrix_iterator.h"

#endif
