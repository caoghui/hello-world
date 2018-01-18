#pragma once

//windows:

//linux :
//
#include <cstdio>
#include <cstring>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

using namespace std::chrono;

#ifdef USR_LOG4CPP

#include "log4cpp/Category.hh"
#include "log4cpp/CategoryStream.hh"
#include "log4cpp/PropertyConfigurator.hh"
using namespace log4cpp;

LOG4CPP_LOGGER("Root")

#define LOG_R_N(msg) LOG4CPP_NOTICE_S((logger)) << "[" << __FUNCTION__ << ":" << __LINE__ << "] =>: " << msg;
#define LOG_R_D(msg) LOG4CPP_DEBUG_S ((logger)) << "[" << __FUNCTION__ << ":" << __LINE__ << "] =>: " << msg;
#define LOG_R_I(msg) LOG4CPP_INFO_S  ((logger)) << "[" << __FUNCTION__ << ":" << __LINE__ << "] =>: " << msg;
#define LOG_R_W(msg) LOG4CPP_WARN_S  ((logger)) << "[" << __FUNCTION__ << ":" << __LINE__ << "] =>: " << msg;
#define LOG_R_E(msg) LOG4CPP_ERROR_S ((logger)) << "[" << __FUNCTION__ << ":" << __LINE__ << "] =>: " << msg;
#define LOG_R_F(msg) LOG4CPP_FATAL_S ((logger)) << "[" << __FUNCTION__ << ":" << __LINE__ << "] =>: " << msg;

#else

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define LOG_R(fmt, ...)  \
       printf(__FILE__ ":" STR(__LINE__) " " fmt "\n", ##__VA_ARGS__)

#define LOG(fmt, ...)	do{\
	fprintf(stderr, "[%s][%5u][DEBUG][", "time",this_thread::get_id());\
	fprintf(stderr, __func__ ":" STR(__LINE__) "] =>: " fmt "\n", ##__VA_ARGS__);\
	fflush(stderr);\
}while(0)

	//CTime m_StartTime1 = CTime::GetCurrentTime();
	//CString time = m_StartTime1.Format("%Y-%m-%d %H:%M:%S");
	//fprintf(stderr, "[%s][%5u]", RPCFXServer::Helper::CString2char(time), this_thread::get_id());
	//fprintf(stderr, "[DEBUG][" __FUNCTION__ ":" STR(__LINE__) "] =>: " fmt "", ##__VA_ARGS__);

#define LOG_T(fmt, ...)	do{\
	fprintf(stderr, "[%5u]", this_thread::get_id());\
	fprintf(stderr, "[DEBUG]["__FUNCTION__":" STR(__LINE__) "] =>: " fmt "", ##__VA_ARGS__);\
	fflush(stderr);\
}while(0)

#define LOG_I(...) do{\
    fprintf(stderr, "%s:%s:%d", __FILE__, __FUNCTION__, __LINE__);\
    time_t tt = system_clock::to_time_t(std::chrono::system_clock::now());\
	char buf[52]; memset(buf, 0, sizeof(buf));\
	ctime_s(buf, sizeof(buf) - 1, &tt);\
    fprintf(stderr, "%s", buf);\
	fprintf(stderr, __VA_ARGS__);\
	fprintf(stderr, "\n");\
  }while(0)

//printf(__FUNCTION__ ":" STR(__LINE__) " =>: " fmt " ", ##__VA_ARGS__)
//printf("LOG =>: " fmt " ", ##__VA_ARGS__)
//printf(__FILE__ ":" STR(__LINE__) " =>: " fmt " ", ##__VA_ARGS__)
#define ERR(fmt, ...) \
	fprintf(stderr, "Error: " __FILE__ ":" STR(__LINE__) " " fmt "\n", ##__VA_ARGS__)

#endif