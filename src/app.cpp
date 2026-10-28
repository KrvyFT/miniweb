#include "miniweb/app.hpp"

#include "miniweb/server.hpp"

#include <exception>
#include <iostream>

namespace miniweb {
int run(int, char **) {
    try {
        run_server();
    } catch (const std::exception &e) {
        // Handle exceptions that may occur during server execution.
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
} // namespace miniweb