
#include "inc/Path.hpp"

namespace helpers {

std::string Path::toString(const std::initializer_list<const std::string>& args) {
    std::string returnPath = "";
    for (auto& elem : args) {
        returnPath += elem;
        if (&elem != &(*std::rbegin(args))) {
            returnPath += PATH_SEPARATOR;
        }
    }

    return returnPath;
}

} // namespace helpers