#pragma once
#include <boost/asio.hpp>
#include <boost/beast.hpp>

namespace miniweb {
namespace net = boost::asio;
namespace beast = boost::beast;
namespace http = beast::http;

using tcp = net::ip::tcp;
using Request = http::request<http::string_body>;
using Response = http::response<http::string_body>;
using Error = boost::system::error_code;
} // namespace miniweb