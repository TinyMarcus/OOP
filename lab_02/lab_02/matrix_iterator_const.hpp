#ifndef MATRIX_ITERATOR_CONST_HPP
#define MATRIX_ITREATOR_CONST_HPP

#include "matrix_iterator_const.h"
#include "exceptions.h"

template <typename T>
const T& const_matrix_iterator<T>::operator *() const
{
    if (ptr.expired() || ptr.lock() == nullptr || &ptr.lock().use_count == 0) throw bad_iterator_exception();
    return ptr.lock().get()[cur_ind];
}

template <typename T>
const T* const_matrix_iterator<T>::operator ->() const
{
    if (ptr.expired() || ptr.lock() == nullptr || ptr.lock().use_count == 0) throw bad_iterator_exception();
    return ptr.lock().get() + cur_ind;
}

template <typename T>
bool const_matrix_iterator<T>::operator !=(const_matrix_iterator const& other) const
{
    return cur_ind != other.cur_ind;
}

template <typename T>
const_matrix_iterator<T>::operator bool() const
{
    return !(ptr.expired() || ptr.lock() == nullptr || &ptr.lock().use_count == 0);
}

template <typename T>
bool const_matrix_iterator<T>::operator ==(const_matrix_iterator const& other) const
{
    return cur_ind == other.cur_ind;
}

template <typename T>
const_matrix_iterator<T>& const_matrix_iterator<T>::operator ++()
{
    if (++cur_ind > length) throw iterator_out_of_range_exception();
    return *this;
}

template <typename T>
const_matrix_iterator<T> const_matrix_iterator<T>::operator ++(int)
{
    if (++cur_ind > length) throw iterator_out_of_range_exception();
    return *this;
}

template <typename T>
const_matrix_iterator<T>& const_matrix_iterator<T>::operator --()
{
    if (--cur_ind < 0) throw iterator_out_of_range_exception();
    return *this;
}

template <typename T>
const_matrix_iterator<T> const_matrix_iterator<T>::operator --(int)
{
    if (--cur_ind < 0) throw iterator_out_of_range_exception();
    return *this;
}

#endif
