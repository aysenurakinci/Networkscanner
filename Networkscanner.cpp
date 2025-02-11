#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <icmpapi.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "iphlpapi.lib")

#define PACKET_SIZE 32

// Function to send ICMP Echo Request (Ping)
void send_ping(const char* ip) {
    HANDLE hIcmpFile;
    IPAddr ipAddr = 0;  // IP address in network byte order
    DWORD dwRetVal;
    char sendData[PACKET_SIZE] = "Ping Test Data";
    BYTE replyBuffer[sizeof(ICMP_ECHO_REPLY) + PACKET_SIZE];
    DWORD replySize = sizeof(replyBuffer);

    // Convert IP string to binary form
    if (InetPtonA(AF_INET, ip, &ipAddr) != 1) {
        printf("Invalid IP address: %s\n", ip);
        return;
    }

    hIcmpFile = IcmpCreateFile();
    if (hIcmpFile == INVALID_HANDLE_VALUE) {
        printf("Unable to create ICMP handle.\n");
        return;
    }

    dwRetVal = IcmpSendEcho(hIcmpFile, ipAddr, sendData, sizeof(sendData),
        NULL, replyBuffer, replySize, 1000);

    if (dwRetVal != 0) {
        PICMP_ECHO_REPLY reply = (PICMP_ECHO_REPLY)replyBuffer;
        printf("Ping successful: %s, Time: %ldms\n", ip, reply->RoundTripTime);
    }
    else {
        printf("Ping failed: %s\n", ip);
    }

    IcmpCloseHandle(hIcmpFile);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP>\n", argv[0]);
        return 1;
    }

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed.\n");
        return 1;
    }

    send_ping(argv[1]);

    WSACleanup();
    return 0;
}
