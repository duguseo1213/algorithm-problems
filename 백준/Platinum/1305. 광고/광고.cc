
#define P  
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int fail[1000001];

int alen;
string a;
int maxx = -2;

void find_fail()
{

	fail[0] = -1;

	for (int i = 1; i < alen; i++)
	{
		int j = fail[i - 1];

		while (1)
		{
			
			if (j == -1 || a[j + 1] == a[i]) break;

			j = fail[j];

		}

		if (a[j + 1] == a[i])
		{
			fail[i] = j + 1;

		}
		else
		{
			fail[i] = -1;
		}
	}
	for (int i = 0; i < alen; i++)
	{
		P("%d ", fail[i]);
		maxx = max(maxx, fail[i]);
	}
	P("\n");
	
}


int main()
{
	int q;
	cin >> q;

	cin >> a;

	alen = a.length();
	find_fail();

	cout << alen - fail[alen-1]-1;

}