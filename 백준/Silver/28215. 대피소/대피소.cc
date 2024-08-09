#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int N,K;

pair<int, int> p[51];

int minn = 21e8;
int arr[3];
void dfs(int dep,int s) {
    if (dep == K) {
        int maxx = 0;
        for (int i = 0; i < N; i++) {
            int minnn = 21e8;
     

            for (int j = 0; j < K; j++) {

               minnn = min(minnn, abs(p[i].first - p[arr[j]].first)+abs(p[i].second - p[arr[j]].second));


            }

            maxx = max(maxx, minnn);

            
        }
        minn = min(minn, maxx);
        //printf("%d\n", maxx);
        return;
    }

    for (int i = s; i < N; i++) {

        arr[dep] = i;
        dfs(dep + 1, i + 1);

    }


}


int main() {
    
    scanf("%d %d", &N, &K);



    for (int i = 0; i < N; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);

        

    }
    dfs(0, 0);
    cout << minn;
}