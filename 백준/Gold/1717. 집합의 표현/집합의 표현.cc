#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int arr[1000001];

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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        arr[i] = i;
    }
    int t, a, b;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &t, &a, &b);

        if (t == 0)
        {
            setunion(a, b);
        }
        else
        {
            if (find(a) == find(b))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }

    }


}