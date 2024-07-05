#define _CRT_SECURE_NO_WARNINGS
#define P printf
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;

int N,M;

int arr[1001];
int visit[1001];

int find(int tar) {

    if (tar == arr[tar]) {
        return arr[tar];
    }
    int root = find(arr[tar]);
    arr[tar] = root;
    return root;

}

void setunion(int a,int b) {
    int t1 = find(a);
    int t2 = find(b);


    if (t1 == t2) {
        return;
    }

    arr[t2] = t1;

}

vector<pair<int, int>> graph[1001];

void dfs(int depth, int v,int fre,int start) {

    if (fre == 0 && depth != 0) {
        setunion(start, v);
    }

    for (int i = 0; i < graph[v].size(); i++) {

        if (visit[graph[v][i].first] == 0) {
            visit[graph[v][i].first] = 1;
            if (fre==0 && graph[v][i].second == 0) {
                dfs(depth + 1, graph[v][i].first, fre, start);
            }
            else if(fre==1 && graph[v][i].second == 0) {
                
            }
            else
            {
                dfs(depth + 1, graph[v][i].first, (fre + 1) % 2, start);
            }

        }

    }

}

int main(){
    for (int i = 1; i <= 1000; i++) {
        arr[i] = i;
    }
    scanf("%d", &N);
    scanf("%d", &M);
    char a;
    int b, c;
    for (int i = 0; i < M; i++) {
        scanf(" %c %d %d", &a, &b, &c);
        //printf("%c %d %d \n", a, b, c);

        if (a == 'E') {
            graph[b].push_back({ c,1 });
            graph[c].push_back({ b,1 });
        }
        else {
            graph[b].push_back({ c,0 });
            graph[c].push_back({ b,0 });
        }
    }

    for (int i = 1; i <= 1000; i++) {

        memset(visit, 0, sizeof(visit));
        dfs(0, i,0,i);

    }
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (find(i) == i) answer++;
        //printf("%d ", arr[i]);
    }
    printf("%d", answer);
}