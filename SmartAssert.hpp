#pragma once

#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <typeinfo>
#include <sstream>

using namespace std;

std::string demangle(const std::string& name);


class Assert
{
	std::string m_expr;
public:
	explicit Assert(const char* expr) : m_expr(expr), SMART_ASSERT_A(*this), SMART_ASSERT_B(*this)
	{
	}
	Assert& SMART_ASSERT_A;
	Assert& SMART_ASSERT_B;
	//whatever member functions
	template<typename T>
	Assert& print_current_val(const char* name, const T& value)
	{
		cout << "\t" << demangle(typeid(T).name()) << " " << name << " = " << value << endl;
		return *this;
	}
	Assert& print_context(const char* file, const int line)
	{
		cout << "Assertion failed in " << "[" << file << " : " << line << "]" << endl;
		cout << "Expr : '" << expr() << "'" << endl;
		cout << "Vals : " << endl;
		return *this;
	}
	const std::string& expr()const
	{
		return m_expr;
	}
};

Assert make_assert(const char* expr);

/*
如何理解这个技巧：当预处理器看到SMART_ASSERT_A(或_B)后面跟着一对括号时，它就将
这个当成对宏的调用来对待。如果没有括号，预处理器就简单地将这个符号仍然留在那里。而
在后一种情况下，符号SMART_ASSERT_A(或_B)只是代表成员变量。
*/
#define SMART_ASSERT_OP(x, next)\
    SMART_ASSERT_A.print_current_val(#x, (x)).SMART_ASSERT_##next

#define SMART_ASSERT_A(x) SMART_ASSERT_OP(x, B)
#define SMART_ASSERT_B(x) SMART_ASSERT_OP(x, A)

#define SMART_ASSERT( expr ) \
    if( (expr) ) ;\
    else make_assert(#expr).print_context(__FILE__, __LINE__).SMART_ASSERT_A


