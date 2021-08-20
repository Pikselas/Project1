#pragma once
#include<conio.h>
#include"ks_Watch.h"
class ks_InpChecker
{
private:
	enum tps
	{
		StartClock = 119,  //w
		ResetClock = 115, //s
		PauseClock = 101,//e 
		ResumeClock = 97,//a
		StopClock = 113 // q
	};
private:
	ks_Watch& watch;
	bool IsAlive;
public:
	ks_InpChecker(ks_Watch& wtc);
	~ks_InpChecker();
	void Start();
	void Stop();
public:
	int GetInput() const noexcept;
	void PerformAction(unsigned int code) const noexcept;
};