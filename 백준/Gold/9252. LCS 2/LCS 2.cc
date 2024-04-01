#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int arr[1001][1001];

pair<int, int> dp[1001][1001];

//char answer[1001] = { 0 };
string a;
string b;

int main()
{
	cin >> a >> b;
	int state = 0;
	if (a[0] == b[0])
	{
		arr[0][0] = 1;

	}
	
	for (int i = 1; i < a.length(); i++)
	{
		if (a[i] == b[0] )
		{
			arr[0][i] = 1;
			dp[0][i] = { 0,i };
		}
		else
		{
			arr[0][i] = arr[0][i-1];
			dp[0][i] = dp[0][i-1];


		}

	}

	for (int i = 1; i < b.length(); i++)
	{
		if (b[i] == a[0] )
		{
			arr[i][0] = 1;
			dp[i][0] = { i,0 };
		}
		else
		{
			arr[i][0] = arr[i - 1][0];
			dp[i][0] = dp[i-1][0];

		}

	}
	
	for (int i = 1; i < b.length(); i++)
	{

		for (int j = 1; j < a.length(); j++)
		{
			if (b[i] == a[j])
			{
				arr[i][j] =arr[i-1][j-1]+ 1;
				dp[i][j] = { i,j };
			}
			else
			{
				if (arr[i][j - 1] > arr[i - 1][j])
				{
					arr[i][j] = arr[i][j - 1];
					dp[i][j] = dp[i][j-1];
				}
				else
				{
					arr[i][j] = arr[i-1][j];
					dp[i][j] = dp[i -1][j];

				}

			}

		}
	}
	int maxx = 0;

	int y, x;
	string answer="";
	for (int i = 0; i < b.length(); i++)
	{
		for (int j = 0; j < a.length(); j++)
		{
			if (arr[i][j] > maxx)
			{
				maxx = arr[i][j];
				y = i;
				x = j;
				//answer = str[i][j];
			}
			//cout << str[i][j]<<" ";
			//printf("%d ", arr[i][j]);
		}
		//printf("\n");
		//cout << endl;
		//printf("\n");
	}
	//printf("%c\n", b[y]);

	
	int cnt = 0;

	if (maxx == 0)
	{
		cout << maxx;
		return 0;
	}

	while (1)
	{
		answer+=b[y];
		if (y <= 0 || x <= 0) break;
		int q = dp[y-1][x-1].first;
		int w= dp[y-1][x-1].second;
		y = q;
		x = w;
		
		cnt++;
		if (cnt == maxx) break;
	}
	cout << maxx << "\n";
	for (int i = answer.length()-1; i >=0; i--)
	{
		cout << answer[i];
	}




}



















