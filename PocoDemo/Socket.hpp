//
//  Socket.hpp
//  PocoDemo
//
//  Created by Anton Katekov on 2021/12/24.
//

#ifndef Socket_hpp
#define Socket_hpp

#include <stdio.h>

namespace Poco {
namespace Net {
class HTTPClientSession;
class WebSocket;
}
}
class Socket {
    
    Poco::Net::HTTPClientSession *_session;
    Poco::Net::WebSocket *_socket;
    
public:
    Socket();
    ~Socket();
    
    void Send();
};

#endif /* Socket_hpp */
