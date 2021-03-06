#include <iostream>



using namespace std;



#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPMessage.h"
#include "Poco/Net/WebSocket.h"
#include "Poco/Net/HTTPClientSession.h"
#include <iostream>



using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPMessage;
using Poco::Net::WebSocket;



int main(int argc, char **argv)
{
    std::string target = "10.0.3.2";
#if defined TARGET_HOST 
    target = "localhost";
#endif
    HTTPClientSession cs(target, 9980);
    HTTPRequest request(HTTPRequest::HTTP_GET, "/?encoding=text",HTTPMessage::HTTP_1_1);
    request.setHost("localhost");
    HTTPResponse response;

    try {

        WebSocket* m_psock = new WebSocket(cs, request, response);
        char const *testStr="Hello echo websocket!";
        char receiveBuff[256];

        int len=m_psock->sendFrame(testStr,strlen(testStr),WebSocket::FRAME_TEXT);
        std::cout << "Sent bytes " << len << std::endl;
        int flags=0;

        int rlen=m_psock->receiveFrame(receiveBuff,256,flags);
        std::cout << "Received bytes " << rlen << std::endl;
        std::cout << receiveBuff << std::endl;

        m_psock->close();

    } catch (std::exception &e) {
        std::cout << "Exception " << e.what();
    }
    return 0;
}
