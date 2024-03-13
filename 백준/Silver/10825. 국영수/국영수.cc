#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

struct Student {
	int language;
	int english;
	int math;
	string name;
};

Student heap[100010];
int hn;

bool cmp(Student a, Student b)
{
	if (a.language == b.language)
	{
		if (a.english == b.english)
		{
			if (a.math == b.math)
			{
				return a.name > b.name;
			}
			return a.math < b.math;
		}

		return a.english > b.english;

	}

	return a.language < b.language; //뒤에께 우선순위 크면 true 반환
}

void push(Student a)
{
	hn++;

	heap[hn] = a;
	Student temp;

	for (int i = hn; i > 1; i = i / 2)
	{
		if (cmp(heap[i], heap[i / 2])) break;

		temp = heap[i];
		heap[i] = heap[i / 2];
		heap[i / 2] = temp;
		


	}


}


Student pop()
{
	Student worst;
	worst.language = -10000;

	Student ret = heap[1];
	heap[1] = heap[hn];
	heap[hn] = worst;

	hn--;

	Student temp;
	for (int i = 1; i * 2 <= hn;)
	{
		if (!cmp(heap[i], heap[i * 2]) && !cmp(heap[i], heap[i * 2 + 1]))
		{
			break;
		}
		else if (cmp(heap[i * 2+1], heap[i * 2]))
		{
			temp = heap[i * 2];
			heap[i * 2] = heap[i];
			heap[i] = temp;

			i = i * 2;
		}
		else
		{
			temp = heap[i * 2+1];
			heap[i * 2+1] = heap[i];
			heap[i] = temp;

			i = i * 2+1;
		}
	}

	return ret;





}




int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string temp;
		Student s;
		cin >> s.name;
		cin >> s.language >> s.english >> s.math;


		push(s);

	}

	for (int i = 0; i < N; i++)
	{
		cout << pop().name << "\n";
	}
	
}