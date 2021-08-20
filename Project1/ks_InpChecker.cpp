#include"ks_InpChecker.h"
ks_InpChecker::ks_InpChecker(ks_Watch& wtc) : watch(wtc),IsAlive(false) {}
ks_InpChecker::~ks_InpChecker()
{
	
}
int ks_InpChecker::GetInput() const noexcept
{
	return _getch();
}
void ks_InpChecker::PerformAction(unsigned int code) const noexcept
{
	switch (code)
	{
	case tps::StartClock:
		watch.Start();
		break;
	case tps::ResetClock:
		watch.Start();
		break;
	case tps::StopClock:
		watch.Stop();
		break;
	case tps::PauseClock:
		watch.Pause();
		break;
	case tps::ResumeClock:
		watch.Resume();
		break;
	}
}
void ks_InpChecker::Start()
{
	IsAlive = true;
	std::thread([this] {
		while (IsAlive)
		{
			PerformAction(GetInput());
		}
		}).detach();
}

void ks_InpChecker::Stop()
{
	IsAlive = false;
}
