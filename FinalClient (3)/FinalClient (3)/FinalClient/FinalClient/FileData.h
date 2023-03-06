#pragma once
#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<sstream>

using namespace std;

//class FileData
//{
//	string file;
//	//Reading Data from a file and converting into String.
//	void initFile() {
//		system("systeminfo>data.txt");
//		//string path = 
//		ifstream f("data.txt");
//		string str;
//		if (f) {
//			ostringstream ss;
//			ss << f.rdbuf();
//			str = ss.str();
//		}
//		file = str;
//	}
//
//	/*Deleting the file created in init() to create a fresh
//	file at the instant of every run.*/
//	void closeFile() {
//		system("del data.txt");
//	}
//public:
//
//	FileData() {
//		initFile();
//	}
//
//	~FileData() {
//		closeFile();
//	}
//
//
//
//	string getOsName() {
//
//		int startIndex = file.find("OS Name:");
//		startIndex += 27;
//		int endIndex = file.find("OS Version:");
//
//		//cout<< file.substr(startIndex, endIndex - startIndex);
//		return file.substr(startIndex, endIndex - startIndex - 1);
//	}
//
//	string getOsVersion() {
//		
//		int startIndex = file.find("OS Version:");
//		startIndex += 27;
//		int endIndex = file.find("OS Manufacturer:");
//
//		return file.substr(startIndex, endIndex - startIndex - 1);
//		
//
//		/*
//		OSVERSIONINFOEX osvInfo = {0};
//		osvInfo.dwOSVersionInfoSize = sizeof(osvInfo);
//
//		// Need to typecast, function takes OSVERSIONINFO
//		GetVersionEx((OSVERSIONINFO*)&osvInfo);
//		
//		std::ostringstream stream;
//		stream << osvInfo.dwMajorVersion;
//		stream << osvInfo.dwMinorVersion;
//		string str = stream.str();
//		return str;*/
//	}
//
//	string getProductID() {
//
//		int startIndex = file.find("Product ID:");
//		startIndex += 27;
//		int endIndex = file.find("Original Install Date:");
//
//		return file.substr(startIndex, endIndex - startIndex - 1);
//	}
//
//	string getSystemType() {
//
//		int startIndex = file.find("System Type:");
//		startIndex += 27;
//		int endIndex = file.find("Processor(s):");
//
//		return file.substr(startIndex, endIndex - startIndex - 1);
//	}
//
//	string getSystemBootTime() {
//
//		int startIndex = file.find("System Boot Time:");
//		startIndex += 27;
//		int endIndex = file.find("System Manufacturer:");
//
//		return file.substr(startIndex, endIndex - startIndex - 1);
//	}
//};

class FileData
{
	string file;
	string toBeDeleteFile;
	//Reading Data from a file and converting into String.
	void initFile() {
		system(("systeminfo>data" + this->toBeDeleteFile).c_str());
		ifstream f(("data" + this->toBeDeleteFile).c_str());
		string str;
		if (f) {
			ostringstream ss;
			ss << f.rdbuf();
			str = ss.str();
		}
		file = str;
	}

	/*Deleting the file created in init() to create a fresh
	file at the instant of every run.*/
	void closeFile() {
		system(("del data" + this->toBeDeleteFile).c_str());
	}
public:

	FileData(string path) {
		this->toBeDeleteFile = path + ".txt";
		initFile();
	}

	~FileData() {
		closeFile();
	}



	string getOsName() {

		int startIndex = file.find("OS Name:");
		startIndex += 27;
		int endIndex = file.find("OS Version:");

		//cout<< file.substr(startIndex, endIndex - startIndex);
		return file.substr(startIndex, endIndex - startIndex - 1);
	}

	string getOsVersion() {

		int startIndex = file.find("OS Version:");
		startIndex += 27;
		int endIndex = file.find("OS Manufacturer:");

		return file.substr(startIndex, endIndex - startIndex - 1);


		/*
		OSVERSIONINFOEX osvInfo = {0};
		osvInfo.dwOSVersionInfoSize = sizeof(osvInfo);

		// Need to typecast, function takes OSVERSIONINFO
		GetVersionEx((OSVERSIONINFO*)&osvInfo);

		std::ostringstream stream;
		stream << osvInfo.dwMajorVersion;
		stream << osvInfo.dwMinorVersion;
		string str = stream.str();
		return str;*/
	}

	string getProductID() {

		int startIndex = file.find("Product ID:");
		startIndex += 27;
		int endIndex = file.find("Original Install Date:");

		return file.substr(startIndex, endIndex - startIndex - 1);
	}

	string getSystemType() {

		int startIndex = file.find("System Type:");
		startIndex += 27;
		int endIndex = file.find("Processor(s):");

		return file.substr(startIndex, endIndex - startIndex - 1);
	}

	string getSystemBootTime() {

		int startIndex = file.find("System Boot Time:");
		startIndex += 27;
		int endIndex = file.find("System Manufacturer:");

		return file.substr(startIndex, endIndex - startIndex - 1);
	}
};


