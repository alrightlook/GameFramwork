#ifndef LOG_HEADER
#define LOG_HEADER
#include <iostream>
#include <fstream>
using namespace std;
class Log
{
	public:
		Log(std::string logfilename);
		~Log();
		void write(std::string tag, std::string content);
	private:
		fstream logfile;
};
#endif
