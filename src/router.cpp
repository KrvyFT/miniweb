#include "miniweb/router.hpp"

#include <boost/beast/http/field.hpp>
#include <boost/beast/http/fields_fwd.hpp>

namespace miniweb {
Response route(const Request &req) {
    auto res = Response{http::status::ok, req.version()};
    res.set(http::field::content_type, "text/plain; charset=utf-8");
    res.body() = "Hello, World!\n";
    res.prepare_payload();
    return res;
}
} // namespace miniweb