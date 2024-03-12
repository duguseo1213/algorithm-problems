#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

map<string, int> m;


int M;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> M;
	string order;
	unsigned int a=0;
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> order;
		if (order == "add")
		{
			cin >> num;
			num--;
			if (!((1 << num) & a))
			{
				a = a + (1 << num);
			}

		}
		else if (order == "check")
		{
			cin >> num;
			num--;
			if (((1 << num) & a))
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0<< "\n";
			}
		}
		else if (order == "remove")
		{
			cin >> num;
			num--;
			if (((1 << num) & a))
			{
				a = a - (1 << num);
			}
		}
		else if (order == "toggle")
		{
			cin >> num;
			num--;
			if (((1 << num) & a))
			{
				a = a - (1 << num);
			}
			else
			{
				a = a + (1 << num);
			}
		}
		else if (order == "all")
		{
			a=(1 << 20)-1;
			
			
		}
		else if(order=="empty")// empty
		{
			a = 0;
		}


	}

}