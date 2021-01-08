#include<iostream>
using namespace std;
int main()
{
    int odd = 0,event = 0;
    int N;
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        int x;
        cin>>x;
        if(x % 2 == 0)
            ++event;
        else 
            ++odd;
    }
    cout<<odd<<" "<<event;
    return 0;
}