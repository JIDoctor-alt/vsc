#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    vector<char> res;
    for(int i = 0;i < b.size();++i)
    {
        char c;
        if(i % 2 == 0)
        {
           if(i < a.size())
            {
                int w = ((a[i] - '0') + (b[i] - '0')) % 13;
                if(w == 10)
                {
                   c = 'J';
                }
                if(w == 11)
                {
                    c = 'Q';
                }
                if(w == 12)
                { 
                    c = 'K';
                }
                if( w < 10)
                {
                    c =  ('0' + w);
                }
            }
            else 
            {
               int w = ( (b[i] - '0')) % 13;
               c =  ('0' + w);
            }
        }
        else 
        {
            if(i < a.size())
            {
               int w = ((b[i] - '0') - (a[i] - '0'));
                if(w < 0)
               {
                   w += 10;
               }
               
               c =  ('0' + w);
            }
            else 
            {
               int w = (b[i] - '0');
               if(w < 0)
               {
                   w += 10;
               }

               c =  ('0' + w);
            }
        }
        res.push_back(c);
      //  cout<<c<<" ";
    }
    for(int i = res.size() - 1;i >= 0;--i)
    {
        cout<<res[i];
    }
    return 0;
}