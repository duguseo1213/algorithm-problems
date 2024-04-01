#define _CRT_SECURE_NO_WARNINGS
#define P 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int fail[1000001];
string a, b;
int cnt = 0;

int alen, blen;
vector<int> answer;
void find_fail()
{
	fail[0] = -1;



	for (int i = 1; i < blen; i++)
	{
		int j = fail[i - 1];

		while (1)
		{
			if (j == -1)
			{
				break;
			}


			if (b[j+1]==b[i])
			{
				break;
			}

			j = fail[j];

		}

		if (b[j + 1] == b[i])
		{
			fail[i] = j+1;
		}
		else
		{
			fail[i] = -1;
		}



	}
	for (int i = 0; i < b.length(); i++)
	{
		P("%d ", fail[i]);
	}
	P("\n");

}

void kmp()
{
	int i = 0;
	int j = 0;

	while (i < alen)
	{
		while (j < blen && i< alen)
		{

			if (a[i] == b[j])
			{
				i++;
				j++;
			}
			else if (j == 0)
			{
				i++;
			}
			else
			{
				j = fail[j - 1] + 1;

			}

		}
		//if (i >= alen) break;


		if (j == blen)
		{
			cnt++;

			answer.push_back(i - blen + 1);
			j = fail[j - 1] + 1;
			
			

		}
		


	}


}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	getline(cin,a);
	
	getline(cin, b);
	alen = a.length();
	blen = b.length();
	
	find_fail();

	kmp();
	

	cout << cnt<<"\n";

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	
}