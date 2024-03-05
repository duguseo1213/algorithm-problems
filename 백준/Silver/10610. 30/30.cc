#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dat[10];
int tempdat[10];

string temp;
int main()
{
	cin >> temp;
	string answer = "";
	for (int i = 0; i < temp.size(); i++)
	{
		dat[temp[i] - '0']++;
	}

	int sum = 0;

	for (int i = 1; i < 10; i++)
	{
		sum += dat[i] * i;
	}

	

	if (dat[0] == 0 || sum % 3!=0) cout << -1; //0없으면 마이너스 출력
	else
	{
		
		for (int j = 9; j >= 0; j--)
		{
			for (int k = 0; k < dat[j]; k++)
			{
				answer += to_string(j);
			}
		}
			
		

		cout << answer;
	}
	//state 1이면 마이너스 출력
	
}