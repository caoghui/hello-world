
#include <chrono>
#include <iostream>
#include <iomanip>
#include <thread>
#include <sstream>
#include <ctime>
#include "log.hpp"
using namespace std;
using namespace std::chrono;

int main(int argc, char** argv)
{
    //LOG_I("Hello World!");
    LOG_R("Log_R print!");
    LOG_R("this is %d line", __LINE__);
    
    MSG("this is a simple msg");
    MSG("this is "<<4<<" msg");
    MSG("the thread id is " << std::this_thread::get_id() << " is running ");
    /*
    
    auto t = chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    stringstream ss; ss << std::put_time(std::localtime(&t), "[%Y-%m-%d %X]");
    ss << "[" << std::this_thread::get_id() << "][DEBUG]";
    ss << "[" << __FUNCTION__<<":"<<__LINE__<<"] =>: ";
    fprintf(stderr, "%s\n", ss.str().c_str());


    cout << std::this_thread::get_id() <<endl;
    fprintf(stderr, "%u\n", std::this_thread::get_id());
    //cout<< std::put_time(std::localtime(&t), "%Y-%m-%d %X")<<endl;
    //cout << ss.str() << endl;    
    //cout<< std::put_time(std::localtime(&t), "%Y-%m-%d %H.%M.%S")<<endl;
    //*/
}

