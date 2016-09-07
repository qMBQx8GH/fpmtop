#include "fpm.h"

#include <string.h>
#include <stdarg.h>
#include <memory>
#include <list>
#include <curl/curl.h>
#include <pugixml.hpp>

fpm::fpm(const std::string &statusUrl): currentTime(""), dashBoard(""), url(statusUrl)
{
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, statusUrl.c_str());
}

fpm::~fpm()
{
	 curl_easy_cleanup(curl);
}

void fpm::update()
{
	time_t ct;
	struct tm *lt;

	time(&ct);                   // Get the current time
	lt = localtime(&ct);  // Convert the current time to the local time

	currentTime = string_format("%02d:%02d:%02d", lt->tm_hour, lt->tm_min, lt->tm_sec);

	url_data.str(std::string());
	poolName = std::string();
	startSince = 0;
	listenQueue = 0;
	maxListenQueue = 0;
	listenQueueLen = 0;
	totalProcesses = 0;
	activeProcesses = 0;
	idleProcesses = 0;
	proc.clear();

	CURLcode res;
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fpm::write_data);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &url_data);
	res = curl_easy_perform(curl);
	if (res != CURLE_OK) {
		dashBoard = string_format("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
	} else {
		dashBoard = "";
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_string(url_data.str().c_str());

		poolName = doc.child("status").child("pool").text().get();
		startSince = doc.child("status").child("start-since").text().as_int();
		listenQueue = doc.child("status").child("listen-queue").text().as_int();
		maxListenQueue = doc.child("status").child("max-listen-queue").text().as_int();
		listenQueueLen = doc.child("status").child("listen-queue-len").text().as_int();

		totalProcesses = doc.child("status").child("total-processes").text().as_int();
		activeProcesses = doc.child("status").child("active-processes").text().as_int();
		idleProcesses = doc.child("status").child("idle-processes").text().as_int();

		pugi::xml_node processes =  doc.child("status").child("processes");
		for (pugi::xml_node_iterator it = processes.begin(); it != processes.end(); ++it)
		{
			process p(*it);
			proc.push_back(p);
		}

		dashBoard += "\n------------------------------\n";
		dashBoard += std::string(url_data.str());
	}
}

size_t fpm::write_data(void *ptr, size_t size, size_t nmemb, std::stringstream *data)
{
	size_t n = (size * nmemb);
	data->write((char *)ptr, n);
	return n;
}

std::string fpm::string_format(const std::string fmt_str, ...)
{
	int final_n, n = ((int)fmt_str.size()) * 2; /* Reserve two times as much as the length of the fmt_str */
	std::string str;
	std::unique_ptr<char[]> formatted;
	va_list ap;
	while(1) {
		formatted.reset(new char[n]); /* Wrap the plain char array into the unique_ptr */
		strcpy(&formatted[0], fmt_str.c_str());
		va_start(ap, fmt_str);
		final_n = vsnprintf(&formatted[0], n, fmt_str.c_str(), ap);
		va_end(ap);
		if (final_n < 0 || final_n >= n) {
			n += abs(final_n - n + 1);
		} else {
			break;
		}
	}
	return std::string(formatted.get());
}

process::process(const pugi::xml_node &xml)
{
	pid = xml.child("pid").text().as_int();
	state = xml.child("state").text().get();
	startTime = xml.child("start-time").text().as_int();
	startSince = xml.child("start-since").text().as_int();
	requests = xml.child("requests").text().as_int();
	requestDuration = xml.child("request-duration").text().as_int();
	requestMethod = xml.child("request-method").text().get();
	requestDomain = xml.child("request-domain").text().get();
	requestUri = xml.child("request-uri").text().get();
	contentLength = xml.child("content-length").text().as_int();
	user = xml.child("user").text().get();
	script = xml.child("script").text().get();
	lastRequestCpu = xml.child("content-length").text().as_double();
	lastRequestMemory = xml.child("content-length").text().as_int();
}