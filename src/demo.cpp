#include "miniweb/demo.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>

namespace miniweb {
struct Connection {
    std::string name;

    explicit Connection(std::string value) : name(std::move(value)) {
        std::cout << "Open " << name << std::endl;
    }
    ~Connection() {
        std::cout << "Close " << name << std::endl;
    }
};

void run_demo() {
    auto owner = std::make_unique<Connection>("demo");
    auto next = std::move(owner);
    std::cout << "Old owner empty: " << std::boolalpha << !owner << std::endl;
    auto inspect = [&next] { std::cout << "Inspect: " << next->name << std::endl; };
    inspect();
}
} // namespace miniweb