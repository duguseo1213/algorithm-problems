#include <string>
#include <vector>
#include <queue>
using namespace std;
long long hn = 0;
long long heap[1000001];

bool cmp(long long a,long long b)
{
	return a > b;
}

priority_queue<int,vector<int>,greater<int>> pq;

void push(long long value)
{
	hn++;
	heap[hn] = value;

	for (int i = hn; i > 1 ; i = i / 2)
	{
		if (cmp(heap[i], heap[i / 2])) break;
		long long temp;
		temp = heap[i];
		heap[i] = heap[1 / 2];
		heap[1 / 2] = temp;
	}

}

long long pop()
{
	long long ret=heap[1];
	heap[1] = heap[hn];
	heap[hn] = 999999999;
	hn--;
	long long temp;
	for (int i = 1; i * 2 <= hn;)
	{
		if (!cmp(heap[i], heap[i * 2]) && !cmp(heap[i], heap[i * 2 + 1]))
		{
			break;
		}

		if (cmp(heap[i * 2], heap[i * 2 + 1]))
		{

			temp = heap[i * 2 + 1];
			heap[i * 2 + 1] = heap[i];
			heap[i] = temp;
			
			i = i * 2+1;

		}
		else
		{
			temp = heap[i * 2 ];
			heap[i * 2 ] = heap[i];
			heap[i] = temp;

			i = i * 2;
		}
	}

	return ret;


}

int solution(vector<int> scoville, int K) 
{
    for(int i=0;i<scoville.size();i++)
    {
        pq.push(scoville[i]);
    }
    int cnt=0;
    
    while(1)
    {
        if(pq.top()>=K) break;
        long long a;
        long long b;
        if(pq.size()==1) return -1;
        
        a=pq.top();
        pq.pop();
        b=pq.top();
        pq.pop();
        pq.push(a+b*2);
        cnt++;
        
    }
    
    return cnt;
    
}