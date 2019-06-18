#ifndef MATRIX_ITERATOR_CONST_H
#define MATRIX_ITERATOR_CONST_H

#include <memory>

template<typename T>
class const_matrix_iterator : public std::iterator<std::input_iterator_tag, T>
{
public:
    const_matrix_iterator() {}
    const_matrix_iterator(std::shared_ptr<T> ptr, int i, int length) : ptr(ptr), cur_ind(i), length(length) {}

    const T& operator *() const;
    const T* operator ->() const;
    bool operator !=(const_matrix_iterator const& iter) const;
    bool operator ==(const_matrix_iterator const& iter) const;

    const_matrix_iterator<T>& operator ++();
    const_matrix_iterator<T> operator ++(int);
    const_matrix_iterator<T>& operator --();
    const_matrix_iterator<T> operator --(int);

    operator bool() const;
private:
    std::weak_ptr<T> ptr;
    int cur_ind;
    int length;
};

#include "matrix_iterator_const.hpp"

#endif
