#include<iostream>
#include<vector>
#include<queue>
 
using namespace std;
 
const int INF = 1000000007;
const int MAX_V = 401;
 
int V, E, ret = INF;
 
int dist[MAX_V][MAX_V];
 
void floyd() {
    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E;
 
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            dist[i][j] = INF;
 
    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        if(dist[a][b] > c)
            dist[a][b] = c;
    }
 
    floyd();
 
    for (int i = 1; i <= V; i++) {
        if (ret > dist[i][i])
            ret = dist[i][i];
    }
 
    if (ret == INF)
        cout << -1 << endl;
    else
        cout << ret << endl;
 
    return 0;
}
