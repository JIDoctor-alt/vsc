#include <iostream>
using namespace std;
int main() {
    int n, a[1000];
    cin >> n;
    for (int i = n; i >= 0; i--) {
        cin >> a[i];
        //系数不为零
        if (a[i] != 0) {
            //不是指数为零的项
            if (i != 0) {
                //不是最高位，正数输出加号
                if (i != n && a[i] > 0) cout << "+";
                //对于系数为-1和1的情况
                if (a[i] == -1) cout << "-";
                //系数不为1则可输出系数
                else if (a[i] != 1) cout << a[i];
                //x项
                cout << "x";
                //指数不为1
                if (i != 1) cout << "^" << i;
            } else {
                //指数为零的项
                if (a[i] > 0) cout << "+";
                cout << a[i];
            }
        }
    }
    return 0;
}