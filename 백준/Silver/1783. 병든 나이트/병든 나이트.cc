#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main()
{
	cin >> N >> M;

	if (N == 1 || M == 1)
	{
		cout << 1;
	}

	else if (N==2)
	{
		if (M < 3)
		{
			cout << 1;
		}
		else if(M>=7)
		{
			cout << 4;
		}
		else if (M >= 5)
		{
			cout << 3;
		}
		else if (M >= 3)
		{
			cout << 2;
		}
	}

	else if ( M>=7)
	{
		cout << 5 + M -7;
		
	}
	else if (M==2)
	{
		cout << 2;
	}
	else if (M >=3 && M<4)
	{
		cout << 3;
	}
	else if (M>=4 && M<=6)
	{
		cout << 4;
	}

}