#pragma once

//#define THREAD_TEST

/*

*/
#include <iostream>
#include <thread>

class CThread
{
private:
	std::thread  m_thread;
	bool is_stopped;
public:
	CThread():is_stopped(false) { }
	virtual ~CThread();
	const char* name()const { return typeid(*this).name(); }
	//
	int start()
	{
#ifdef THREAD_TEST
		cout << "CThread::start a1: " << m_thread.get_id() << endl;
		this_thread::sleep_for(std::chrono::seconds(2));
		cout << "CThread::start a2: " << this_thread::get_id() << endl;
#endif
		std::thread tmp{ CThread::run, this };
		m_thread = move(tmp);
#ifdef THREAD_TEST
		this_thread::sleep_for(std::chrono::seconds(2));
		cout << "CThread::start b3: " << m_thread.get_id() << endl;
		this_thread::sleep_for(std::chrono::seconds(2));
		cout << "CThread::start b4: " << this_thread::get_id() << endl;
#endif
		return 0;
	}
	void stop()
	{
		is_stopped = true;
	}

	bool is_stop()
	{
		return is_stopped;
	}

	int detach()
	{
		m_thread.detach();
		return 0;
	}
	int join()
	{
		if (m_thread.joinable())
		{
			m_thread.join();
		}		
		return 0;
	}

	std::thread::id get_id()const
	{
		if (m_thread.get_id() != std::thread::id{})
		{
			return m_thread.get_id();
		}
		else
		{
			return std::this_thread::get_id();
		}
	}

	void sleep_for(int sec)
	{
		std::this_thread::sleep_for(std::chrono::seconds(sec));
	}

	//�������ظ÷�����ʵ���Լ�������
#ifndef THREAD_TEST
	virtual int work() = 0;
#else
	virtual int work()
	{
		this_thread::sleep_for(std::chrono::seconds(8));
		cout << "CThread::work : " << get_id() << endl;
		this_thread::sleep_for(std::chrono::seconds(2));
		cout << "CThread::work : " << this_thread::get_id() << endl;
		this_thread::sleep_for(std::chrono::seconds(2));
		return 0;
	}
#endif
	static int run(void* ptr)
	{
		CThread* self = (CThread*)ptr;		
		return self->work();
	}

};

