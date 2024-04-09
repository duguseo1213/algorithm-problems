#define _CRT_SECURE_NO_WARNINGS
#define P printf

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

string a;
string b;

int stack[1000100];
int top = -1;

bool cmp()
{
	int state = 0;
	for (int i = 0; i < b.length(); i++)
	{
		
		if (stack[top + 1 - b.length() + i] != b[i])
		{
			return 0;
		}
	}
	
	return 1;
}

int main()
{
	cin >> a >> b;	

	for (int i = 0; i < a.length(); i++)
	{
		top++;
		stack[top] = a[i];
		
		if (top+1 >= b.length())
		{
			if (cmp())
			{
				
				top -= b.length();

			}

		}
		
	}

	if (top == -1)
	{
		printf("FRULA");
	}
	else
	{
		for (int i = 0; i <= top; i++)
		{
			printf("%c", stack[i]);
		}
	}


}