#pragma once
#include<thread>
#include<chrono>
#include<sstream>
#include<mutex>
class ks_Watch
{
private:
	struct tm
	{
		long int h;
		long int m;
		long int s;
		long int ms;
	};
private:
	std::chrono::steady_clock::time_point timeP;
	std::chrono::steady_clock::time_point StandBytm;
	mutable std::mutex mtx;
	bool IsActive;
	bool IsStandBy;
	long double Elapsed;
private:
	tm GetTime() const noexcept;
public:
	ks_Watch();
	~ks_Watch();
	void Start();
	double Count() const noexcept;
	std::string GetTimeString() const noexcept;
	void Pause();
	void Resume();
	void Stop();
};