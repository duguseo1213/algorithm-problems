#include <string>
#include <vector>

using namespace std;
int minn=987654321;
void dfs(int storey, int sum)
{
    if(storey==0)
    {
        minn=min(sum,minn);
        return ;
    }
    if(storey==1)
    {
        minn=min(sum+1,minn);
        return;
    }
    dfs((storey+10-storey%10)/10,sum+10-storey%10);
    
    dfs((storey-storey%10)/10,sum+storey%10);
 
    
}

int solution(int storey) {
    int answer = 0;
    
    dfs(storey,0);
    
    
    return minn;
}