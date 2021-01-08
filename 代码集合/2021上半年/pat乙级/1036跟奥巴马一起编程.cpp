#include<iostream>
using namespace std;
int main()
{
    int N;
    char c;
    cin>>N>>c;
    int line ,column;
    column = N;
    line  = (column*1.0)/2  + 0.5;
    for(int i = 0;i < line;++i)
    {
        for(int j = 0;j < column;++j)
        {
            if(i == 0 || i == line - 1)
            {
                cout<<c;
            }
            else 
            {
               if(j == 0 || j == column - 1)
                {
                    cout<<c;
                }
                else 
                {
                    cout<<" ";
                }
            }
            
        }
        cout<<endl;
    }
    return 0;
}