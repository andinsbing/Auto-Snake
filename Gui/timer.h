#pragma once
#include<functional>
#include<thread>
#include<utility> 
#include<mutex>
#include<type_traits>

// trick for decltype
#define NULL_VALUE_OF_TYPE(TYPE) ( (TYPE) ( * (typename std::remove_reference<TYPE>::type * ) 0  )  )

template<class FnPointer>
struct FunctionTraits
{
	template<class R, class... Arg>
	static R resultTypeHelper(R(*)(Arg...)) = delete;
	using RetType = decltype(resultTypeHelper(NULL_VALUE_OF_TYPE(FnPointer)));
};

template<class FnPointer>
using FunctionRet_t = typename FunctionTraits<FnPointer>::RetType;

template<class FnPointer, class... Arg>
class Timer
{
public:
	enum State
	{
		ready,
		running,
		paused,
		destroyed
	};
public:
	Timer(int millisecond, FnPointer fun, Arg... arg) :
		_interval(millisecond),
		_state(ready),
		_bind(std::bind(fun, std::forward<Arg>(arg)...)),
		_thread(std::bind(&Timer<FnPointer, Arg...>::caller, this))
	{
	}
	Timer(const Timer&) = delete;
	Timer(Timer&&) = delete;
	~Timer()
	{
		finish();
		_thread.join();
	}
	void run()
	{
		setState(running);
	}
	//puase event loop immediately after the latest event finished
	void pause()
	{
		setState(paused);
	}
	//break event loop
	void finish()
	{
		setState(destroyed);
	}
	State state()const
	{
		return this->_state;
	}
private:
	void caller()
	{
		while (true)
		{
			std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(_interval));
			switch (_state)
			{
			case ready:
			case paused:
				std::this_thread::yield();
				break;
			case running:
				_loopSafeMutex.lock();
				_bind();
				_loopSafeMutex.unlock();
				break;
			case destroyed:
				return;//quit event loop
			default:
				break;
			}
		}
	}
	//event loop safe
	void setState(State state)
	{
		_loopSafeMutex.lock();
		_state = state;
		_loopSafeMutex.unlock();
	}
	const int _interval;
	State _state;
	decltype(std::bind(NULL_VALUE_OF_TYPE(FnPointer), std::forward<Arg>(NULL_VALUE_OF_TYPE(Arg))...)) _bind;
	std::thread _thread;
	std::mutex _loopSafeMutex;
};

#undef NULL_VALUE_OF_TYPE
