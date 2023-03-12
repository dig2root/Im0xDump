#include "FileDumper.h"

FileDumper::FileDumper(const std::string& filename) : m_file(filename) {}

FileDumper::~FileDumper() {
	m_file.close();
}

void FileDumper::dump() {
	if (!m_file.is_open()) {
		std::cout << "File is not open" << std::endl;
		return;
	}

	std::cout << "Dumping file..." << std::endl;

	// Get file size
	m_file.seekg(0, std::ios::end);
	m_file_size = m_file.tellg();
	m_file.seekg(0, std::ios::beg);
	std::cout << "File size: " << m_file_size << std::endl;

	// Read file into buffer
	m_buffer = new char[m_file_size];
	m_file.read(m_buffer, m_file_size);
}