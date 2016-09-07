#ifndef FPM_H
#define FPM_H

#include <string>
#include <sstream>
#include <list>
#include <curl/curl.h>
#include <pugixml.hpp>

class process
{
public:
	int pid;
	std::string state;
	time_t startTime;
	time_t startSince;
	int requests;
	int requestDuration;
	std::string requestMethod;
	std::string requestDomain;
	std::string requestUri;
	int contentLength;
	std::string user;
	std::string script;
	double lastRequestCpu;
	size_t lastRequestMemory;
	process(const pugi::xml_node &xml);
};

class fpm
{
public:
	fpm(const std::string &statusUrl);
	~fpm();
	void update();
	static std::string string_format(const std::string fmt_str, ...);

	std::string poolName;
	int startSince;
	int listenQueue;
	int maxListenQueue;
	int listenQueueLen;

	int totalProcesses;
	int activeProcesses;
	int idleProcesses;

	std::string currentTime;

	std::list<process> proc;
	std::string dashBoard;
private:
	const std::string url;
	CURL *curl;

	std::stringstream url_data;
	static size_t write_data(void *ptr, size_t size, size_t nmemb, std::stringstream *data);
};

#endif // FPM_H