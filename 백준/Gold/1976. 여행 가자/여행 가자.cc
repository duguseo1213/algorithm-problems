#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int arr[1000001];

int graph[201][201];

int find(int tar)
{
    if (tar == arr[tar])
    {
        return tar;
    }

    int root = find(arr[tar]);

    arr[tar] = root;

    return root;

}

void setunion(int a,int b)
{
    int t1 = find(a);
    int t2 = find(b);

    if (t1 == t2) return;

    arr[t2] = t1;

}


int main()
{
    for (int i = 0; i < 300; i++)
    {
        arr[i] = i;
    }

    int N;
    cin >> N;
    int M;
    cin >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j++)
        {
            if (graph[i][j] == 1)
            {
                setunion(i, j);
            }
        }
    }
    int q;
    cin >> q;
    int temp = find(q);
    int flag = 0;
    
    for (int i = 1; i < M; i++)
    {
        cin >> q;
        if (temp != find(q))
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

}