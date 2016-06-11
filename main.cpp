// #include <netinet/in.h>
// #include <arpa/inet.h>
// #include <time.h>
// #include <sys/socket.h>

#include <windows.h>
#include <thread>
// #include <chrono>
// #include <sys/types.h>
// #include <winsock2.h>
#include <ws2tcpip.h>

#include <stdio.h>
#include <iostream>
// using namespace std;

#define TEST_PORT 12345
#define TEST_GROUP "225.0.0.37"

int main(int argc, char *argv[])
{
    int s, cnt;
    struct ip_mreq mreq;
    const char *message;
    message = "vmea hello message";

    /* create what looks like an ordinary UDP socket */
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
        perror("socket");
        exit(1);
    }
    const char optval = 1;
    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    /* set up destination address */
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr(TEST_GROUP);
    addr.sin_port=htons(TEST_PORT);

    /* now just sendto() our destination! */
    while (1) {
        if (sendto(s, message,sizeof(message),0,(struct sockaddr *) &addr,
                   sizeof(addr)) < 0) {
            perror("sendto");
            exit(1);
        }
        Sleep(1);
    }
    return 0;
}