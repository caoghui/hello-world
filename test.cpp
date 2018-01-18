
#include <iostream>
#include "log.hpp"
using namespace std;

int main(int argc, char** argv)
{
    LOG("Hello World!");
    LOG_R("Log_R print!");
    cout <<__FILE__<<endl;
    cout << __FUNCTION__<<endl;
}

