#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct mine{
    int dia;
    int iron;
    int stone;
};

bool cmp(mine a,mine b){
    if(a.dia==b.dia){
        if(a.iron==b.iron){
            return a.stone>b.stone;
        }
       return a.iron>b.iron;
    }
     return a.dia > b.dia;
}

vector<mine> order;
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int pcnt=picks[0]+picks[1]+picks[2];
    for(int i=0;i<pcnt*5 && i<minerals.size();i=i+5){
        mine temp={0,};
        for(int j=0;j<5;j++){
            if(i+j==minerals.size()) break;
            
            if(minerals[i+j]=="diamond"){
                temp.dia++;
            }
            else if(minerals[i+j]=="iron"){
                temp.iron++;
            }
            else{
                temp.stone++;
            }
            
        }
        order.push_back(temp);
        
    }
    
    sort(order.begin(),order.end(),cmp);
    //int answer=0;
    for(int i=0;i<order.size();i++){
        if(picks[0]>0){
            picks[0]--;
            answer=answer+(order[i].dia+order[i].iron+order[i].stone);
        }
        else if(picks[1]>0){
            picks[1]--;
            answer=answer+(5*order[i].dia+order[i].iron+order[i].stone);
        }
        else if(picks[2]>0){
            picks[2]--;
            answer=answer+(25*order[i].dia+5*order[i].iron+order[i].stone);
        }
    }
    
    
    return answer;
}