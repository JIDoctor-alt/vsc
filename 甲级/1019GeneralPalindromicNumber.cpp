#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<int> toPalindromic(int number,int base)
{
    vector<int> list;
    if(number == 0)
    {
        list.push_back(0);
        return list;
    }

    while(number != 0)
    {
        int bit = number % base;
        list.push_back(bit);
        number /= base;
    }
    return list;
}
bool isPalindromic(vector<int> list)
{
    int length = list.size();
    for(int i = 0,j = length - 1;i < length/2;i++,j--)
    {
        if(list[i] != list[j])
            return false;
    }
    return true;
}
int main()
{
    int number,base;
    cin>>number>>base;
    vector<int> builder = toPalindromic(number,base);
    cout<<(isPalindromic(builder) ? "Yes\n" : "No\n");
    for(int i = builder.size() - 1;i >= 0;i--)
        printf("%d%s",builder[i],i== 0 ? "\n" : " ");
    
    return 0;

}