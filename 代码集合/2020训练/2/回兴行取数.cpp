#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int a[201][201];
    memset(a,-1,sizeof(a));

    int i = 0,j = 0;

    for(i = 0;i < m;++i)
        for(j = 0;j < n;++j)
            cin>>a[i][j];
    i = 0,j = 0;

    int total = 0;
    while (total < n*m)
    {
        while(i <= m-1 && a[i][j] != -1)
        {
            cout<<a[i][j]<<(total != n*m - 1 ? " " : "\n");a[i][j] = -1;
            ++total;
            ++i;
            
        }
        --i;
        ++j;
        while(j <= n-1 && a[i][j] != -1)
        {
            cout<<a[i][j]<<(total != n * m - 1 ? " " : "\n");
            ++total;a[i][j] = -1;
            ++j;
            
        }
        --i;
        --j;
        while(i >= 0 && a[i][j] != -1)
        {
            cout<<a[i][j]<<(total != n*m - 1 ? " " : "\n");
            ++total;a[i][j] = -1;
            --i;
            
        }
        ++i;
        --j;
        while(j >= 0 && a[i][j] != -1)
        {
            cout<<a[i][j]<<(total != n*m - 1 ? " ": "\n");
            ++total;a[i][j] = -1;
            --j;
            
        }
        ++i;
        ++j;
    }
    
    return 0;
}