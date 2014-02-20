#pragma once
#include <string>
#include "DMSerial.h"
#include "qcdm.h"
#include <map>"

using namespace std;
using namespace qcdm;

class DMCommander
{
	
public:
	DMCommander(DMSerial &dmPort);

	bool getNamLock();
	bool setMode(int mode);

	string getMeid();
	string getEsn();
	string getChipset();
	string getScm();
	DMVersionInfo getVersionInfo();
	
	string getNamMdn(int nam = 0);
	string getNamMin(int nam = 0);
	string getNamBanner(int nam = 0);
	string getNamName(int nam = 0);
	string getHomeSid(int nam = 0);
	string getHomeNid(int nam = 0);
	
	string getPppUserId(int profile = 0);
	string getPppPassword(int profile = 0);
	string getPapUserId(int profile = 0);
	string getPapPassword(int profile = 0);
	string getHdrAnAuthUserIdLong(int profile = 0);
	string getHdrAnAuthPasswordLong(int profile = 0);
	string getHdrAnAuthNai(int profile = 0);
	string getHdrAnAuthPassword(int profile = 0);

// preset packets
public:
	/*
    static const char* DMCommander::readEfsSubsysSPC = {
		0x4B, 0x13, 0xF, 0x0, 0x6E, 0x76, 0x6D, 0x2F, 0x6E, 0x76, 
		0x6D, 0x2F, 0x6E, 0x76, 0x6D, 0x5F, 0x73, 0x65, 0x63, 0x75, 
		0x72, 0x69, 0x74, 0x79, 0x0, 0x2A, 0x69, 0x7E
	};

    const unsigned char readEfsSPC[] = {
		0x59, 0x4, 0x0, 0x15, 0x6E, 0x76, 0x6D, 0x2F, 0x6E, 0x76, 
		0x6D, 0x2F, 0x6E, 0x76, 0x6D, 0x5F, 0x73, 0x65, 0x63, 0x75, 
		0x72, 0x69, 0x74, 0x79, 0x0, 0x85, 0x20, 0x7E
	};

    const unsigned char readNvSPC[] = {
		0x26, 0x55, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0xA5, 0x34, 0x7E
	};

    const unsigned char readLgSPC[] = { 0x11, 0x17, 0x0, 0x8, 0x1C, 0xA6, 0x7E };

	const unsigned char readSamsungSPC[] = {
		0x26, 0x52, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x71, 0xF6, 0x7E
	};

    static unsigned char readSamsungSPCAlternate[] = {
		0x26, 0x53, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		0x0, 0x0, 0x0, 0x50, 0x68, 0x7E
	};

    const unsigned char readHtcSPC[] = {0x41, 0x74, 0x64, 0x77, 0x61, 0x6F, 0x70, 0x42, 0x4A, 0x7E};

	const unsigned char readKyoceraSPC[] = {0x29, 0x3, 0x0, 0x81, 0x73, 0x7E};
	*/
protected:
	DMSerial *dmPort;

};
