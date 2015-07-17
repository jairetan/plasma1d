#pragma once
#include<sstream>
    template <typename T>
std::string to_string(T value)
{
    std::ostringstream os ;

    //throw the value into the string stream
    os << value ;

    //convert the string stream into a string and return
    return os.str() ;
}
