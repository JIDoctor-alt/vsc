#include<iostream>
#include<string>
using namespace std;
int a[2];
int main()
{
    string str;
    getline(cin,str);
    int sum = 0;
    for(int i = 0;i < str.size();++i)
    {
        char c = str[i];
        if(isalpha(c))
        {
            if(isupper(c))
            {
                c = tolower(c);
            }
            sum += (c - 'a' + 1);
        }
    }
    while(sum)
    {
        int w = sum % 2;
        ++a[w];
        sum /= 2;
    }
    cout<<a[0]<<" "<<a[1]<<endl;
    return 0;
}