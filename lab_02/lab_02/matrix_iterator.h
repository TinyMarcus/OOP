#ifndef MATRIX_ITERATOR_H
#define MATRIX_ITERATOR_H

#include <iterator>
#include "exceptions.h"
#include <memory>

// weak_ptr

template<typename T>
class matrix;
template<typename ValueType>
class matrix_iterator;
template<typename ValueType>
class const_matrix_iterator;

template<typename T>
class matrix_iterator : public std::iterator<std::input_iterator_tag, T>
{
public:
    matrix_iterator() {}
    matrix_iterator(std::shared_ptr<T> ptr, int i, int length) : ptr(ptr), cur_ind(i), length(length) {}

    T& operator*() const;
    T* operator->() const;
    T& operator*();
    T* operator->();

    bool operator!=(matrix_iterator const& iter) const;
    bool operator==(matrix_iterator const& iter) const;

    matrix_iterator<T>& operator++();
    matrix_iterator<T> operator++(int);
    matrix_iterator<T>& operator--();
    matrix_iterator<T> operator--(int);

    operator bool() const;
private:
    std::weak_ptr<T> ptr;
    int cur_ind;
    int length;
protected:
    void _check();
};

#include "matrix_iterator.hpp"

#endif
