#include <iostream>
#include <algorithm>
#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include "timer.h"
#include "fpm.h"

class InputParser{
	public:
		InputParser (int &argc, char **argv)
		{
			for (int i=1; i < argc; ++i) {
				this->tokens.push_back(std::string(argv[i]));
			}
		}

		const std::string& getCmdOption(const std::string &option) const
		{
			std::vector<std::string>::const_iterator itr;
			itr =  std::find(this->tokens.begin(), this->tokens.end(), option);
			if (itr != this->tokens.end() && ++itr != this->tokens.end()) {
				return *itr;
			}
			return "";
		}

		bool cmdOptionExists(const std::string &option) const
		{
			return std::find(this->tokens.begin(), this->tokens.end(), option) != this->tokens.end();
		}
	private:
		std::vector <std::string> tokens;
};

class Display
{
public:
	Display(WINDOW *win, const std::string &statusUrl): window(win), info(statusUrl) {
	}
	
	void update()
	{
		info.update();
/*
top - 16:02:16 up 15 days, 23:35,  6 users,  load average: 1,47, 0,97, 0,82
Tasks: 319 total,   2 running, 317 sleeping,   0 stopped,   0 zombie
%Cpu(s): 14,5 us,  5,7 sy,  0,0 ni, 67,5 id, 11,9 wa,  0,0 hi,  0,3 si,  0,0 st
КиБ Mem:   8288544 total,  7651296 used,   637248 free,   321256 buffers
КиБ Swap: 12285948 total,   799456 used, 11486492 free.  3237308 cached Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
 1115 root      20   0       0      0      0 S   7,6  0,0   6:07.28 cifsd
 4114 max       20   0 1499484 442160  66488 S   6,6  5,3 186:04.77 firefox
10264 max       20   0  317320 158956  28940 S   4,3  1,9 106:41.18 kate
*/
		int width;
		int height;
		getmaxyx(window, height, width);

		int days = info.startSince / 60 / 60 / 24;
		int hours = (info.startSince / 60 / 60) % 24;
		int minutes = (info.startSince / 60) % 60;
		int seconds = info.startSince % 60;

		wprintw(window, "%s - %s up %d days, %d:%d\n"
			,info.poolName.c_str()
			,info.currentTime.c_str()
			,days, hours, minutes
		);

		wprintw(window, "Listen queue: %d, max %d, len %d\n"
			,info.listenQueue
			,info.maxListenQueue
			,info.listenQueueLen
		);

		wprintw(window, "Processes: %d total, %d active, %d idle\n"
			,info.totalProcesses
			,info.activeProcesses
			,info.idleProcesses
		);

		//startTime = xml.child("start-time").text().as_int();
		//startSince = xml.child("start-since").text().as_int();
		//requests = xml.child("requests").text().as_int();
		//requestDuration = xml.child("request-duration").text().as_int();
		//contentLength = xml.child("content-length").text().as_int();
		//user = xml.child("user").text().get();
		//script = xml.child("script").text().get();
		//lastRequestCpu = xml.child("content-length").text().as_double();
		//lastRequestMemory = xml.child("content-length").text().as_int();

		attron(A_REVERSE);
		std::string header = std::string("\n   PID    STATE               DOMAIN METHOD URI");
		header.resize(width, ' ');
		wprintw(window, header.c_str());
		attroff(A_REVERSE);
		int y = 5;
		for (auto it = info.proc.begin(); it != info.proc.end(); ++it)
		{
			std::string line = fpm::string_format("%6d %8s %20s %-6s %s\n"
				,it->pid
				,it->state.c_str()
				,it->requestDomain.c_str()
				,it->requestMethod.c_str()
				,it->requestUri.c_str()
			);
			line.resize(width, ' ');
			mvaddstr(y++, 0, line.c_str());
			if (y > height) {
				break;
			}
		}

		//wprintw(window, info.dashBoard.c_str());
		move(0, 0);
		refresh();
	}
private:
	fpm info;
	WINDOW *window;
};

void mainLoop(const std::string statusUrl)
{
	int ch;
	nodelay(stdscr, TRUE);
	WINDOW *win = initscr();

 	Timer t;
	Display mainDisplay(win, statusUrl);
	// Assume "t" is a Timer
	auto tid = t.create(1000, 1000, std::bind(&Display::update, &mainDisplay));

	for (;;) {
		if ((ch = getch()) != ERR) {
			switch (ch) {
				case 'q':
					goto end;
			}
		}
	}

end:
	endwin();
	std::cout << "url: " << statusUrl << std::endl;
}

int main(int argc, char **argv)
{
	InputParser input(argc, argv);
	std::string statusUrl;


	if (input.cmdOptionExists("-u")) {
		const std::string &url = input.getCmdOption("-u");
		if (!url.empty()) {
			statusUrl += url;
			statusUrl += "?full&xml";
		}
	}

	if (statusUrl.empty()) {
		std::cerr << "Usage: fpmtop -u <status url>" << std::endl;
	} else {
		mainLoop(statusUrl);
	}

	return 0;
}