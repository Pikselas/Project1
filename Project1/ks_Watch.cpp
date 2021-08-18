#include "ks_Watch.h"
ks_Watch::ks_Watch()
{
	IsActive = false;
	IsStandBy = false;
	Elapsed = 0.0;
}
ks_Watch::~ks_Watch()
{
 
}
void ks_Watch::Start()
{
	std::lock_guard<std::mutex> guard(mtx);
	IsActive = true;
	IsStandBy = false;
	Elapsed = 0.0;
	timeP = std::chrono::steady_clock::now();
}
double ks_Watch::Count() const noexcept
{
	std::chrono::duration<double> dCounter;
	if (!IsStandBy)
	{
		dCounter = std::chrono::steady_clock::now() - timeP;
	}
	else
	{
		dCounter = StandBytm - timeP;
	}
	return dCounter.count() - Elapsed;
}
ks_Watch::tm ks_Watch::GetTime() const noexcept
{
	tm t;
	t.h = t.m = t.s = t.ms = 0;
	if (IsActive)
	{
		double timeINs = Count();
		t.s = static_cast<int>(timeINs);
		t.ms = (timeINs - t.s) * 100;
		if (t.s >= 60)
		{
			t.m = t.s / 60;
			t.s = t.s % 60;
		}
		if (t.m >= 60)
		{
			t.h = t.m / 60;
			t.m = t.m % 60;
		}
	}
	return t;
}
std::string ks_Watch::GetTimeString() const noexcept
{
	std::stringstream tmS;
	tm t = GetTime();
	tmS << t.h << ":" << t.m << ":" << t.s << ":" << t.ms;
	return tmS.str();
}
void ks_Watch::Pause()
{
	std::lock_guard<std::mutex> guard(mtx);
	if (!IsStandBy)
	{
		StandBytm = std::chrono::steady_clock::now();
		IsStandBy = true;
	}
}
void ks_Watch::Resume()
{
	std::lock_guard<std::mutex> guard(mtx);
	if (IsStandBy)
	{
		std::chrono::duration<double> dCounter = std::chrono::steady_clock::now() - StandBytm;
		IsStandBy = false;
		Elapsed += dCounter.count();
	}
}
void ks_Watch::Stop()
{
	std::lock_guard<std::mutex> guard(mtx);
	IsActive = false;
	IsStandBy = false;
	Elapsed = 0.0;
}