#pragma once
#pragma comment(lib, "pdh.lib")
#include "TCHAR.h"
#include "pdh.h"
#include <string>
#include<iostream>
#include<Windows.h>

using namespace std;

class CPULoad
{
public:
    PDH_HQUERY cpuQuery;
    PDH_HCOUNTER cpuTotal;

    void init() {
        PdhOpenQuery(NULL, NULL, &cpuQuery);
        // You can also use L"\\Processor(*)\\% Processor Time" and get individual CPU values with PdhGetFormattedCounterArray()
        PdhAddEnglishCounter(cpuQuery, L"\\Processor(_Total)\\% Processor Time", NULL, &cpuTotal);
        PdhCollectQueryData(cpuQuery);
    }

    double getCurrentValue() {
        PDH_FMT_COUNTERVALUE counterVal;

        PdhCollectQueryData(cpuQuery);
        PdhGetFormattedCounterValue(cpuTotal, PDH_FMT_DOUBLE, NULL, &counterVal);
        return counterVal.doubleValue;
    }

    double getCPULoad() {

        init();
        return getCurrentValue();

    }
    /*
    static float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
    {
        static unsigned long long _previousTotalTicks = 0;
        static unsigned long long _previousIdleTicks = 0;

        unsigned long long totalTicksSinceLastTime = totalTicks - _previousTotalTicks;
        unsigned long long idleTicksSinceLastTime = idleTicks - _previousIdleTicks;

        float ret = 1.0f - ((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime) / totalTicksSinceLastTime : 0);

        _previousTotalTicks = totalTicks;
        _previousIdleTicks = idleTicks;
        return ret;
    }

    static unsigned long long FileTimeToInt64(const FILETIME& ft) { return (((unsigned long long)(ft.dwHighDateTime)) << 32) | ((unsigned long long)ft.dwLowDateTime); }

    // Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
    // You'll need to call this at regular intervals, since it measures the load between
    // the previous call and the current one.  Returns -1.0 on error.
    float GetCPULoad()
    {
        FILETIME idleTime, kernelTime, userTime;
        return GetSystemTimes(&idleTime, &kernelTime, &userTime) ? CalculateCPULoad(FileTimeToInt64(idleTime), FileTimeToInt64(kernelTime) + FileTimeToInt64(userTime)) : -1.0f;
    }
    */
    float getAverage() {
        double avg = 0.0;

        for (int i = 0; i < 50; i++) {

            avg += getCPULoad();
            Sleep(10);
            //cout << getCPULoad()*100<<" ";
        }
        avg /= 50;
        int c = (int)(avg * 100 + .5);
        float b = c / 100.0;
        return b;

    }
};


