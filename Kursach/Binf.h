#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Binf
{
	fstream file;
	string FileName;
public:
	Binf(string name);
	~Binf();
	void read(string& data);
	void write(const string& data);
	void write(const int& num);
	void read(int& num);
	void close();
};

