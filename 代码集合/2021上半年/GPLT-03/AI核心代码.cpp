#include<iostream>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<regex>
using namespace std;
//  \s 代表空格  *代表 0 ~ 多个   ^ 代表开头  例如 _ _ ab _ _ c _ _ ,只关注ab前面的空格，其余后面的不关心
/*
匹配除换行符以外的任意字符
\w 	匹配字母或数字或下划线或汉字
\s 	匹配任意的空白符
\d 	匹配数字
\b 	匹配单词的开始或结束
^ 	匹配字符串的开始
$ 	匹配字符串的结束
*/
int main()
{
    int N;
    cin>>N;
    //读取回车符
    cin.get();
    while (N--)
    {
       string s;
       getline(cin,s);
       cout<<s<<endl;
       // 替换行首部的空格：  "" （替换成空了）（\s* 代表 0 个到多个）
       s = regex_replace(s,regex(R"(^\s*)"),"");
       //$代表从行尾部开始匹配  ""替换成空
       s = regex_replace(s,regex(R"(\s*$)"),"");
        // \s+ (这里的加号代表多个)多个空格替换成  " "一个空格
       s = regex_replace(s,regex(R"(\s+)")," ");
       //\w是代表字母  \W是代表不是字母（大写的W）  
       //这里我用不是字母来表示 标点符号 。即用这样来代表标点符号
       //将标点符号前面的空格删掉  
       //这里将R"()"中的内容分组取 "$1"
       //多余的空格在前面已经删除了，这里直接删除一个空格就OK了
       //利用正则表达式中的一个概念叫做分组  第一个括号 即代表 $1 替换成它
       s = regex_replace(s,regex(R"(\s(\W))"),"$1");
       //将除了大写的I以外的字符替换成小写字母
       for(auto &c : s)
            if(c != 'I')
                c = tolower(c);
                //将问号替换成!
        s = regex_replace(s,regex(R"(\?)"),"!");
        //替换独立的  这里I_can中间的_是为了解决(独立的I（I can 或者I could不是独立的I）)下边的I_
        s = regex_replace(s,regex(R"(\bcan you\b)"),"I_can");
        s = regex_replace(s,regex(R"(\bcould you\b)"),"I_could");
        //独立的  \b就是边界 board
        s = regex_replace(s,regex(R"(\bI\b|\bme\b)"),"you");
        ///然后再把I_替换下  "I_"
        s = regex_replace(s,regex(R"(I_)"),"I ");

        cout<<"AI: "<<s<<endl;
    }
    
    return 0;
}