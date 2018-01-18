
#include <iostream>
#include "log.hpp"
#include "ScopeGuard.hpp"
using namespace std;

int main(int argc, char** argv)
{
    LOG_R_D("test ScopeGuard");
	ON_SCOPE_EXIT([]() { cout << "the scope exit call" << endl; });
    return 0;
}