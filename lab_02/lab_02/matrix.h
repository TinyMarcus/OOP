#ifndef MATRIX_H
#define MATRIX_H

#include "base_container.h"
#include "exceptions.h"
#include "matrix_iterator.h"
#include "matrix_iterator_const.h"
#include <iostream>
#include <memory>

// shared_ptr

template<typename T>
class matrix : public :: base_container
{
public:
    matrix() = default;
    matrix(unsigned int n, unsigned int m);

    explicit matrix(const matrix<T>& matr);
    matrix(matrix<T>&& matr);
    explicit matrix(std::initializer_list<std::initializer_list<T>> lst);

    ~matrix();

    matrix<T>& operator =(const matrix<T>& matr);

    matrix<T>& operator +=(const matrix<T>& matr);
    matrix<T> operator +(const matrix<T>& matr) const;
    matrix<T> operator +(const T num);

    matrix<T>& operator -=(const matrix<T>& matr);
    matrix<T> operator -(const matrix<T>& matr);
    matrix<T> operator -(const T num);

    void set_elem(unsigned int i, unsigned int j,const T& elem);
    T& get_elem(unsigned int i, unsigned int j);
    T get_elem(unsigned int i, unsigned int j) const;

    matrix<T> operator *(const matrix<T>& matr);
    template<typename _T>
    friend matrix<_T> operator *(const matrix<_T>& m1, _T num);
    template<typename _T>
    friend matrix<_T> operator *(_T num, const matrix<_T>& m1);
    matrix<T> operator /(T num);

    template<typename _T>
    friend std::ostream& operator <<(std::ostream& os, const matrix<_T>& matr);

    matrix_iterator<T> begin();
    matrix_iterator<T> end();

    const_matrix_iterator<T> begin() const;
    const_matrix_iterator<T> end() const;

    T& operator ()(unsigned int i, unsigned int j);
    const T& operator ()(unsigned int i, unsigned int j) const;

    bool is_square();
    unsigned int get_n() const;
    unsigned int get_m() const;

    matrix<T> reverse();
    matrix<T> transpose();
    matrix<T> operator !(void);

    T determinant_value(const size_t count, const matrix<T>& matrix);
    matrix<T> matrix_det(size_t count, size_t exclude_row, size_t exclude_column, const matrix<T>& matrix);
    T determinant(void);

protected:
    template<typename ValueType>
    class proxy_line
    {
    public:
        proxy_line() = delete;
        proxy_line(ValueType* array, unsigned int n) : data_row(array), m(n) {}

        T& operator[](unsigned int index)
        {
            if (index >= this->m) throw out_of_range_exception();
            return (data_row[index]);
        }

        T operator[](unsigned int index) const
        {
            if (index >= this->m) throw out_of_range_exception();
            return (data_row[index]);
        }

    private:
        unsigned int m;
        ValueType* data_row = nullptr;
    };

public:
    proxy_line<T> operator[](unsigned int index)
    {
        if (index >= this->n) throw out_of_range_exception();

        return proxy_line<T>(this->data.get() + index * this->m, this->m);
    }

    proxy_line<T> operator[](unsigned int index) const
    {
        if (index >= this->n) throw out_of_range_exception();

        return proxy_line<T>(this->data.get() + index * this->m, this->m);
    }

private:
    unsigned int n;
    unsigned int m;
    std::shared_ptr <T> data;
    //T* data;
};

#include "matrix.hpp"

#endif
