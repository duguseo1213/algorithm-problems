#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <cstring>
#include <queue>
using namespace std;

int N;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int visit[50][50];
int map_[50][50];
int L, R;

queue<pair<int,int>> q;
int sum;
int color;
int cnt;
void bfs(int y, int x)
{
    sum = map_[y][x];
    cnt = 1;
    visit[y][x] = color;
    q.push({ y,x });

    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny<0 || nx<0 || ny>N - 1 || nx>N - 1) continue;

            if (visit[ny][nx] != 0) continue;

            if (abs(map_[ny][nx] - map_[y][x]) >= L && abs(map_[ny][nx] - map_[y][x]) <= R)
            {
                cnt++;
                sum += map_[ny][nx];
                q.push({ ny,nx });
                visit[ny][nx] = color;

            }



        }
    }


    //cout << cnt << sum<<endl;

}

void move(int y, int x)
{
    int tempvisit[50][50] = { 0, };

    tempvisit[y][x]=1;
    q.push({ y,x });

    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        map_[y][x] = sum / cnt;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny<0 || nx<0 || ny>N - 1 || nx>N - 1) continue;

            if (visit[ny][nx] == color && tempvisit[ny][nx]==0)
            {
                tempvisit[ny][nx] = 1;
                q.push({ ny,nx });
            }

        }
    }
}


int main()
{
    cin >> N;
    cin >> L >> R;
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map_[i][j];
        }
    }
    while (1)
    {
        answer++;
        color = 1;

        
        memset(visit, 0, sizeof(visit));


        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visit[i][j] == 0)
                {
                    bfs(i, j);
                    move(i, j);
                    color++;

                }
            }
        }
        /*
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d ", visit[i][j]);
            }
            printf("\n");
        }

        printf("\n");
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d ", map_[i][j]);
            }
            printf("\n");
        }*/

        if (color == 1 + N * N) break;

    }
    cout << answer-1;
}