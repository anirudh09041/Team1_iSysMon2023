#define WIN32_LEAN_AND_MEAN
#define _BOOST_SERIALIZE_H 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#include"ClientInfo.h"
#include"LoginCred.h"
#include "ReadConfig.h"

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma  (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

int __cdecl main(int argc, char** argv)
{
    int timer = 10000;
    try {
        timer = returnTimer();
        std::cout << "Timer value: " << timer << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo* result = NULL,
        * ptr = NULL,
        hints;
    const char* sendbuf = "Hello World !!!";

    // STRUCTURE OF SYSTEM INFORMATION
    struct SystemInformation {
        int sizeOfStruct = 0;
        string currentClientName;
        string systemName;
        string userName;
        string cpuUtilization; // changed to string
        string availableRam;
        string totalRam;
        string ip;
        string downloadSpeed;
        string uploadSpeed;
        string systemIdleWindow; //changed to string
        char currentTime[100];
        char osName[100];
        char osVersion[100];
        char productID[100];
        string systemType;
        char systemBootTime[100];
        string systemUpTime;
        char hddUtilization[100];

    };
    struct SystemInformation SI;





    char recvbuf[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;

    // for negative buffer length
    int nackbuflen = 11;
    // for storing negative acknowledgment
    char nackrecvbuf[11];

    //Validate the parameters
    if (argc < 3) {
        //printf("usage: %s server-name\n", argv[0]);
        cout << argc;
        return 1;
    }

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    /*struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("10.152.240.74");
    serverAddr.sin_port = htons(27015);*/


    // Resolve the server address and port
    iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Attempt to connect to an address until one succeeds
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            return 1;
        }

        // Connect to server.
        iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }


    
    char message[7000];
    
    char systemInfoAuthBuffer[5];
    string systemInfoAuth = "NOTLS";

    memcpy(systemInfoAuthBuffer, systemInfoAuth.c_str(), sizeof(systemInfoAuth));
    printf("sizeof systemInfoAuth = %d\n", (int)sizeof(systemInfoAuth));
    send(ConnectSocket, systemInfoAuthBuffer, (int)sizeof(systemInfoAuth), 0);


   /* char loginCredBuffer[200];
    LoginCred lc;
    char loginStat[200];
    string username = "client1";
    string pass = "admin1";*/
    //'true' for sign in and 'false' for sign up
    /*lc.purpose = true;
    strcpy_s(lc.username, username.c_str());
    strcpy_s(lc.password, pass.c_str());

    memcpy(loginCredBuffer, &lc, sizeof(lc));
    printf("sizeof lc = %d\n", (int)sizeof(lc));

    iResult = send(ConnectSocket, loginCredBuffer, (int)sizeof(lc), 0);
    
    iResult=recv(ConnectSocket,loginStat , 200, 0);
    cout << "Bytes Received: " << iResult<<endl;
    string loginStatString(loginStat);
    cout << loginStatString << endl;
    if (loginStatString.compare("Credentials Verified") != 0) 
    {
        cout << loginStatString+", SAFELY CLOSING THE PROGRAM";
        exit(0); 
    }*/
    while (1)
    {
        ClientInfo cf(argv[2]);

        // send returns the number of bytes sent 
        SI.currentClientName = argv[2];
        SI.systemName = cf.systemName;
        SI.userName = cf.userName;
        SI.cpuUtilization = to_string(cf.cpuUtilization);
        SI.availableRam = cf.availableRam;
        SI.totalRam = cf.totalRam;
        SI.ip = cf.ip;
        SI.downloadSpeed = cf.downloadSpeed;
        SI.uploadSpeed = cf.uploadSpeed;
        SI.systemIdleWindow = to_string(cf.systemIdleWindow);
        strcpy_s(SI.currentTime, cf.currentTime.c_str());
        //SI.currentTime = cf.currentTime;
        strcpy_s(SI.osName, cf.osName.c_str());
        //SI.osName = cf.osName;
        strcpy_s(SI.osVersion, cf.osVersion.c_str());
        //SI.osVersion = cf.osVersion;
        strcpy_s(SI.productID, cf.productID.c_str());
        //SI.productID = cf.productID;
        SI.systemType = cf.systemType;
        strcpy_s(SI.systemBootTime, cf.systemBootTime.c_str());
        //SI.systemBootTime = cf.systemBootTime;
        SI.systemUpTime = cf.systemUpTime;
        strcpy_s(SI.hddUtilization, cf.hddUtilization.c_str());
        //SI.hddUtilization = cf.hddUtilization;

        cout << "Size of system Name is :::: " << sizeof(cf.systemName) << endl;
        cout << "Size of user Name is :::: " << sizeof(cf.userName) << endl;
        cout << "Size of CPU util is :::: " << sizeof(cf.cpuUtilization) << endl;
        cout << "Size of avai RAM is :::: " << sizeof(cf.availableRam) << endl;
        cout << "Size of TOTAL RAM is :::: " << sizeof(cf.totalRam) << endl;
        cout << "Size of ip is :::: " << sizeof(cf.ip) << endl;
        cout << "Size of download speed is :::: " << sizeof(cf.downloadSpeed) << endl;
        cout << "Size of upload speed is :::: " << sizeof(cf.uploadSpeed) << endl;
        cout << "Size of system idle window is :::: " << sizeof(cf.systemIdleWindow) << endl;
        cout << "Size of current time is :::: " << sizeof(cf.currentTime) << endl;
        cout << "Size of osName is :::: " << sizeof(cf.osName) << endl;
        cout << "Size of osVersion is :::: " << sizeof(cf.osVersion) << endl;
        cout << "Size of product ID is :::: " << sizeof(cf.productID) << endl;
        cout << "Size of systemType is :::: " << sizeof(cf.systemType) << endl;
        cout << "Size of system Boot timeis :::: " << sizeof(cf.systemBootTime) << endl;
        cout << "Size of system Up Time is :::: " << sizeof(cf.systemUpTime) << endl;
        cout << "Size of hdd is :::: " << sizeof(cf.hddUtilization) << endl;





         cout << (SI).systemName << endl;
         cout << (SI).userName << endl;
         //cout << d1 << endl;
         cout << (SI).cpuUtilization<<endl;
         cout << (SI).hddUtilization << endl;
         cout << (SI).availableRam << endl;
         cout << (SI).totalRam << endl;
         cout << (SI).ip << endl;
         cout << (SI).downloadSpeed << endl;
         cout << (SI).uploadSpeed << endl;
         //cout << d2 << endl;
         cout << (SI).currentTime << endl;
         cout << (SI).osName << endl;
         cout << (SI).osVersion << endl;
         cout << (SI).productID << endl;
         cout << (SI).systemType << endl;
         cout << (SI).systemBootTime << endl;
         cout << (SI).systemUpTime << endl;
         cout << "ALL DATA\n";

        memcpy(message, &SI, sizeof(SI));
        printf("sizeof SI = %d\n", (int)sizeof(SI));


        iResult = send(ConnectSocket, message, 7000, 0);
        if (iResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
            closesocket(ConnectSocket);
            WSACleanup();
            return 1;
        }

        printf("\n Bytes Sent: %ld\n", iResult);
        cf.~ClientInfo();

        iResult = recv(ConnectSocket, nackrecvbuf, nackbuflen, 0);
        //string str(nackrecvbuf,nackrecvbuf+11);
        if (nackrecvbuf[0] == 'd')
        {
            printf("\t server asking to disconnect \t\n");
            shutdown(ConnectSocket, SD_SEND);
            closesocket(ConnectSocket);
            WSACleanup();
          // can be called here to delete all the files at the end
          //  cf.~ClientInfo();
            //Sleep(2000);
        }

        Sleep(timer);

    }

    // shutdown the connection since no more data will be sent
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    // Receive until the peer closes the connection
    do {

        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0)
            printf("Bytes received: %d\n\n  message from server: %s\n\n", iResult, recvbuf);
        else if (iResult == 0)
            printf("Connection closed\n");
        else
            printf("recv failed with error: %d\n", WSAGetLastError());

    } while (iResult > 0);

    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();

    return 0;
}