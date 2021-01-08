#include<iostream>
#include<algorithm>
using namespace std;
int n;
char c[30005],a[30005];
int main()
{
   // ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 0;i < n;++i)
    {
        cin>>c[i];
    }
    int s = 0,e = n - 1, i = 0;
    while(s <= e)
    {
        if(c[s] < c[e])
        {
            a[i] = c[s++];
        }
        else if(c[s] > c[e])
        {
            a[i] = c[e--];
        }
        else 
        {
            int l = s + 1 , r = e - 1;
            while(l != r)
            {
                if(c[l] == c[r])
                {
                    ++l, --r;
                }
                else 
                {
                    break;
                }
            }
            if(c[l] < c[r])
            {
                a[i] = c[s++];
            }
            else 
            {
                a[i] = c[e--];
            }
        }
        ++i;
    }
    for(int i = 0;i < n;++i)
    {
        cout<<a[i];
        if((i + 1) % 80 == 0)
        {
            cout<<endl;
        }
    }
    return 0;
}