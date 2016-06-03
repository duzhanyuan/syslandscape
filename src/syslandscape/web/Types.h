#ifndef SYSLANDSCAPE_WEB_TYPES
#define SYSLANDSCAPE_WEB_TYPES

#include <cstdint>
#include <memory>
#include <boost/asio.hpp>

namespace syslandscape {
namespace web {

typedef uint8_t byte;
typedef std::vector<byte> bytes;
typedef std::shared_ptr<bytes> bytes_ptr;

typedef boost::asio::ip::tcp::acceptor acceptor;
typedef boost::asio::signal_set signal_set;
typedef boost::asio::ip::tcp::socket socket;
typedef std::shared_ptr<socket> socket_ptr;
typedef boost::asio::io_service::strand strand;
typedef std::shared_ptr<strand> strand_ptr;
typedef boost::asio::deadline_timer timer;
typedef std::shared_ptr<timer> timer_ptr;

/**
 * UNKOWN should be used only while parsing and indicates an error.
 */
enum class Method
{
  UNKNOWN = 0,
    GET,
    POST,
    PUT,
    DELETE,
    HEAD
};

Method toMethod(int);
Method toMethod(const std::string &);
std::string toString(Method);

enum class Status
{
  OK = 200,
    CREATED = 201,
    ACCEPTED = 202,
    NO_CONTENT = 204,
    MULTIPILE_CHOICES = 300,
    MOVED_PERMANENTLY = 301,
    MOVED_TEMPORARILY = 302,
    NOT_MODIFIED = 304,
    BAD_REQUEST = 400,
    UNAUTHORIZED = 401,
    FORBIDDEN = 403,
    NOT_FOUND = 404,
    INTERNAL_SERVER_ERROR = 500,
    NOT_IMPLEMENTED = 501,
    BAD_GATEWAY = 502,
    SERVICE_UNAVAILABLE = 503
};

} /* namespace web */
} /* namespace syslandscape */

#endif /* SYSLANDSCAPE_WEB_TYPES */