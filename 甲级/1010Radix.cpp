#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
string n1,n2;
int tag,radix;
long long countT(string str,long long radix)
{
    long long sum = 0;

    for(auto &c : str)
    {
        if(isdigit(c))
        {
            //sum += (c - '0')*pow(radix,i) ;
            sum = sum * radix + (c - '0');
        }
        else 
        {
           // sum += (c - 'a' + 10) * pow(radix,i); 
            sum = sum * radix + (c - 'a' + 10);
        }
    }
    return sum;
}
long long findradix(string n1,long long targer)
{
    char c = *max_element(n1.begin(),n1.end());

    long long low = (isdigit(c) ? c - '0' : c - 'a' + 10) + 1;//进制的下限

    //进制的上限就是n1 ??
    long long high = max(low,targer);

    while(low <= high)
    {
        long long mid = (low + high + 1)/2;


        long long temp = countT(n1,mid);

        if(temp < 0 || temp > targer)
        {
            high = mid - 1;
        }
        else if(temp == targer)
        {
            return mid;
        }
        else 
        {
            low = mid + 1;
        }
    }

    return -1;
}
int main()
{
    //radix是n2的进制
    cin>>n1>>n2>>tag>>radix;

    if(tag == 1)
    {
        swap(n1,n2);
    }

    long long res = findradix(n1,countT(n2,radix));


    if(res != -1)
    {
        cout<<res<<endl;
    }
    else 
    {
        printf("Impossible\n");
    }
    return 0;
}