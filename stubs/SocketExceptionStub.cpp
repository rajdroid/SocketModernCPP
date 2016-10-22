#include "SocketExceptions.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    SocketExceptions cSockExc(ErrorCodes::errConnectionTimeout);
    std::cout << cSockExc.getExceptionString() << std::endl;

    SocketExceptions cSockExcCopy(cSockExc);
    std::cout << cSockExcCopy.getExceptionString() << std::endl;
    return 0;
}
