#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, r, c;


int cnt = 0;
int state = 0;
void func(int y,int x,int size)
{
	if (size == 2)
	{
		
		if (y == r && x == c)
		{
			cnt++;
			state = 1;
			return;
		}
		
		else if (y == r && x+1 == c)
		{
			cnt = cnt + 2;
			state = 1;
			return;
		}
		else if (y+1 == r && x == c)
		{
			cnt = cnt + 3;
			state = 1;
			return;
		}
		else if (y+1 == r && x+1 == c)
		{
			cnt = cnt + 4;
			state = 1;
			return;
		}
		cnt = cnt + 4;
		return;
	}
	if (y <= r && r < y + size)
	{

		func(y, x, size / 2);
		if (state == 1) return;
		func(y, x + size / 2, size / 2);
		if (state == 1) return;

		func(y + size / 2, x, size / 2);
		if (state == 1) return;
		func(y + size / 2, x + size / 2, size / 2);
		if (state == 1) return;
	}
	else
	{
		cnt = cnt + size * size / 2;
		func(y + size / 2, x, size / 2);
		if (state == 1) return;
		func(y + size / 2, x + size / 2, size / 2);
		if (state == 1) return;
	}

	

}


int main()
{
	cin >> N >> r >> c;

	

	func(0, 0, pow(2, N));
	cout << cnt-1;
}