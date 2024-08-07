#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

int ly,lx;
int sy,sx;
int ey,ex;

int visit[100][100];
queue<pair<int,int>> q;
int solution(vector<string> maps) {
    
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].size();j++){
            if(maps[i][j]=='S'){
                sy=i;
                sx=j;
            }
            if(maps[i][j]=='E'){
                ey=i;
                ex=j;
            }
            if(maps[i][j]=='L'){
                ly=i;
                lx=j;
            }
        }
    }
    
    q.push({ly,lx});
    visit[ly][lx]=1;
    
    while(!q.empty()){
        
        int y=q.front().first;
        int x=q.front().second;
        
        q.pop();
        
        for(int i=0;i<4;i++){
            
            int ny=y+dy[i];
            int nx=x+dx[i];
            
            if(ny<0 || nx<0 || ny>maps.size()-1 || nx > maps[i].size()-1 || maps[ny][nx]=='X' || visit[ny][nx]!=0){ continue;
                
            }
            
            q.push({ny,nx});
            visit[ny][nx]=visit[y][x]+1;
        }
        
    }
    if(visit[sy][sx]==0 || visit[ey][ex]==0) return -1;
    else{
        return visit[sy][sx]+visit[ey][ex]-2;
    }
    
    
    
    int answer = 0;
    return answer;
}