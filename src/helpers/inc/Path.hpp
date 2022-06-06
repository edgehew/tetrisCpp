#pragma once

#include <string>

namespace helpers {

class Path {
private:
    const std::string PATH_SEPARATOR = #ifdef _WIN32 "\\" #else "/" #endif ;

public:
    static std::string toString(std::string t, Args... args) {
        return t + PATH_SEPARATOR + append(args);
    }

    static std::string toString(std::initializer_list<std::string> args) {
        std::string returnPath = "";
        for (auto& elem : args) {
            returnPath += elem;
            if (&elem != &args.back()) {
                returnPath += PATH_SEPARATOR;
            }
        }

        return returnPath;
    }

};

} // namespace helpers