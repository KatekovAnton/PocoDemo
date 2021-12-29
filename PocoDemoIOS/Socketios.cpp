//
//  Socketios.cpp
//  PocoDemo
//
//  Created by Anton Katekov on 2021/12/24.
//

#include "Socketios.hpp"
#include <iostream>
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPMessage.h"
#include "Poco/Net/WebSocket.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/NetException.h"

Socketios::Socketios()
{}

Socketios::~Socketios()
{}

void Socketios::Send()
{
    std::string target = "localhost";

    _session = new Poco::Net::HTTPClientSession(target, 9980);
    Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, "/?encoding=text",Poco::Net::HTTPMessage::HTTP_1_1);
    request.setHost("localhost");
    Poco::Net::HTTPResponse response;

    try {
        
        _socket = new Poco::Net::WebSocket(*_session, request, response);
        char const *testStr="Hello echo websocket!";
        char receiveBuff[256];

        int len= _socket->sendFrame(testStr,strlen(testStr),Poco::Net::WebSocket::FRAME_TEXT);
        std::cout << "Sent bytes " << len << std::endl;
        int flags=0;

        int rlen= _socket->receiveFrame(receiveBuff,256,flags);
        std::cout << "Received bytes " << rlen << std::endl;
        std::cout << receiveBuff << std::endl;

        _socket->close();

    }
    catch (Poco::Net::ConnectionRefusedException &e) {
        std::cout << "Exception " << e.code() << ", msg:" << e.what();
    }
    catch (std::exception &e) {
        std::cout << "Exception " << e.what();
    }
}
