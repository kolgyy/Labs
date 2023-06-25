#include "Logger.h"

int main() {

	logging :: Logger logger("log.txt", logging :: LogLevel::Debug); // Создание объекта класса и уровнем логирования debug

	logger.log("This is an info message", logging :: LogLevel::Info); // Запись сообщений лога разных уровней
	logger.log("This is a debug message", logging :: LogLevel::Debug);
	logger.log("This is an error message",logging :: LogLevel::Error);
	logger.log("This is a fatal message", logging :: LogLevel::Fatal);
	logger.log("This is a warning message",logging :: LogLevel::Warning);

	logger.setLogLevel(logging::LogLevel::Info); // Изменение уровня логирования

	logger.log("This message should be logged with Info level", logging :: LogLevel::Info); // Запись лога с новый уровнем

	return 0;
}

