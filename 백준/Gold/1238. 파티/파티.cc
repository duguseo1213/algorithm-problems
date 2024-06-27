#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

vector<pair<int,int>> vec[1001]; //value, destination

struct cmp{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.first>b.first;
    }
};

priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq; //다음 값, 위치
int N,M,X;
int visit[1001];
int answer[1001];

void func(int start){
    for(int i=0;i<=1000;i++){
        visit[i]=2100000000;
    }
    visit[start]=0;
    pq.push({0,start});

    while(!pq.empty()){
        pair<int,int> now=pq.top();
        pq.pop();
        
        for(int i=0;i<vec[now.second].size();i++){
            
            if(vec[now.second][i].first+now.first<visit[vec[now.second][i].second]){
                
                visit[vec[now.second][i].second]=vec[now.second][i].first+now.first;
                pq.push({vec[now.second][i].first+now.first,vec[now.second][i].second});
            }

            
        }
        
    }
    

    
}

int main()
{
    scanf("%d %d %d",&N,&M,&X);
    int a,b,c;
    for(int i=0;i<M;i++){
        scanf("%d %d %d",&a,&b,&c);
        
        vec[a].push_back({c,b});
    }
    //printf("%d\n",vec[1].size());
    

    for(int i=1;i<=N;i++){
        func(i);
        answer[i]+=visit[X];
    }
    func(X);
    for(int i=1;i<=N;i++){
        answer[i]+=visit[i];
    }
    int maxx=0;

    for(int i=1;i<=N;i++){
        maxx=max(maxx,answer[i]);
    }
    
    printf("%d",maxx);
    
    
    
}








