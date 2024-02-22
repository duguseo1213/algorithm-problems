#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int arr[500001];

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

bool setunion(int a, int b)
{
    int t1 = find(a);
    int t2 = find(b);

    if (t1 == t2) return 0;

    arr[t2] = t1;
    return 1;

}





int main() 
{
    
    int N, M;
    cin >> N >> M;

    for (int i = 0; i <= 500000; i++)
    {
        arr[i] = i;
    }
    int a, b;
    int state = 0;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        if (setunion(a, b))
        {

        }
        else
        {
            state = 1;
            cout << i + 1;
            break;
        }
    
    }
    if (state == 0)
    {
        cout << 0;
    }


}