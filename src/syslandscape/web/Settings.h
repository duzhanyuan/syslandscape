#ifndef SYSLANDSCAPE_WEB_SETTINGS
#define SYSLANDSCAPE_WEB_SETTINGS

#include <memory>
#include <string>

namespace syslandscape {
namespace web {

class Settings;
typedef std::shared_ptr<Settings> settings_ptr;

class Settings
{
public:

  void port(uint16_t);
  
  uint16_t port() const;

  void address(const std::string &);
  
  std::string address() const;

  void reuseAddress(bool);

  bool reuseAddress() const;

  bool noDelay() const;

  void noDelay(bool);

  void workerThreads(uint16_t);

  uint16_t workerThreads() const;
  
  void maxPendingConnections(uint16_t);
  
  uint16_t maxPendingConnections() const;
  
  void receiveBufferSize(uint16_t);

  uint16_t receiveBufferSize() const;
  
  void sendBufferSize(uint16_t);

  uint16_t sendBufferSize() const;

  void requestMaxSize(size_t);

  std::size_t requestMaxSize() const;

  void requestBufferSize(size_t);

  std::size_t rquestBufferSize() const;

  uint16_t keepAliveTimeout() const;

  void keepAlivetimeout(uint16_t);

  void ssl(bool);

  bool ssl() const;

  void sslCertificate(const std::string &);

  std::string sslCertificate() const;

  void sslPrivateKey(const std::string &);

  std::string sslPrivateKey() const;
  
private:

  uint16_t _port = 8080;
  
  std::string _address = "127.0.0.1";

  bool _reuseAddress = true;

  /** Set tcp::no_delay option to socket. */
  bool _noDelay = true;

  uint16_t _workerThreads = 10;
  
  uint16_t _maxPendingConnections = 30;
  
  uint16_t _receiveBufferSize = 8192;

  uint16_t _sendBufferSize = 8192;

  /* Maximum allowed size in bytes for request (including headers and 
   * body
   */
  std::size_t _requestMaxSize = 1000000;

  /**
   * Size of request read buffer. After every read, @_requestMaxSize
   * is tested. 
   */
  std::size_t _requestBufferSize = 1000;

  /** The number of seconds Connection will wait for a subsequent 
   * request before closing the connection. Once a request has been 
   * received, the timeout value specified by the Timeout directive 
   * applies. */
  uint16_t _keepAliveTimeout = 15;

  bool _ssl;

  std::string _sslCertificate;

  std::string _sslPrivateKey;
};

} /* web */
} /* engine  */

#endif /* SYSLANDSCAPE_WEB_SETTINGS */
