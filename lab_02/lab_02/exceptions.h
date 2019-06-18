#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>
#include <exception>

class base_exception : public std::exception
{
public:
    virtual const char* what()
    {
        return message.c_str();
    }

    explicit base_exception() = default;

    explicit base_exception(const char* message)
        : message(message) {}

    explicit base_exception(const std::string& message)
        : message(message) {}

    explicit base_exception(const std::string& message, const std::string& add_message)
        : message(message), additional_message(add_message) {}

    explicit base_exception(const char* message, const char* add_message)
        : message(message), additional_message(add_message) {}


protected:
    std::string message;
    std::string additional_message;
};


class out_of_range_exception : public base_exception
{
public:
    explicit out_of_range_exception()
        : base_exception("Index out of range"){}

    explicit out_of_range_exception(const std::string& add_message)
        : base_exception("Index out of range", add_message){}

};


class memory_allocate_exception : public base_exception
{
public:
    explicit memory_allocate_exception()
        : base_exception("Bad memory allocation"){}

    explicit memory_allocate_exception(const std::string& add_message)
        : base_exception("Bad memory allocation", add_message){}
};


class is_empty_exception : public base_exception
{
public:
    explicit is_empty_exception()
        : base_exception("Matrix is empty"){}

    explicit is_empty_exception(const std::string& add_message)
        : base_exception("Matrix is empty", add_message){}
};

class bad_iterator_exception : public base_exception
{
public:
    explicit bad_iterator_exception()
        : base_exception("Error with iterator"){}

    explicit bad_iterator_exception(const std::string& add_message)
        : base_exception("Error with iterator", add_message){}
};

class iterator_out_of_range_exception : public base_exception
{
public:
    explicit iterator_out_of_range_exception()
        : base_exception("Iterator out of range"){}

    explicit iterator_out_of_range_exception(const std::string& add_message)
        : base_exception("Iterator out of range", add_message){}
};

class matr_sizes_exception : public base_exception
{
public:
    explicit matr_sizes_exception()
        : base_exception("Matrixes have bad sizes"){}

    explicit matr_sizes_exception(const std::string& add_message)
        : base_exception("Matrixes have bad sizes", add_message){}
};

class matr_wrong_size_exception : public base_exception
{
public:
    explicit matr_wrong_size_exception()
        : base_exception("Matrixes cant have zero sizes"){}

    explicit matr_wrong_size_exception(const std::string& add_message)
        : base_exception("Matrixes cant have zero sizes", add_message){}
};

class zero_devision_exception : public base_exception
{
public:
    explicit zero_devision_exception()
        : base_exception("Devision by zero"){}

    explicit zero_devision_exception(const std::string& add_message)
        : base_exception("Devision by zero", add_message){}
};

#endif
