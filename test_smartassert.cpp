#include <iostream>
#include <string>
#include "log.hpp"
#include "SmartAssert.hpp"

using namespace std;

int main(int argc, char** argv)
{
    LOG_R_D("test SmartAssert");
	string str("this");
	SMART_ASSERT(str.empty())(str);
    return 0;
}