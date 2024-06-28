#include <iostream>
#include <boost/filesystem.hpp>

int main() {
    boost::filesystem::path path("/app/muduo");
    if (boost::filesystem::exists(path)) {
        std::cout << "Directory exists!" << std::endl;
    }
    return 0;
}
