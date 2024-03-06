#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string a,b;

int main()
{
	cin >> a;

	cin >> b;

	int i=0;
	int j = b.size();
	int state = 0; //안뒤집

	

	while (1)
	{
		//printf("%d %d\n", i, j);
		if (j - i == a.size())
		{
			break;
			
		}
		if (state == 0)
		{
			if (b[j - 1] == 'A')
			{
				j--;
				state = 0;
				
			}
			else if (b[j - 1] == 'B')
			{
				j--;
				state = 1;
				
			}
		}
		else
		{
			if (b[i] == 'A')
			{
				i++;
				state = 1;

			}
			else if (b[i] == 'B')
			{
				i++;
				state = 0;

			}

		}
		

	}
	//printf("%d %d\n", i, j);
	int flag = 0;
	//cout << state;
	if (state == 0)
	{
		for (int k = i; k < j; k++)
		{
			if (b[k] != a[k - i])
			{
				flag = 1;
				break;
			}
		}
	}
	else
	{
		for (int k = i; k < j; k++)
		{
			if (b[j-k-1+i] != a[k - i])
			{
				flag = 1;
				break;
			}
		}
	}




	if (flag == 1)
	{
		cout << 0;
	}
	else
	{
		cout << 1;
	}
	
}