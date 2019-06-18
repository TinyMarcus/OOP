#ifndef ERRORS_H
#define ERRORS_H

#include <exception>

class My_Error : public std::exception
{
public:
    virtual const char *what() const throw()
    {
        return "Undefined error";
    }
};

class Bad_Size : public My_Error
{
public:
    virtual const char *what() const throw()
    {
        return "Sizes mismatch";
    }
};

class Wrong_Division : public My_Error
{
public:
    virtual const char *what() const throw()
    {
        return "Division by zero";
    }
};

class Wrong_Boundaries : public My_Error
{
public:
    virtual const char *what() const throw()
    {
        return "Index is out of boundaries";
    }
};

class Allocation_Error : public My_Error
{
public:
    virtual const char *what() const throw()
    {
        return "Memory couldn't be allocated";
    }
};

#endif // ERRORS_H
