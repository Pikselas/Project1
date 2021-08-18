#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<functional>
#include"ks_Watch.h"
int main()
{
	ks_Watch kw;
	kw.Start();
	while (true)
	{
		std::cout << kw.GetTimeString();
		system("cls");
	}
	return 0;
 }