#pragma once
#include <windows.h>
#include <stdio.h>
#include <iostream>
#pragma comment(lib, "user32.lib")
#include <tchar.h>
#include <winsock.h>
#include <lmcons.h>
#include <string>
#include<chrono>
#include<ctime>
#include<iomanip>
#include<sstream>
using namespace std;

class SystemInfo
{

private:

    string availableRam;
    string totalRam;

public:

    SystemInfo() {
        getAvailMem();
    }

    string getUpTime() {

        string uptime = "";

        int nSysUpTime = GetTickCount64() / 1000;
        int hours = nSysUpTime / 3600;
        nSysUpTime %= 3600;
        int minutes = nSysUpTime / 60;
        nSysUpTime %= 60;
        int seconds = nSysUpTime;

        uptime = to_string(hours) + ":" + to_string(minutes);
        uptime += ":";
        uptime += to_string(seconds);
        return uptime;

    }

    string getCurrentTime() {

        char str[26];
        auto currentTime = std::chrono::system_clock::now();
        std::time_t currentTime2 = std::chrono::system_clock::to_time_t(currentTime);
        ctime_s(str, 26, &currentTime2);

        string time = str;

        return time;
    }

    string getUserName() {

        TCHAR Username[UNLEN + 1];
        DWORD nULen = UNLEN;

        GetUserName(Username, &nULen);

        string str;
        wstring wStr = Username;
        str = std::string(wStr.begin(), wStr.end());
        return str;
    }

    string getComputerName() {
        TCHAR  szComputerName[MAX_COMPUTERNAME_LENGTH + 1];
        DWORD  lnNameLength = MAX_COMPUTERNAME_LENGTH;

        GetComputerName(szComputerName, &lnNameLength);

        string str;
        wstring wStr = szComputerName;
        str = string(wStr.begin(), wStr.end());
        return str;
    }

    void getAvailMem() {

        string value = "";
        MEMORYSTATUSEX memoryStatus;
        memoryStatus.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&memoryStatus);

        const float oneGB = 1024 * 1024 * 1024;

        this->availableRam = to_string(memoryStatus.ullAvailPhys / oneGB);
        this->totalRam = to_string(memoryStatus.ullTotalPhys / oneGB);

        /*
        value += to_string(memoryStatus.ullAvailPhys / oneGB);
        value += "/";
        value += to_string(memoryStatus.ullTotalPhys / oneGB);
        value += "GB";

        return value;
        */
    }

    string getAvailableRam() {
        return availableRam;
    }

    string getTotalRam() {
        return totalRam;
    }

    string DisplayDriveSizes()
    {
        string value = "";
        TCHAR szDrives[MAX_PATH + 1];
        DWORD dwLen = GetLogicalDriveStrings(MAX_PATH, szDrives);
        TCHAR* pLetter = szDrives;

        ULARGE_INTEGER liFree, liTotal;
        while (*pLetter)
        {
            //  Get size, ignoring disk-quotas.
            GetDiskFreeSpaceEx(pLetter, NULL, &liTotal, &liFree);

            // Display information
            value += "Drive ";
            value += *pLetter;
            value += ": ";
            value += to_string(liFree.QuadPart / (float)(1 << 30));
            value += " GB ";

            while (*++pLetter);
            pLetter++;
        }



        return value;
    }

    int getIdleTime() {
        LASTINPUTINFO info;
        info.cbSize = sizeof(info);
        GetLastInputInfo(&info);
        DWORD idleSeconds = (GetTickCount64() - info.dwTime) / 1000;

        return stoi(to_string(idleSeconds));

    }
};


