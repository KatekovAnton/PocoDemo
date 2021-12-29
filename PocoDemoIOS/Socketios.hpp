//
//  Socketios.hpp
//  PocoDemo
//
//  Created by Anton Katekov on 2021/12/24.
//

#ifndef Socketios_hpp
#define Socketios_hpp

#include <stdio.h>

namespace Poco {
namespace Net {
class HTTPClientSession;
class WebSocket;
}
}
class Socketios {
    
    Poco::Net::HTTPClientSession *_session;
    Poco::Net::WebSocket *_socket;
    
public:
    Socketios();
    ~Socketios();
    
    void Send();
};

#endif /* Socket_hpp */
