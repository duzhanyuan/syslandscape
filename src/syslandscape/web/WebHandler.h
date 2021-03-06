#ifndef SYSLANDSCAPE_WEB_WEBHANDLER
#define SYSLANDSCAPE_WEB_WEBHANDLER

#include <string>
#include <memory>
#include "Request.h"
#include "Response.h"

namespace syslandscape {
namespace web {

class WebHandler;
typedef std::shared_ptr<WebHandler> web_handler_ptr;

class WebHandler
{
public:

  virtual ~WebHandler();

  virtual void handle(std::shared_ptr<Request>, std::shared_ptr<Response>) = 0;

};


} /* namespace web */
} /* namespace syslandscape  */

#endif /* SYSLANDSCAPE_WEB_WEBHANDLER */
