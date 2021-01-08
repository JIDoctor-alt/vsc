#include<iostream>
using namespace std;
int n,d,nonprime[100010];
int getreverse(int n,int d)
{
    int s  = 0;
    while(n != 0)
    {
        s = s * d + (n % d);
        n /= d;
    }
    return s;
}

int main()
{
    for(int i = 2;i * i < 100010;++i)
    {
        for(int j = 2;j * i < 100010;++j)
            nonprime[i * j] = 1;
    }
    nonprime[0] = nonprime[1] = 1;
    while(true)
    {
        scanf("%d",&n);
        if(n < 0)
            break;
        scanf("%d",&d);
        if(nonprime[n] || nonprime[getreverse(n,d)])
            cout<<"No\n";
        else 
            cout<<"Yes\n";
    }
    return 0;
}