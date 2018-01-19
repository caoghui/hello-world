#include <iostream>
//#include "log.hpp"
#include "SmartAssert.hpp"

using namespace std;

#if __cplusplus < 201103L
//#error "should use C++11 implementation"
#endif

#define LOG(...) {\
	fprintf(stderr, "%s: Line %d: Fun: %s\t", __FILE__, __LINE__, __func__);\
	fprintf(stderr, __VA_ARGS__);\
	fprintf(stderr, "\n");\
}

void test_assert();

int main(int argc, char** argv)
{
    LOG("test SmartAssert");
	
    return 0;
}

void test_assert()
{
	string str("this");
	SMART_ASSERT(str.empty())(str);
}