#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
   string str;
   int N;
   int j;
   cin>>str>>N;
   for(int cnt = 1;cnt < N;++cnt)
   {
     //  int len = int(str.size());
       string t;
       for(int i = 0;i < str.size();i = j)
       {
           for(j = i;j < str.size() && str[j] == str[i];j++);
           /*
           例如原有表达式 A=A+B
改为A+=B
这样不仅减少了敲入代码的数量，而且由于变量A只出现一次，在运行时也提高了系统的性能。*/
           t += str[i] + to_string(j - i);//这里会超时 x+=y等价于x=x+y和类型强制转换两个操作。
       }
       str = t;
   }
   cout<<str<<endl;
   return 0;
}
/*
原有表达式 A=A+B改为A+=B这样不仅减少了敲入代码的数量，而且由于变量A只出现一次，在运行时也提高了系统的性能。*/