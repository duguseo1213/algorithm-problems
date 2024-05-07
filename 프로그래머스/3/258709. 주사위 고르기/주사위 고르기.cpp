#define P printf

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A_sel;
vector<int> B_sel;

//vector<int> A_sum;
//vector<int> B_sum;

int A_sum[100000];
int B_sum[100000];



vector<int> answer;

int N;
int arr[10][6];
int maxx=0;
int cnt;
int acnt=0;
int bcnt=0;
int visit[10];

void twopoint()
{
    cnt=0;
    
    sort(&A_sum[0],&A_sum[0]+acnt);
    sort(&B_sum[0],&B_sum[0]+bcnt);
    int i=0;
    int j=0;
    /*
    for(int i=0;i<A_sum.size();i++)
    {
        int left=0;
        int right=B_sum.size()-1;
        int index=-1;
        while(1)
        {
            if(left>right) break;
            int mid=(left+right)/2;
            
            if(A_sum[i]>=B_sum[mid])
            {
                index=mid;
                left=mid+1;
            }
            else
            {
                
                right=mid-1;
            }
            
        }
        
        if(index!=-1)
        {
            cnt+=index;
        }
        
    }
        */
        
    
    while(1)
    {     
        if(i>=acnt)
        {     
            break;
        }
        if(j>=acnt)
        {
            cnt=cnt+acnt*(acnt-i-1);
            break;
        }
        
        if(A_sum[i]>B_sum[j])
        {
            j++;
            cnt++;
        }
        else if(A_sum[i] == B_sum[j])
        {
            i++;
            
            if(i<acnt) cnt=cnt+j;
        }
        else
        {
            i++;
            if(i<acnt) cnt=cnt+j;
        }
        //P("%d %d %d\n",A_sum[i],B_sum[j],cnt);
    }
    
    
   // P("%d\n",cnt);
    
}

void dfs_a(int dep,int sum)
{
    
    if(dep==N)
    {
        A_sum[acnt]=sum;
        acnt++;
        return;
    }
        
    for(int i=0;i<6;i++)
    {
        dfs_a(dep+1,sum+arr[A_sel[dep]][i]);
    }
           
}

void dfs_b(int dep,int sum)
{
    
    if(dep==N)
    {
        B_sum[bcnt]=sum;
        bcnt++;
        return;
    }
        
    for(int i=0;i<6;i++)
    {
        dfs_b(dep+1,sum+arr[B_sel[dep]][i]);
    }
           
}



void sel_dice(int dep,int s)
{
    if(dep==N)
    {
        //dfs
        for(int i=0;i<dep*2;i++)
        {
            if(visit[i]==0)
            {
                A_sel.push_back(i);
            }
            else
            {
                B_sel.push_back(i);
            }
        }
        
        acnt=0;
        bcnt=0;
        
        dfs_a(0,0);
        dfs_b(0,0);
       
        twopoint();
        
        if(cnt>maxx)
        {
            maxx=cnt;
            answer.clear();
            for(int i=0;i<A_sel.size();i++)
            {
                answer.push_back(A_sel[i]+1);
            }
            
        }
        
        //A_sum.clear();
       // B_sum.clear();
        A_sel.clear();
        B_sel.clear();
        
        return;
    }
    
    for(int i=s;i<N*2;i++)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            sel_dice(dep+1,i);
            visit[i]=0;
        }
    }
    
    
    
    return;
    
}




vector<int> solution(vector<vector<int>> dice) {
    
    for(int i=0;i<dice.size();i++)
    {
        for(int j=0;j<6;j++)
        {
            arr[i][j]=dice[i][j];

        }

    }
    
    N=dice.size()/2;

    //twopoint();
    
    sel_dice(0,0);
    //P("%d",maxx);
    
    return answer;
}