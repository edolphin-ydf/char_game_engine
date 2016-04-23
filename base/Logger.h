#ifndef LOGGER_H_IA4RPV6J
#define LOGGER_H_IA4RPV6J

#include <stdio.h>

namespace edolphin
{

#define FORMAT(_buffer, _fmt)	\
	va_list argptr;	\
	char _buffer[1024] = {0};	\
	va_start(argptr, _fmt);	\
	vsnprintf(_buffer, sizeof(_buffer)-1, _fmt, argptr);	\
	va_end(argptr)

class Logger
{
public:
	Logger (const char* logFilePath);
	virtual ~Logger ();

	void debug(const char* fmt, ...);
	void info(const char* fmt, ...);

	void write(const char* level, char* msg);

private:
	FILE* file;	
};

} /* edolphin */ 

#endif /* end of include guard: LOGGER_H_IA4RPV6J */
