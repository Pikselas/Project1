#include<iostream>
#include"ks_Watch.h"
#include"ks_InpChecker.h"
int main()
{
	ks_Watch kw;
	ks_InpChecker kin ( kw );
	kin.Start();
	while (true)
	{
		std::cout << kw.GetTimeString();
		system("cls");
	}
	return 0;
 }