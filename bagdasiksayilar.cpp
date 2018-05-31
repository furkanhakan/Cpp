// bagdasiksayi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int tbolen1=0,tbolen2=0,bagdasik=0;
	for (int i = 1; i < 10000; i++)
	{
		tbolen1=0;
		tbolen2=0;
		for (int j = 1; j < i; j++)
		{
			if (i%j==0)
			{
				tbolen1+=j;
			}
		}
		if (tbolen1==i)
		{

		}
		else
		{
			for (int k = 1; k < tbolen1; k++)
			{
				if (tbolen1%k==0)
				{
					tbolen2+=k;
				}
			}
			if (tbolen2==i)
			{
				bagdasik+=tbolen1;
			}
		}
	}
	cout<<bagdasik;
	return 0;
}

