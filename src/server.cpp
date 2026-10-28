#include "miniweb/server.hpp"

#include "miniweb/session.hpp"

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/address.hpp>
#include <exception>
#include <iostream>

namespace miniweb {
void run_server() {
    // Implementation of the server logic goes here.
    // This function will set up the server, accept incoming connections,
    // and spawn sessions for each client.
    net::io_context io;
    tcp::acceptor acceptor(io, {net::ip::make_address("127.0.0.1"), 8080});
    while (true) {
        auto socket = acceptor.accept();
        try {
            session(std::move(socket));
        } catch (const std::exception &e) {
            // Handle exceptions that may occur during session handling.
            std::cerr << e.what() << std::endl;
        }
    }
}
} // namespace miniweb