#pragma once
#include "Libr.h"

class BaseException
{
protected:
	string msg;

public:
	BaseException(string msg) { this->msg = msg; }
	virtual string what() = 0;
};

class FileException : public BaseException
{
public:
	FileException(string msg, string filename) : BaseException(msg)
	{
		this->filename = filename;
	}
	string what() { return msg; }
private:
	string filename;
};

class InputException : public BaseException
{
public:
	InputException(string msg, int idata) : BaseException(msg)
	{
		this->idata = idata;
		sdata = "empty";
	}
	InputException(string msg, string sdata) : BaseException(msg)
	{
		idata = 0;
		this->sdata = sdata;
	}
	string what() { return msg; }
	int GetIntData() { return idata; }
	string GetStingData() { return sdata; }
private:
	int idata;
	string sdata;
};