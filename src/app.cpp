#include "miniweb/app.hpp"

#include "miniweb/demo.hpp"

namespace miniweb {
int run(int, char **) {
    run_demo();
    return 0;
}
} // namespace miniweb