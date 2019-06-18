#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "matrix.h"
#include "exceptions.h"
#include <time.h>

template<typename T>
class matrix;

template<typename T>
matrix<T>::matrix(unsigned int n, unsigned int m) : base_container()
{
    if (n == 0 || m == 0) throw matr_wrong_size_exception();

    this->n = n;
    this->m = m;
    this->element_count = n * m;

    try
    {
        //data = new T[n*m];
        data = std::make_shared<T> (n*m);
    }
    catch (std::bad_alloc)
    {
        throw memory_allocate_exception();
    }
}

template<typename T>
matrix<T>::matrix(const matrix<T>& matr) : base_container()
{
    this->n = matr.get_n();
    this->m = matr.get_m();
    this->element_count = matr.size();
    try
    {
        //this->data = new T[n*m];
        this->data = std::shared_ptr<T>(n*m);
    }
    catch (std::bad_alloc)
    {
        throw memory_allocate_exception();
    }

    for (unsigned int i = 0; i < n; ++i)
    {
        for (unsigned int j = 0; j < m; ++j)
        {
            this->data.get()[i*m+j] = matr.data.get()[i*m+j];
        }
    }
}

template<typename T>
matrix<T>::matrix(matrix<T>&& matr)
{
    this->n = matr.get_n();
    this->m = matr.get_m();
    this->element_count = matr.size();
    try
    {
        //this->data = new T[n*m];
        this->data = std::make_shared<T>(n*m);
    }
    catch (std::bad_alloc)
    {
        throw memory_allocate_exception();
    }

    for (unsigned int i = 0; i < n; ++i)
    {
        for (unsigned int j = 0; j < m; ++j)
        {
            this->data.get()[i*m+j] = matr.data.get()[i*m+j];
        }
    }
}

template<typename T>
matrix<T>::matrix(std::initializer_list<std::initializer_list<T>> lst):base_container()
{
    this->n = lst.size();
    this->m = lst.begin()->size();
    auto iter = lst.begin();
    try
    {
        //this->data = new T[n*m];
        this->data = std::make_shared<T>(n*m);
    }
    catch (std::bad_alloc)
    {
        throw memory_allocate_exception();
    }

    if (lst.size() != n) throw matr_wrong_size_exception();

    for (unsigned int i = 0; iter != lst.end(); ++iter, ++i)
    {
        if (m != iter->size()) throw matr_wrong_size_exception();

        unsigned int j = 0;
        for (auto in_iter = iter->begin(); in_iter != iter->end(); ++in_iter, ++j)
        {
            this->data.get()[i*m+j] = *in_iter;
        }
    }
    this->element_count = this->n * this->m;
}


template<typename T>
matrix<T>::~matrix()
{
    data = nullptr;
    n = 0;
    m = 0;
}

template<typename T>
matrix<T>& matrix<T>::operator =(const matrix<T>& matr)
{
    (*this) = matrix(matr);
    return *this;
}

template<typename T>
matrix<T>& matrix<T>::operator +=(const matrix<T>& matr)
{
    if (this->get_n() != matr.get_n() || this->get_m() != matr.get_m()) throw matr_sizes_exception();

    unsigned int n = this->get_n();
    unsigned int m = this->get_m();
    for (unsigned int i = 0; i < n; ++i)
    {
        for (unsigned int j = 0; j < m; ++j)
        {
            this->data.get()[i*m+j] = this->data.get()[i*m+j] + matr.data.get()[i*m+j];
        }
    }
    return *this;
}


template<typename T>
matrix<T>& matrix<T>::operator -=(const matrix<T>& matr)
{
    if (this->get_n() != matr.get_n() || this->get_m() != matr.get_m()) throw matr_sizes_exception();

    unsigned int n = this->get_n();
    unsigned int m = this->get_m();
    for (unsigned int i = 0; i < n; ++i)
    {
        for (unsigned int j = 0; j < m; ++j)
        {
            this->data[i*m+j] = this->data[i*m+j] - matr.data[i*m+j];
        }
    }
    return *this;
}



