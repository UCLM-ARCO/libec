// -*- coding:utf-8; tab-width:4; mode:cpp -*-

#include <sys/types.h>
#include <sys/socket.h>

#include "./socket.h"

using namespace std;

Socket::Socket(SocketFamily family, SocketType type) {
  socket_family = family;
  socket_type = type;
  csocket = socket(family, type);
};

void
Socket::bind(AddressInfo address_info) {
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));

  server_address.sin_family = socket_family;
  server_address.sin_addr.s_addr = str_tonl(address_info.address);
  server_address.sin_port = htons(address_info.port);

  bind(csocket,
       (struct sockaddr*) &server_address, sizeof(server_address));
};

void
Socket::listen(int n) {
  listen(csocket, n);
}

std::pair<Socket,AddressInfo>
Socket::accept(void) {
  struct sockaddr_in client_address;
  accept(csocket,
	 (struct sockaddr*) &client_address, sizeof(client_address));

  AddressInfo retval;
  retval.address = inet_nto_str(client_address.sin_addr);
  retval.port = ntohs(client_address.sin_port);
  return retval;
};

char*
recv(int buflen, int flags) {
  char* buffer = (char*) malloc(buflen);
  recv(csocket, buffer, buflen);
  return buffer;
}
