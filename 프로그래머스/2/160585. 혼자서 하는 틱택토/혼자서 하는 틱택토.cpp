#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int answer = -1;
    
    int ocnt=0;
    int xcnt=0;
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]=='O')
            {
                ocnt++;
            }
            else if(board[i][j]=='X')
            {
                xcnt++;
            }
                
        }
    }
    
    if(ocnt-xcnt!=0 && ocnt-xcnt!=1)
    {
        return 0;
    }
    int owin=0;
    int xwin=0;
    int win=0;
    for(int i=0;i<3;i++)
    {
       
        if(board[i][0]==board[i][1] && board[i][2]==board[i][1] && board[i][0]!='.')
        {
            win++;
            if(board[i][0]=='O')
            {
                owin=1;
            }
            else if(board[i][0]=='X')
            {
                xwin=1;
            }

        }
        
    }
    
    if(win>1)
    {
        return 0;
    }
    
    if(owin==1 && ocnt-xcnt!=1)
    {
        return 0;
    }
    if(xwin==1 && ocnt-xcnt!=0)
    {
        return 0;
    }
   
    
    
    win=0;
     owin=0;
     xwin=0;
    for(int i=0;i<3;i++)
    {
       
        if(board[0][i]==board[1][i] && board[2][i]==board[1][i] && board[0][i]!='.')
        {
            win++;
            if(board[0][i]=='O')
            {
                owin=1;
            }
            else if(board[0][i]=='X')
            {
                xwin=1;
            }
        }
         
        
           
    }
    
    if(win>1)
    {
        return 0;
    }
    if(owin==1 && ocnt-xcnt!=1)
    {
        return 0;
    }
    if(xwin==1 && ocnt-xcnt!=0)
    {
        return 0;
    }
    
    if(board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0]=='O')
    {
        if(ocnt-xcnt!=1)
        {
            return 0;
        }
    }
    
    if(board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0]=='X')
    {
        if(ocnt-xcnt!=0)
        {
            return 0;
        }
    }
    
     if(board[0][2]==board[1][1] && board[0][2]==board[2][0] && board[0][2]=='O')
    {
        if(ocnt-xcnt!=1)
        {
            return 0;
        }
    }
    
    if(board[0][2]==board[1][1] && board[0][2]==board[2][0] && board[0][2]=='X')
    {
        if(ocnt-xcnt!=0)
        {
            return 0;
        }
    }
    
    
    
    
    
    
    return 1;
}