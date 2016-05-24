#include <iostream>
#include <string>
#include <memory>
#include <syslandscape/web/HTTPServer.h>
#include <syslandscape/web/HTTPRequest.h>
#include <syslandscape/web/HTTPResponse.h>
#include <syslandscape/web/HTTPStatus.h>
#include <syslandscape/web/HTTPCookie.h>
#include <syslandscape/web/WebHandlerFactory.h>
#include <syslandscape/web/WebHandler.h>
#include <syslandscape/web/WebContext.h>

using std::string;
using syslandscape::web::HTTPServer;
using syslandscape::web::HTTPRequest;
using syslandscape::web::HTTPResponse;
using syslandscape::web::HTTPStatus;
using syslandscape::web::HTTPCookie;
using syslandscape::web::WebContext;
using syslandscape::web::WebHandler;
using syslandscape::web::WebHandlerFactory;

class MyHandler : public WebHandler
{
public:
  MyHandler();

  void handle(HTTPRequest &, HTTPResponse &) override;
private:
};

MyHandler::MyHandler()
{
}

void MyHandler::handle(HTTPRequest &request, HTTPResponse &response)
{
  std::stringstream ss;
  ss << "<html><head><title>Page</title></head>";
  ss << "<body>";
  ss << "<h1>" << request.getUrl() << "</h1>";
  ss << "<h2>" << toString(request.getMethod()) << "</h2>";
  
  for (auto header: request.headers())
    {
      ss << header.first << ": " << header.second << "<br>";
    }
  
  ss << "</body></html>";

  HTTPCookie* c = new HTTPCookie();
  c->setName("SYSLSESSION");
  c->setValue("whatever");
  c->setHttpOnly(true);
  
  response.addCookie(c);
  response.setHeader("Content-Type", "text/html");
  response.setStatus(HTTPStatus::OK);
  response.setContent(ss.str());
}

class MyHandlerFactory : public WebHandlerFactory
{
public:
  
  std::unique_ptr<WebHandler> getHandler(const string &, HTTPRequest &) override;

private:
};

std::unique_ptr<WebHandler> MyHandlerFactory::getHandler(const string &, HTTPRequest &)
{
  return std::make_unique<MyHandler>();
}


int main()
{
  auto wc = std::make_shared<WebContext>();
  wc->add("/", "home");
  wc->add("/index.html", "home");
  wc->setWebHandlerFactory(std::make_shared<MyHandlerFactory>());  
  
  std::cout << "RUN" << std::endl;
  try {
    HTTPServer s("0.0.0.0", "8080");
    s.setWebContext(wc);
    s.run();

    
  }
  catch (std::exception& e)
  {
    std::cerr << "exception: " << e.what() << "\n";
  }

  return 0;
}
