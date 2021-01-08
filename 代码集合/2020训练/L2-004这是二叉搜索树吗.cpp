#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int N;
bool flag;
int post[10005];
int postorder[10005],cur;
void solve(int s,int e)
{
    if(s > e)
        return;

    int x = post[s];
    int i  = s + 1,j = e;
    
    if(flag)
    {
         while(i <= j && post[i] < x)
             ++i;
            
        while(i <= j && post[j] >= x)
                --j;
    }
    else 
    {
         while(i <= j && post[i] >= x)
            ++i;
        while(i <= j && post[i] < x)
            --j;
    }

    if(i != j + 1)
        return;

    solve(s + 1,i - 1);
    solve(i,e);
   
    postorder[cur++] = x;
}
int main()
{
    int N;
    cin>>N;
    for(int i = 0;i < N;++i)
        cin>>post[i];
   
    flag = true;
    cur = 0;

     solve(0,N - 1);

     if(cur !=  N)
     {
         flag = false;
          cur = 0;
          solve(0,N-1);
     }
     
     if(cur == N)
     {
         cout<<"YES\n";
         int cnt = 0;
         for(int j = 0;j < cur;++j)
         {
             if(cnt != 0)
                cout<<" ";
              else 
                cnt = 1;
            cout<<postorder[j];
         }
     }
     else 
     {
         cout<<"NO\n";
     }
    return 0;
}