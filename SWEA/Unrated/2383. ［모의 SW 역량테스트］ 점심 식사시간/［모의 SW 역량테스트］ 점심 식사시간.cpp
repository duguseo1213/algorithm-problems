#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

struct person {
    int y;
    int x;
    int arrivetime;
};

int s1y;
int s1x;
int s1size;

int s2y;
int s2x;
int s2size;


vector<person> p;

vector<int> a; //1번계단
vector<int> b; //2번계단

int map_[10][10];

int visit[10];
int maxx = 987654321;
void ff()
{

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int tempa[10];
    int tempb[10];
    
    int tempmax = 0;

    for (int i = 0; i < a.size(); i++)
    {
        tempa[i] = a[i];
    }
    for (int i = 0; i < b.size(); i++)
    {
        tempb[i] = b[i];
    }
    if (a.size() == 0)
    {

    }
    else if (a.size() <= 3)
    {
        tempmax = max(tempmax, a[a.size()-1]+s1size);
    }
    else
    {
        int i = 0;
        while (1)
        {
            if (i + 3 == a.size()) break;

            if (a[i + 3] - a[i] < s1size)
            {
                a[i + 3] = a[i]+ s1size;
            }
            i++;
        }

        tempmax = max(tempmax, a[a.size()-1]+ s1size);
        
    }
    //printf("%d\n", tempmax);
    if (b.size() == 0)
    {

    }
    else if (b.size() <= 3)
    {
        tempmax = max(tempmax, b[b.size() - 1] + s2size);
    }
    else
    {
        int i = 0;
        while (1)
        {
            if (i + 3 == b.size()) break;

            if (b[i + 3] - b[i] < s2size)
            {
                b[i + 3] = b[i] + s2size;
            }
            i++;
        }

        tempmax = max(tempmax, b[b.size() - 1] + s2size);
    }
   // printf("%d\n", tempmax);
    maxx = min(tempmax, maxx);
}


void func(int dep, int s)
{
    if (dep == p.size())
    {
        //calculate
        a.clear();
        b.clear();
        for (int i = 0; i < p.size(); i++)
        {
            if (visit[i] == 0)
            {
                
                int q = abs(p[i].y - s1y) + abs(p[i].x - s1x)+1;
                a.push_back(q);
            }
            else
            {
                int q = abs(p[i].y - s2y) + abs(p[i].x - s2x)+1;
                b.push_back(q);
            }

            //printf("%d ", visit[i]);
        }
        ff();
        //printf("\n");
        return;
    }


    func(dep + 1, 0);
    visit[dep] = 1;
    func(dep + 1, 0);
    visit[dep] = 0;


}


int main()
{
    //freopen("sample_input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        
        p.clear();
        int N;
        maxx = 987654321;
        cin >> N;
        s1x = -1;
        s1y = -1;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &map_[i][j]);

                if (map_[i][j] == 1)
                {
                    p.push_back({ i,j,0, });
                }
                else if (map_[i][j] > 1)
                {
                    if (s1x == -1 && s1y == -1)
                    {
                        s1x = j;
                        s1y = i;
                        s1size = map_[i][j];
                    }
                    else
                    {
                        s2x = j;
                        s2y = i;
                        s2size = map_[i][j];
                    }

                }
            }
        }


        func(0, 0);

        printf("#%d %d\n", t, maxx);
    }
}