#include <string>
#include <vector>

using namespace std;

int answer[1000000];

vector <int> stack;

vector<int> solution(vector<int> numbers) {
    
    stack.push_back(numbers[numbers.size()-1]);
    //printf("%d",stack[0]);
    answer[numbers.size()-1]=-1;
    
    for(int i=numbers.size()-2;i>=0;i--)
    {
        while(1)
        {
            if(stack.size()==0)
            {
                answer[i]=-1;
                stack.push_back(numbers[i]);
                break;
            }
            
            if(numbers[i]>=stack.back() )
            {
                stack.pop_back();
            }
            else
            {
                
                answer[i]=stack.back();
                stack.push_back(numbers[i]);
                
                break;
            }
        }
    }
    vector<int> answer2;
    for(int i=0;i<numbers.size();i++)
    {
        answer2.push_back(answer[i]);
        //printf("%d ",answer[i]);
        
    }
    
    
    
    return answer2;
}