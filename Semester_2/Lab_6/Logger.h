#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

namespace logging {
enum class LogLevel {
	Debug,
	Info,
	Warning,
	Error,
	Fatal
};

class Logger {
public:
	Logger(std::string filename, LogLevel level = LogLevel::Info); // ����������� ��������� ��� ����� � ������� �����������
	~Logger(); // �������� �����
	void setLogLevel(LogLevel level); // ��������� ������ �����������
	void log(std::string message, LogLevel level = LogLevel::Info); // ������ � ������� � ����

private:
	LogLevel m_logLevel; // ������� �����������

	std::ofstream m_fileStream; // ����� ��� ������ � ����

	std::string getLogLevelString(LogLevel level);
};

}