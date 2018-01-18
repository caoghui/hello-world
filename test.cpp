
#include <chrono>
#include <iostream>
#include <iomanip>
#include <thread>
#include <sstream>
#include <ctime>
#include "log.hpp"
#include "ScopeGuard.hpp"
using namespace std;
using namespace std::chrono;

void test_scope();

void thd_func()
{    
    LOG_R_I("Log_R print!");
    cout << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::seconds(3));
}

int main(int argc, char** argv)
{
    //LOG_I("Hello World!");
    //thread thd(thd_func);
    //thd.join();

    LOG_R_I("this is %d line", __LINE__);

    LOG_R_D("this is a log level debug");
    
    LOG_D("this is a simple msg");
    LOG_D("this is "<<4<<" msg");
    LOG_D("the thread id is " << std::this_thread::get_id() << " is running ");
    
    LOG_R_I("this is a info msg");
    LOG_R_D("this is a debug msg");
    LOG_R_W("this is a warn msg");
    LOG_R_E("this is a error msg");

    test_scope();

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

void test_scope()
{
    ON_SCOPE_EXIT([](){ cout << " scope exit" << endl;});
}