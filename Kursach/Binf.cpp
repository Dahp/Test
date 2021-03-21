#include "Binf.h"
#include <new>


Binf::Binf(string name)
{
	FileName = name;

	file.open(FileName, ios::in | ios::out | ios::binary | ios::app);

}
void Binf::write(const string& data)
{
	size_t len = data.length() + 1;
	file.write((char*)&len, sizeof(len));
	file.write((char*)data.c_str(), len);
}

void Binf::read(string& data)
{
	size_t len;
	file.read((char*)&len, sizeof(len));
	char* buf;
	buf = new char[len];
	file.read(buf, len);
	data = buf;
	delete[] buf;
}

void Binf::write(const int& num)
{
	file.close();

	file.open(FileName, ios::in | ios::out | ios::trunc | ios::binary);

	file << num;
}

void Binf::read(int& num)
{
	file.seekg(0, ios::beg);
	file >> num;
}

Binf::~Binf()
{
	file.close();
}
