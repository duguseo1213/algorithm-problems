#define _CRT_SECURE_NO_WARNINGS
#define P 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_set>
using namespace std;

string a, b;

int fail[1000000];
vector<int> answer;
int cnt;
void find_fail()
{
	fail[0] = -1;
	for (int i = 1; i < b.size(); i++){
		int j = fail[i - 1];
		while (1)
		{
			if (j == -1){
				break;
			}
			if (b[i] == b[j + 1]){
				break;
			}
			j = fail[j];
		}
		if (b[j + 1] == b[i]){
			fail[i] = j + 1;
		}
		else{
			fail[i] = -1;
		}
	}
}


void kmp()
{
	int i = 0;
	int j = 0;
	while (i < a.size())
	{

		while (j < b.size() && i < a.size())
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
		if (j == b.size())
		{
			cnt++;
			answer.push_back(i - b.size() + 1);
			j = fail[j - 1] + 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	getline(cin, a);
	getline(cin, b);
	find_fail();

	kmp();


	cout << cnt << "\n";

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}

}
