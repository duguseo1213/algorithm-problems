#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) 
{
    int i=deliveries.size()-1;
    int j=pickups.size()-1;
    
    long long answer=0;
    while(1)
    {
        int icap=cap;
        int jcap=cap;
        
        int idex=-1;
        int jdex=-1;
        
        while(i>=0)
        {
            if(deliveries[i]<=icap)
            {
                if(deliveries[i]>0)
                {
                    idex=max(idex,i+1);
                }
                icap-=deliveries[i];
                deliveries[i]=0;
                i--;
                
            }
            else
            {
                idex=max(idex,i+1);
                deliveries[i]-=icap;
                break;
                
            }
        }
        
        while(j>=0)
        {
            if(pickups[j]<=jcap)
            {
                if(pickups[j]>0)
                {
                    jdex=max(jdex,j+1);
                }
                jcap-=pickups[j];
                pickups[j]=0;
                j--;
                
            }
            else
            {
                jdex=max(jdex,j+1);
                pickups[j]-=jcap;
                break;
                
            }
        }/*
         printf("%d \n",answer);
        for(int i=0;i<deliveries.size();i++)
        {
            printf("%d ",deliveries[i]);
        }
        printf("\n");
        for(int i=0;i<pickups.size();i++)
        {
            printf("%d ",pickups[i]);
        }
        printf("\n");
        printf("%d %d\n",idex,jdex);
        */
        if(idex!= -1 || jdex!= -1)
        {
            answer=answer+max(idex,jdex)*2;
        }
        if(i==-1 && j==-1) break;
        
        
        
        
        
        
       
        
        
    }
    return answer;
}