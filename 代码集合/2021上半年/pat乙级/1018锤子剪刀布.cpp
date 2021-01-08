#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
int main()
{
    int N;
    cin>>N;
    map<char,int> ms1,ms2;
    int a1 = 0,a2 = 0, a3 = 0,b1 = 0,b2 = 0,b3 = 0;
    while (N--)
    {
        char x,y;
        cin>>x>>y;
        if(( x == 'C' && y == 'J')||(x == 'B' && y == 'C')||(x == 'J' && y == 'B'))//甲赢
        {
            ++a1;
            ++b3;
            ms1[x]++;
        }
        else if(( y == 'C' && x == 'J')||(y == 'B' && x == 'C')||(y == 'J' && x == 'B'))//乙赢
        {
            ++b1;
            ++a3;
            ms2[y]++;
        }
        else 
        {
            ++a2;
            ++b2;
        }
    }
    int ans1 = 0, ans2 = 0;
    char x1,x2;
    map<char,int>::iterator w1,w2;
    for(w1 = ms1.begin(),w2 = ms2.begin();w1 != ms1.end() && w2 != ms2.end();++w1,++w2)
    {
        if(w1->second > ans1)
        {
            ans1 = w1->second;
            x1 = w1->first;
        }
        else if(w1->second == ans1)
        {
            if(w1->first < x1)
            {
                x1 = w1->first;
            }
        }

        if(w2->second > ans2)
        {
            ans2 = w2->second;
            x2 = w2->first;
        }
        else if(w2->second == ans2)
        {
            if(w2->first < x2)
            {
                x2 = w2->first;
            }
        }
    }
    cout<<a1<<" "<<a2<<" "<<a3<<endl;
    cout<<b1<<" "<<b2<<" "<<b3<<endl;
    cout<<x1<<" "<<x2<<endl;
    return 0;
}