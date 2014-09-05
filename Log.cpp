#include "Log.h"

Log::Log(std::string logfilename)
{
	logfile.open(logfilename.c_str(), ios::out);
}

Log::~Log()
{
	logfile.close();
}

void Log::write(std::string tag, std::string content)
{
	if(!logfile.is_open()) {
		return;
	}

	logfile<<tag<<" "<<content<<std::endl;
}
