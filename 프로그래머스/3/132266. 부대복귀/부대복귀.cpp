#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> graph[100001];
queue<int> q;

int visit[100001];
int dest;

int bfs(int s)
{
    while(!q.empty())
    {
        q.pop();
    }
    q.push(s);
    visit[s]=1;
    
    while(!q.empty())
    {
        int now=q.front();
        if(now==dest) return visit[now]-1;
        q.pop();
        for(int i=0;i<graph[now].size();i++)
        {
            if(visit[graph[now][i]]==0)
            {
                q.push(graph[now][i]);
                visit[graph[now][i]]=visit[now]+1;
                
            }
        }
    }
    
    return -1;
    
}


vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    
    for(int i=0;i<roads.size();i++)
    {
        graph[roads[i][0]].push_back(roads[i][1]);
        graph[roads[i][1]].push_back(roads[i][0]);
    }
    
    dest=destination;
    vector<int> answer;
    for(int i=0;i<sources.size();i++)
    {
        memset(visit,0,sizeof(visit));
        answer.push_back(bfs(sources[i]));
    }
    
    
    
    return answer;
}