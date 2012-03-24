#ifndef SOCKET_H
#define SOCKET_H

#include <string>
#include <utility>

class Socket {
private:
  int csocket;
  SocketFamily sock_family;
  SocketType sock_type;

public:
  enum SocketFamily{AF_UNIX=1, AF_INET=2, AF_PACKET=17};
  enum SocketType{SOCK_STREAM, SOCK_DGRAM, SOCK_RAW};
  enum ShutdownMode{SHUT_RD, SHUT_WR, SHUT_DRWR};

  typedef struct {
    std::string address;
    int port;
  }  AddressInfo;

  Socket(SocketFamily family, SocketType type);
  std::pair<Socket,AddressInfo> accept(void);
  void bind(AddressInfo address_info);
  void close(void);
  void connect(AddressInfo address_info);
  AddressInfo getpeername(void);
  AddressInfo getsockname(void);
  // getsockopt(int level, std::string optname, int buflen);
  // gettimeout(void);
  void listen(int n);
  std::string recv(int buflen, int flags=0);
  void recv_into(char* buffer, int nbytes, int flags=0);
  std::string recvfrom(int buflen, int flags=0);
  void recvfrom_into(char* buffer, int nbytes, int flags=0);
  void sendall(const char* data, int flags=0);
  void sendto(const char* data, AddressInfo address_info, int flags=0);
  // setblocking(bool value);
  // void setsockopt(int level, std::string optname, int value);
  void settimeout(float value=0);
  void shutdown(ShutdownMode how);
};

#endif
