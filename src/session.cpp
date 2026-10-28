#include "miniweb/session.hpp"

#include "miniweb/router.hpp"

#include <boost/beast/core/flat_buffer.hpp>
#include <boost/beast/http/impl/read.hpp>

namespace miniweb {
void session(tcp::socket socket) {
    // Implementation of the session handling logic goes here.
    // This function will manage the lifecycle of a single client connection.
    beast::flat_buffer buffer;
    Request req;

    http::read(socket, buffer, req);
    auto res = route(req);
    res.keep_alive(false);
    http::write(socket, res);
}
} // namespace miniweb