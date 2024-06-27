#include <iostream>
#include <boost/filesystem.hpp>

int main() {
    boost::filesystem::path path("./test_data.txt");
    if (boost::filesystem::exists(path)) {
        std::cout << "Directory exists!" << std::endl;
    }
    return 0;
}