template<typename _T>
matrix<_T> matrix<_T>::operator +(const matrix<_T>& matr) const
{
    if (this->get_n() != matr.get_n() || this->get_m() != matr.get_m()) throw matr_sizes_exception();

    unsigned int n = this->get_n();
    unsigned int m = this->get_m();
    matrix<_T> res = matrix<_T>(n, m);
    for (unsigned int i = 0; i < n; ++i)
    {
        for (unsigned int j = 0; j < m; ++j)
        {
            res.data[i*m+j] = this->data[i*m+j] + matr.data[i*m+j];
        }
    }
    return res;
}

template<typename _T>
matrix<_T> matrix<_T>::operator -(const matrix<_T>& matr)
{
    if (this->get_n() != matr.get_n() || this->get_m() != matr.get_m()) throw matr_sizes_exception();

    unsigned int n = this->get_n();
    unsigned int m = this->get_m();
    matrix<_T> res = matrix<_T>(n, m);
    for (unsigned int i = 0; i < n; ++i)
    {
        for (unsigned int j = 0; j < m; ++j)
        {
            res.data[i*m+j] = this->data[i*m+j] - matr.data[i*m+j];
        }
    }
    return res;
}


template<typename _T>
matrix<_T> matrix<_T>::operator *(const matrix<_T>& matr)
{
    if (this->get_m() != matr.get_n()) throw matr_sizes_exception();

    unsigned int n = this->get_n();
    unsigned int m = matr.get_m();
    unsigned int l = this->get_m();

    matrix<_T> res = matrix<_T>(n, m);
    for (unsigned int i = 0; i < n; ++i)
    {
        for (unsigned int j = 0; j < m; ++j)
        {
            res.data.get()[i*m+j] = this->data.get()[i*this->get_m()] * matr.data.get()[j];
            for (unsigned int k = 1; k < l; ++k)
            {
                res.data.get()[i*m+j] += this->data.get()[i*this->get_m()+k] * matr.data.get()[k*matr.get_m()+j];
            }
        }
    }
    return res;
}


template<typename _T>
matrix<_T> operator +(const matrix<_T>& m1, double num)
{
    unsigned int n = m1.get_n();
    unsigned int m = m1.get_m();
    matrix<_T> res = matrix<_T>(n, m);
    for (unsigned int i = 0; i < n; ++i)
    {
        for (unsigned int j = 0; j < m; ++j)
        {
            res.data[i*m+j] = m1.data[i*m+j] + num;
        }
    }
    return res;
}

template<typename _T>
matrix<_T> operator -(const matrix<_T>& m1, double num)
{
    unsigned int n = m1.get_n();
    unsigned int m = m1.get_m();
    matrix<_T> res = matrix<_T>(n, m);
    for (unsigned int i = 0; i < n; ++i)
    {
        for (unsigned int j = 0; j < m; ++j)
        {
            res.data[i*m+j] = m1.data[i*m+j] - num;
        }
    }
    return res;
}

template<typename _T>
matrix<_T> operator *(const matrix<_T>& m1, const _T num)
{
    unsigned int n = m1.get_n();
    unsigned int m = m1.get_m();
    matrix<_T> res = matrix<_T>(n, m);
    for (unsigned int i = 0; i < n; ++i)
    {
        for (unsigned int j = 0; j < m; ++j)
        {
            res.data[i*m+j] = m1.data[i*m+j] * num;
        }
    }
    return res;
}

template<typename _T>
matrix<_T> operator *(const _T num, const matrix<_T>& m1)
{
    unsigned int n = m1.get_n();
    unsigned int m = m1.get_m();
    matrix<_T> res = matrix<_T>(n, m);
    for (unsigned int i = 0; i < n; ++i)
    {
        for (unsigned int j = 0; j < m; ++j)
        {
            res.data[i*m+j] = num * m1.data[i*m+j];
        }
    }
    return res;
}


template<typename _T>
matrix<_T> operator /(const matrix<_T>& m1, _T num)
{
    if (num == 0.0) throw zero_devision_exception();

    unsigned int n = m1.get_n();
    unsigned int m = m1.get_m();
    matrix<_T> res = matrix<_T>(n, m);
    for (unsigned int i = 0; i < n; ++i)
    {
        for (unsigned int j = 0; j < m; ++j)
        {
            res.data[i*m+j] = m1.data[i*m+j] / num;
        }
    }
    return res;
}



