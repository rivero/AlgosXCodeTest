
/*************************************************************************
Implement a simple thread pool in C++ that can manage and execute a few tasks concurrently. 
The thread pool should have the following features:

-Initialization: Initialize the thread pool with a specified number of threads.

-Task Submission: Allow tasks to be submitted to the pool.

-Execution: Ensure that the submitted tasks are executed by the threads in the pool.

-Shutdown: Provide a way to gracefully shutdown the thread pool, ensuring all pending tasks are completed before the program exits.

****************************************************************************/

// VERSION WITH RAII-mechanism (lock_guard: proecessResourceLock()) AND NON-BLOCKING LOCK proecessResourceTry()
// Also added option join or detach.

#if 0

#include <iostream>
#include <atomic>
#include <chrono>
#include <thread>
#include <functional>
#include <mutex>

using namespace std;

atomic<bool> g_globalExecFlag = true;
mutex g_mutex;
atomic<int> g_counter{ 0 };

struct ThreadPool
{
	ThreadPool(int nt = 10) : num_threads(nt){}
	void startPool()
	{
		addTasks(num_threads);
	}
	void stopPool() const
	{
		g_globalExecFlag = false;
	}
	void addTasks(size_t n, bool joinDetach = false /*false is detach*/)
	{
		std::function<void()> func = []() {executableThread;};

		for (int i = 0; i < n; i++)
		{
			addTask(func, joinDetach);
		}
	}
	void addTask(const function<void()>& f, bool joinDetach = false /*false is detach*/)
	{
		thread t1(f);
		if (joinDetach)
			t1.join();
		else
			t1.detach();
	}
	~ThreadPool()
	{
		g_globalExecFlag = false;
	}
private:
	void processResourceLock()
	{
		lock_guard<mutex> guard(g_mutex);
		// Do something here that requires synchronization and/or resource sharing
		g_counter++;
	}
	void processResourceTry()
	{
		static int my_counter;
		while (g_globalExecFlag)
		{
			if (g_mutex.try_lock())
			{
				g_counter++;
				g_mutex.unlock();
				return;
			}
			else
			{
				++my_counter;
				this_thread::sleep_for(chrono::milliseconds(50));
			}

		}
	}
	void executableThread()
	{
		while (g_globalExecFlag)
		{
			processResourceLock();
			processResourceTry();
			this_thread::sleep_for(chrono::seconds(1));
		}
		cout << "thread finished\n";
	}
	int num_threads{};
};



int main() 
{
	ThreadPool tp;
	tp.startPool();
	tp.addTasks(1);
	this_thread::sleep_for(chrono::seconds(60));

	tp.stopPool();
	return 0;
}

#endif
