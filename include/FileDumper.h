#include <iostream>
#include <fstream>

class FileDumper {
public:
	FileDumper(const std::string& filename);
	~FileDumper();
	void dump();
	int getFileSize() const { return m_file_size; }
	char* getBuffer() const { return m_buffer; }

private:
	std::ifstream m_file;
	int m_file_size = m_file.tellg();
	char* m_buffer = new char[m_file_size];
};