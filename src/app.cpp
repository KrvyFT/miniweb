#include "miniweb/app.hpp"

#include "miniweb/greeting.hpp"

#include <iostream>

namespace miniweb {
int run(int argc, char *argv[]) {
    std::cout << greeting() << std::endl;
    return 0;
}
} // namespace miniweb