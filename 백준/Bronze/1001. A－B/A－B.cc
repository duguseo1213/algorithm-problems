#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

int dy[8] = { 0,0,1,-1,1,1,-1,-1 };
int dx[8] = { 1,-1,0,0,1,-1,1,-1 };

int sdy[4] = {-1,0,1,0};
int sdx[4] = {0,1,0,-1};


using namespace std;

int main()
{
    int a,b;
    
    cin>>a>>b;
    
    cout<<a-b;
    
}

