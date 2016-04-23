#include "Logger.h"	
#include <stdarg.h>

namespace edolphin
{
	

Logger::Logger (const char* logFilePath) {
	file = fopen(logFilePath, "w+");
}

Logger::~Logger () {
	fclose(file);
}


void Logger::debug(const char* fmt, ...) {
	FORMAT(buffer, fmt);
	this->write("DEBUG", buffer);
}

void Logger::info(const char* fmt, ...) {
	FORMAT(buffer, fmt);
	this->write("INFO", buffer);
}


void Logger::write(const char* level, char* msg) {
	if (file != NULL) {
		fprintf(file, "[%s] %s\n", level, msg);
	}
}


} /* edolphin */ 
