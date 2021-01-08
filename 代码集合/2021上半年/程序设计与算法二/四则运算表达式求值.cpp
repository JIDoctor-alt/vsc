#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip>

using namespace std;
//计算一个因子的值
double factor_value();
//计算一个项的值
double term_value();
//计算一个表达式的值
double expression_value();
int main()
{
    cout<<fixed<<setprecision(2)<<expression_value()<<endl;
    return 0;
}
///求一个表达式的值
double expression_value()
{
    //求一个项的值
    double result = term_value();
    ///初始为后面有表达式
    bool more = true;
    //这个项可能是加减法表达式
    while (more)
    {   //看一个字符不取走
        char op = cin.peek();
        if(op == '+' || op == '-')
        {//从输入中读走一个字符
            cin.get();
            //计算后面的项
            double value = term_value();
            //如果是加号，加上 同理，减号，则减去
            if(op == '+')result += value;
            else result -= value;
        }else more = false;//如果不是则false
    }
    return result;
}

double term_value()
{
    //因子 计算因子的值
    double result = factor_value();
    //因子可能是乘除
    bool more = true;
    while(more)
    {
        char op = cin.peek();
        //如果是乘除
        if(op == '*' || op == '/'){
            //将前面的运算符（乘除）读走
            cin.get();
            ///计算因子的值
            double value = factor_value();
            //根据运算符进行计算result
            if(op == '*')result *= value;
            else result /= value;
        }else more = false;//不是运算符后面没有因子则false
    }
    //返回因子
    return result;
}
double factor_value()
{
    double result = 0;
    char op = cin.peek();
    //因子可能是在括号中的
    if(op == '('){
        cin.get();//读走左括号
        //计算括号里的表达式
        result = expression_value();
        //读走有括号
        cin.get();
    }else{//不是括号，则可能是一个数
    //判断是否为数字（无论是小数，整数，都是从数字开始
        while(isdigit(op))
        {   //数字计算
            result = result*10 + op - '0';
            cin.get();//读走计算了的数
            op = cin.peek();//读取下一个数

        }
        //判断是否有小数部分
        if(op == '.')
        {
            cin.get();//读走前面的小数点
            op = cin.peek();//
            double t = 0.1;//用来计算小数部分
            while(isdigit(op))
            {
                //计算小数部分
                result += t*(op-'0');
                //每次计算完成后下次如果小数还有数，就右移一位
                t *= 0.1;
                cin.get();//将前面计算的数字读走
                //查看下一个字符
                op = cin.peek();
            }
        }
    }
    return result;
}