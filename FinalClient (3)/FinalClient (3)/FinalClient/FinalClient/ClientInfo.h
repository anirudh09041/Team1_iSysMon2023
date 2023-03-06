#pragma once

#include<string>
#include "CPULoad.h"
#include "NetworkInfo.h"
#include "FileData.h"
#include "SystemInfo.h"
using namespace std;

class ClientInfo
{
public:

	string systemName;
	string userName;
	float cpuUtilization;
	string hddUtilization;
	string availableRam;
	string totalRam;
	string ip;
	string downloadSpeed;
	string uploadSpeed;
	//string networkStat;
	int systemIdleWindow;
	string currentTime;
	string osName;
	string osVersion;
	string productID;
	string systemType;
	string systemBootTime;
	string systemUpTime;



	ClientInfo(string path) {
		SystemInfo si;
		CPULoad cl;
		NetworkInfo ni(path);
		FileData fd(path);


		Sleep(500);

		//Assigning value to the ClientInfo Object
		setSystemName(si.getComputerName());
		setUserName(si.getUserName());
		setCpuUtilization(cl.getAverage());
		setHddUtilization(si.DisplayDriveSizes());

		setAvailableRam(si.getAvailableRam());
		setTotalRam(si.getTotalRam());

		setSystemIdleWindow(si.getIdleTime());
		setCurrentTime(si.getCurrentTime());
		setUpTime(si.getUpTime());

		setOSName(fd.getOsName());
		setOSVersion(fd.getOsVersion());
		setProductID(fd.getProductID());
		setSystemType(fd.getSystemType());
		setSystemBootTime(fd.getSystemBootTime());

		setIp(ni.getIp());
		setDownloadSpeed(ni.getDownloadSpeed());
		setUploadSpeed(ni.getUploadSpeed());

	}

	void setSystemName(string sysName) {
		this->systemName = sysName;
	}

	void setUserName(string uname) {
		this->userName = uname;
	}

	void setCpuUtilization(float cu) {
		this->cpuUtilization = cu;
	}

	void setHddUtilization(string hu) {
		this->hddUtilization = hu;
	}

	void setAvailableRam(string ar) {
		this->availableRam = ar;
	}

	void setTotalRam(string sr) {
		this->totalRam = sr;
	}

	void setSystemIdleWindow(int sw) {
		this->systemIdleWindow = sw;
	}

	void setCurrentTime(string ct) {
		this->currentTime = ct;
	}

	void setOSName(string on) {
		this->osName = on;
	}

	void setOSVersion(string ov) {
		this->osVersion = ov;
	}

	void setProductID(string pi) {
		this->productID = pi;
	}

	void setSystemType(string st) {
		this->systemType = st;
	}

	void setSystemBootTime(string bt) {
		this->systemBootTime = bt;
	}

	void setUpTime(string ut) {
		this->systemUpTime = ut;
	}

	void setIp(string ipa) {
		this->ip = ipa;
	}

	void setDownloadSpeed(string ds) {
		this->downloadSpeed = ds;
	}

	void setUploadSpeed(string us) {
		this->uploadSpeed = us;
	}


	string getSystemName() {
		return systemName;
	}

	string getUserName() {
		return userName;
	}

	float getCpuUtilization() {
		return cpuUtilization;
	}

	string getHddUtilization() {
		return hddUtilization;
	}

	string getAvailableRam() {
		return availableRam;
	}

	string getTotalRam() {
		return totalRam;
	}

	string getIp() {
		return ip;
	}

	string getDownloadSpeed() {
		return downloadSpeed;
	}

	string getUploadSpeed() {
		return uploadSpeed;
	}

	int getSystemIdleWindow() {
		return systemIdleWindow;
	}

	string getCurrentTime() {
		return currentTime;
	}

	string getOsName() {
		return osName;
	}

	string getOsVersion() {
		return osVersion;
	}

	string getProductId() {
		return productID;
	}

	string getSystemType() {
		return systemType;
	}

	string getSystemBootTime() {
		return systemBootTime;
	}

	string getSystemUpTime() {
		return systemUpTime;
	}
};