template<typename _T>
std::ostream& operator <<(std::ostream& os,  const matrix<_T>& matr)
{
    for (size_t i = 0; i < matr.get_n(); ++i)
    {
        for (size_t j = 0; j < matr.get_m(); ++j)
            os << matr[i][j] << ' ';
        os << std::endl;
    }
    return os;
}


template<typename T>
void matrix<T>::set_elem(unsigned int i, unsigned int j,const T& elem)
{
    if (i < this->get_n() && j < this->get_m()) throw out_of_range_exception();

    this[i][j] = elem;
}


template<typename T>
T& matrix<T>::get_elem(unsigned int i, unsigned int j)
{
    if (i < this->get_n() && j < this->get_m()) throw out_of_range_exception();

    return this[i][j];
}

template<typename T>
T matrix<T>::get_elem(unsigned int i, unsigned int j) const
{
    if (i < this->get_n() && j < this->get_m()) throw out_of_range_exception();

    return this[i][j];
}

template <typename T>
matrix<T> matrix<T>::transpose(void)
{
    if (this->is_empty()) throw is_empty_exception();

    matrix<T> res(this->get_n(), this->get_m());

    for (size_t i = 0; i < res.get_m(); ++i)
        for (size_t j = 0; j < res.get_n(); ++j)
            res[i][j] = (*this)[j][i];
    return res;
}

template <typename T>
matrix<T> matrix<T>::operator !(void)
{
    if (this->is_empty()) throw is_empty_exception();
    return this->transpose();
}

template <typename T>
matrix<T> matrix_det(unsigned int cnt, size_t exclude_row, size_t exclude_column, const matrix<T>& matr)
{
    matrix<T> res(cnt - 1, cnt - 1);
    size_t ki = 0, kj = 0;
    for (size_t i = 0; i < cnt - 1; ++i)
    {
        if (i == exclude_row)
            ki = 1;
        for (size_t j = 0; j < cnt - 1; ++j)
        {
            if (j == exclude_column)
                kj = 1;
            res[i][j] = matr[i + ki][j + kj];
        }
    }
    return res;
}

template <typename T>
T determinant_value(const size_t count, const matrix<T>& matr)
{
    size_t sign = 1, new_count = count - 1;
    T det = 0;
    if (count == 1)
        return matr[0][0];
    if (count == 2)
        return ((matr[0][0] * matr[1][1]) - (matr[1][0] * matr[0][1]));
    if (count > 2)
        for (size_t i = 0; i < count; ++i)
        {
            matrix<T> new_matr = matrix_det(count, i, 0, matr);
            det = det + sign * matr[i][0] * determinant_value(new_count, new_matr);
            sign = -sign;
        }
    return det;
}

template <typename T>
T matrix<T>::determinant(void)
{
    if (!this->is_square()) throw matr_sizes_exception();
    T det = determinant_value(this->get_n(), *this);
    return det;
}

template<typename T>
const T& matrix<T>::operator ()(unsigned int i, unsigned int j) const
{
    if (i < this->n || j < this->m) throw out_of_range_exception();

    return this->data[i*m+j];
}

template<typename T>
T& matrix<T>::operator ()(unsigned int i, unsigned int j)
{
    if (i < this->n || j < this->m) throw out_of_range_exception();

    return this->data[i*m+j];
}

template<typename T>
bool matrix<T>::is_square()
{
    return (this->get_n() == this->get_m());
}

template<typename T>
unsigned int matrix<T>::get_n() const
{
    return this->n;
}

template<typename T>
unsigned int matrix<T>::get_m() const
{
    return this->m;
}

template <typename T>
matrix_iterator<T> matrix<T>::begin()
{
    return matrix_iterator<T>(data, 0, element_count);
}

template <typename T>
matrix_iterator<T> matrix<T>::end()
{
    return matrix_iterator<T>(data, element_count, element_count);
}

template<typename T>
const_matrix_iterator<T> matrix<T>::begin() const
{
    return const_matrix_iterator<T>(data, 0, element_count);
}

template<typename T>
const_matrix_iterator<T> matrix<T>::end() const
{
    return const_matrix_iterator<T>(data, element_count, element_count);
}

#endif
