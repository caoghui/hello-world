#include <iostream>
#include "log.hpp"
#include "Thread.hpp"
using namespace std;

class MyWork : public CThread
{
	virtual int work()
	{
		LOG_D("thd id "<< this_thread::get_id() << " running..");
		sleep_for(5);
		return 0;
	}
	
};

int main(int argc, char** argv)
{
	LOG_R_D("thread class running...");
	MyWork thd;
	thd.start();
	thd.join();
	LOG_R_D("worker thread complete...");
	return 0;
}