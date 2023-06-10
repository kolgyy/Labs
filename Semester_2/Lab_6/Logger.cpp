#include "Logger.h"
#include <iomanip> 

logging::Logger::Logger(std::string filename, LogLevel level) {
	m_logLevel = level; // ��������� ������ �����������
	m_fileStream.open(filename.c_str(), std::ios::out | std::ios::app); // �������� ����� ��� ������
}

logging::Logger::~Logger() {
	m_fileStream.close(); // �������� �����
}

void logging :: Logger::setLogLevel(LogLevel level) { // ����� ��������� ������ �����������
	m_logLevel = level;
}

void logging :: Logger::log(std::string message, LogLevel level) {
	if (level >= m_logLevel) { // ����� �� ���������� ��������� � ���
		std::time_t t = std::time(nullptr);
		std::tm tm = *std::localtime(&t);

		std::string logLevelString = getLogLevelString(level); // ��������� ������ ��� ������ �����������
		std::time_t now = std::time(nullptr); // ��������� �������� ������� � ��������
		std::tm tm_ = *std::localtime(&now); // �������������� �������� ������� � ��������� std::tm
		char buffer[100]; // �������� ������ ��� �������� ����������������� ���� � �������
		std::strftime(buffer, 100, "%d.%m.%Y %H:%M:%S", &tm); // �������������� ���� � ������� � ������ � �����
		std::string timestamp(buffer); // �������������� ����������������� ���� � ������� � string
		std::string logMessage = "[" + timestamp + "] " + "[" + logLevelString + "] " + message; // ������������ ��������� ����
		if (level >= LogLevel::Error) {
			std::cerr << logMessage << std::endl;
		}
		else {
			std::cout << logMessage << std::endl;
		}
		m_fileStream << logMessage << std::endl; // ������ ��������� � ����

	}
}

std::string logging:: Logger::getLogLevelString(LogLevel level) { // ����� ��� ��������� ������, �������������� ������ �����������
	switch (level) {
	case LogLevel::Debug:
		return "\033[0;34m" + std::string("DEBUG") + "\033[0m";
	case LogLevel::Info:
		return "\033[0;32m" + std::string("INFO") + "\033[0m";
	case LogLevel::Warning:
		return "\033[0;33m" + std::string("WARNING") + "\033[0m";
	case LogLevel::Error:
		return "\033[0;31m" + std::string("ERROR") + "\033[0m";
	case LogLevel::Fatal:
		return "\033[1;31m" + std::string("FATAL") + "\033[0m";
	default:
		return std::string("");
	}
}
