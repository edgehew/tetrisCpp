#pragma once

#include <initializer_list>
#include <iterator>
#include <string>

namespace helpers {

class Path {
private:
    #ifdef _WIN32 
        static constexpr auto PATH_SEPARATOR = "\\"; 
    #else 
        static constexpr auto PATH_SEPARATOR = "/"; 
    #endif

public:
    static std::string toString(const std::initializer_list<const std::string>& args); 
};

} // namespace helpers