#include <iostream>

using namespace std;

int visit[10];
int arr[10][10];
long minn=100000000;
int N;
int c[10];



void func(int num,int sum,int dep,int start)
{
    

    
    if (dep == N-1)
    {
        if (arr[num][start] != 0)
            sum = sum + arr[num][start];
        else return;
        if (sum < minn)
        {
            
            minn = sum;
        }
        /*for (int i = 0; i < N; i++)
        {
            cout << c[i]<<" ";
        }*/
        
    }
    dep += 1;
    for (int i = 0; i < N; i++)
    {
        if (visit[i] == 0 && num != i && arr[num][i]!=0)
        {
            visit[i] = 1;
            c[dep-1] = arr[num][i];
            func(i,sum + arr[num][i],dep,start);
            visit[i] = 0;
        }
        
    }

    

}

int main()
{
    
    cin >> N;
    int dep = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        visit[i] = 1;
        func(i, 0,0,i);
        visit[i] = 0;
    }

    printf("%ld", minn);
}