#pragma once
#pragma comment(lib, "ws2_32.lib")
#include<string>
#include<iostream>
#include <winsock.h>
#include<fstream>
//#include <netinet/in.h>
using namespace std;

class NetworkInfo
{
private:
	string ip;
	string downloadSpeed;
	string uploadSpeed;
	string toBeDeleteFile;

	struct IPv4
	{
		unsigned char b1, b2, b3, b4;
	};

	bool getMyIP(IPv4& myIP)
	{
		char szBuffer[1024];

#ifdef WIN32
		WSADATA wsaData;
		WORD wVersionRequested = MAKEWORD(2, 0);
		if (::WSAStartup(wVersionRequested, &wsaData) != 0)
			return false;
#endif


		if (gethostname(szBuffer, sizeof(szBuffer)) == SOCKET_ERROR)
		{
#ifdef WIN32
			WSACleanup();
#endif
			return false;
		}

		struct hostent* host = gethostbyname(szBuffer);
		if (host == NULL)
		{
#ifdef WIN32
			WSACleanup();
#endif
			return false;
		}

		//Obtain the computer's IP
		myIP.b1 = ((struct in_addr*)(host->h_addr))->S_un.S_un_b.s_b1;
		myIP.b2 = ((struct in_addr*)(host->h_addr))->S_un.S_un_b.s_b2;
		myIP.b3 = ((struct in_addr*)(host->h_addr))->S_un.S_un_b.s_b3;
		myIP.b4 = ((struct in_addr*)(host->h_addr))->S_un.S_un_b.s_b4;

#ifdef WIN32
		WSACleanup();
#endif
		return true;
	}

	string setIpAddr()
	{
		IPv4 myIP;

		getMyIP(myIP);
		string ipa = to_string(myIP.b1) + "." + to_string(myIP.b2) + "." + to_string(myIP.b3) + "." + to_string(myIP.b4);
		//cout << ipa;
		this->ip = ipa;
		return ipa;
	}


	void setInternetSpeed() {
		std::string outputstring;
		std::string buffer;
		std::ifstream input("netspeed" + this->toBeDeleteFile);
		int recpos;
		int transpos;
		int ssidpos;

		while (std::getline(input, buffer))
		{
			outputstring += (buffer + '\n');
		}


		size_t reclocate = outputstring.find("Receive");
		if (reclocate != string::npos)
			recpos = reclocate;
		size_t translocate = outputstring.find("Transmit");
		if (translocate != string::npos)
			transpos = translocate;


		string dSpeed = outputstring.substr(recpos + 25, 5);
		string uSpeed = outputstring.substr(transpos + 25, 5);

		this->downloadSpeed = dSpeed;
		this->uploadSpeed = uSpeed;
	}

public:

	//creates network.txt and stores the data from file to local vairables
	NetworkInfo(string path) {
		this->toBeDeleteFile = path + ".txt";
		system(("netsh wlan show interface>netspeed" + this->toBeDeleteFile).c_str());

		setInternetSpeed();
		setIpAddr();
	}
	//deletes file for creation of new file at new instance
	~NetworkInfo() {
		system(("del netspeed" + this->toBeDeleteFile).c_str());
	}
	string getIp() {
		return ip;
	}

	string getUploadSpeed() {
		return uploadSpeed;
	}

	string getDownloadSpeed() {
		return downloadSpeed;
	}

	/*
	string getAll() {
		string allNetStat="";

		allNetStat += "IP: ";
		allNetStat += getIpAddr() + ", ";
		//allNetStat += "\n";
		allNetStat += getInternetSpeed();

		return allNetStat;
	}
	*/

};


