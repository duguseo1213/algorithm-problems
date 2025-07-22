#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int answer;
int N;

vector<vector<int>> qq;
vector<int> anss;

vector<int> vec;

int arr[31];

bool check(){
    for(int i=0;i<qq.size();i++){
        int cnt=0;
        for(int j=0;j<qq[i].size();j++){
            if(arr[qq[i][j]]==1){
                cnt++;
            }
        }
        if(cnt!=anss[i]){
            return false;
        }
    }
    return true;
}

void dfs(int depth,int s){
    if(depth==5){
        memset(arr,0,sizeof(arr));
        for(int i=0;i<vec.size();i++){
            arr[vec[i]]=1;
           // printf("%d ",vec[i]);
        }
        //printf("\n");
        if(check()){
            answer++;
        }
        ///
        return;
    }
    
    
    for(int i=s;i<=N;i++){
        vec.push_back(i);
        dfs(depth+1,i+1);
        vec.pop_back();
    }
    
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    anss=ans;
    qq=q;
    N=n;
    dfs(0,1);
    return answer;
}