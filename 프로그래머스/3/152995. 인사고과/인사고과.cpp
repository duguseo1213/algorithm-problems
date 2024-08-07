#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> vec;
vector<int> vecvec;
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    
    return a.first>b.first;
}

int firstmaxx;
int secondmaxx;



int solution(vector<vector<int>> scores) {
    for(int i=0;i<scores.size();i++){
        vec.push_back({scores[i][0],scores[i][1]});
    }
    
    if(scores.size()==1){
        return 1;
    }
    
    pair<int,int> temp=vec[0];
    sort(vec.begin(),vec.end(),cmp);
   
    
    
    vecvec.push_back(vec[0].first+vec[0].second);
    secondmaxx=vec[0].second;
    for(int i=1;i<vec.size();i++){
        
        
        if(vec[i].first!=vec[i-1].first){
            firstmaxx=max(firstmaxx,secondmaxx);          
        }
        secondmaxx=max(secondmaxx,vec[i].second);
        //printf("%d %d %d %d\n",vec[i].first,vec[i].second,firstmaxx,secondmaxx);
        if(vec[i].second<firstmaxx){
            
            if(vec[i]==temp){
                return -1;
            }
            
        }
        else{
            vecvec.push_back(vec[i].first+vec[i].second);
        }
        
        
    }
    
    sort(vecvec.begin(),vecvec.end(),greater<int>());
    
    for(int i=0;i<vecvec.size();i++){
        printf("%d ",vecvec[i]);
        if(temp.first+temp.second==vecvec[i]){
            return i+1;
        }
    }
    
    int answer = 0;
    return answer;
}