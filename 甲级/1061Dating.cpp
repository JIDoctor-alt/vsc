#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
    string str1,str2;
    string day[7]  = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    getline(cin,str1);
    getline(cin,str2);
    char firstC,secondC;
    int j = 0;
    while(j < str1.size() && j < str2.size())
    {
        if(str1[j] == str2[j] && (str1[j] <= 'G' && str1[j] >= 'A'))
            break;

        ++j;
    }
    firstC = str1[j];
    ++j;
    while(j < str1.size() && j < str2.size())
    {
        if((str1[j] == str2[j] && ((str1[j] >= 'A' && str1[j] <= 'N') || isdigit(str1[j]))))
            break;
        ++j;
    }
    secondC = str1[j];
 //   cout<<"========="<<secondC<<endl;
    string dt = day[firstC - 'A'];
    int hh = (isdigit(secondC) ? (secondC - '0') : (secondC - 'A' + 1) + 9);
    getline(cin,str1);
    getline(cin,str2);
    int l1 = int(str1.size()), l2 = int(str2.size());
    int i = 0;
    while(i < l1 && i < l2)
    {
        if(str1[i] == str2[i] && isalpha(str1[i]))
            break;
        ++i;
    }
    int mm = i;
    cout<<dt<<" ";
    printf("%02d:%02d\n",hh,mm);
    return 0;
}