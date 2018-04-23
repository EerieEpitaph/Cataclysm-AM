#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <exception>
#include <iostream>
#include <exception>

class redefinition_exception : public std::exception
{
    const char* what() const throw()
    {return "Redefining existing object";}
};

class line_analysis_exception : public std::exception
{
    const char* what() const throw()
    {return "JSON analysis failed";}
};

class identifier_mismatch_exception : public std::exception
{
    const char* what() const throw()
    {return "Identifier changed in parsing-time";}
};

#endif // EXCEPTIONS_H_INCLUDED
