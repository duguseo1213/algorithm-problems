#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
using namespace std;
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
int map[505][505];
int cnt=2;

set<int> s;

int N,M;

queue<pair<int,int>> q;

void bfs(int i,int j)
{
    q.push({i,j});
    map[i][j]=cnt;
    
    while(!q.empty())
    {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int k=0;k<4;k++)
        {
            
            int ny=y+dy[k];
            int nx=x+dx[k];
            
            
            if(ny<0 || nx<0 ||ny>N-1 || nx>M-1) continue;

            if(map[ny][nx]==1)
            {
               
                map[ny][nx]=cnt;
                q.push({ny,nx});
            }
            
            
        }
        
    }
    
    
}

int dat[250000];

int solution(vector<vector<int>> land) 
{
    int answer = 0;
    N=land.size();
    M=land[0].size();
    for(int i=0;i<land.size();i++)
    {
        for(int j=0;j<land[0].size();j++)
        {
            map[i][j]=land[i][j];
      
        }
    }
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {

            if(map[i][j]==1)
            {
                bfs(i,j);
                cnt++;
            }    
        }
    }
    

    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            dat[map[i][j]]++;
           
        }
        
    }
    int maxx=0;
    for(int i=0;i<M;i++)
    {
        s.clear();
        int answer=0;
        for(int j=0;j<N;j++)
        {
            if(map[j][i]!=0){
            s.insert(map[j][i]);
            }
        }
        for(auto j= s.begin();j!=s.end();j++)
        {
            
            
            answer+=dat[*j];
        }
        
        
        maxx=max(answer,maxx);       
        
    }
    
    
    return maxx;
}


