###第九届蓝桥杯大赛个人赛决赛（软件类）真题\C大学B组

---

### 标题：换零钞

> 考点：
>
> 总结：解方程求x的最小值。`200 - 21 *x `能够被5整除时x的最小值。

```ruby
74
```

### 标题：激光样式

> 考点：枚举
>
> 总结：二进制

```ruby
#include<iostream>

using namespace std;

//求x在二进制表示下第k位是0还是1
inline int get(int x,int k)
{
    return x >> k & 1;
}

int main()
{
    int cnt = 0;
    for(int i = 0;i < 1<<30;i++)
    {
        bool flag = true;
        for(int j = 1;j < 30;j++)
            if(get(i,j)&&get(i,j-1))//相邻两位不能同时为1
            {
                flag = false;
                break;
            }
        cnt += flag;
    }
    cout<<cnt<<endl;
    return 0;
}
//2178309
```



* 递推解法
* `f(i,0) `所有长度是i,最后一位是0且没有连续1的方案数
* `f(i,1)`所有长度是i,最后一位是1且没有连续1的方案数

```ruby
#include<iostream>

using namespace std;


int main()
{
    int f[40][2] = {0};//初始值为0

    f[0][0] = 1;//没有的是否只有一种
    for(int i = 1;i <= 30;i++)
    {
        f[i][0] = f[i-1][0] + f[i-1][1];
        f[i][1] = f[i-1][0];
    }
    cout<<f[30][0]+f[30][1]<<endl;
    return 0;
}
//2178309
```

### 标题：格雷码

> 考点：二进制
>
> 总结：十进制在计算机中是以二进制的形式存在的，一个数的负数可以看做 这个数的原码取反再加一得到（也可以看做是原码通过，找到最后一个1的位置，该1的位置以及后面的零不变，前面的数取反（包括符号位）即可）。拓展：而对于负数转变成它的原码，则需要将符号位不变，最后一个1以及这个1后面的数不变，以前面的数值位取反即可。
>
> 异或：`0 ^ 0 = 0; 0 ^ 1 = 1 ; 1 ^ 0 = 1;1 & 1 = 0`相同为0，不同为1。

```ruby

#include <stdio.h>

using namespace std;
void show(int a,int n)
{
	int i;
	int msk = 1;
	for(i=0; i<n-1; i++) msk = msk << 1;
	for(i=0; i<n; i++){
		printf((a & msk)? "1" : "0");
		msk = msk >> 1;
	}
	printf("\n");
} 

void f(int n)
{
	int i;
	int num = 1;
	for(i=0; i<n; i++) num = num<<1;
	
	int a = 0;
	for(i=0; i<num; i++){
		show(a,n);
		
		if(i%2==0){
			a = a ^ 1;
		}
		else{//树状树状基本操作
			a = a ^ ((a & -a) << 1); //填空  找到最后一个1的位置，左移一位，在异或
		}
	}
}

int main()
{
	f(4);
	return 0;
}

```

### 标题：调手表

> 考点：bfs
>
> 总结：最短距离

```ruby
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int N = 100010;
int d[N];
int n,k;
void bfs()
{
    queue<int> q;

    memset(d,-1,sizeof(d));
    d[0] = 0;
    q.push(0);

    while(q.size())
    {
        auto t = q.front();
        q.pop();

        int a = (t+1)%n;
        if(d[a] == -1)
        {
            d[a] = d[t] + 1;
            q.push(a);
        }

        int b = (t + k)%n;
        if(d[b] == -1)
        {
            d[b] = d[t] + 1;
            q.push(b);
        }
    }
}

int main()
{
    cin>>n>>k;
    
    bfs();

    int res = 0;
    for(int i = 0;i < n;++i)
        res = max(res,d[i]);
    
    cout<<res<<endl;
    return 0;
}
```

### 标题：搭积木

> 考点：动归规划
>
> 总结：

```ruby
#include<iostream>

using namespace std;

typedef long long LL;

const int N = 110, mod = 1e9 + 7;

int n,m;
LL s[N][N];//二维前缀和
int c[N][N];//表示第i层前j个字符中有多少个'X'
LL f[N][N][N];

void get_prefix_sum(int i)
{
    for(int j = 1;j <= m;j++)
        for(int k = 1;k <= m;k++)
            s[j][k] = (s[j - 1][k] + s[j][k - 1] - s[j - 1][k - 1] + f[i][j][k])%mod;
        
}

LL get_sum(int x1,int y1,int x2,int y2)
{
    return (s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1])%mod;
}

int main()
{
    cin>>n>>m;
    
    char str[N];

    for(int i = n;i;i--)
    {
        cin>>str + 1;
        for(int j = 1;j <= m;++j)
            c[i][j] = c[i][j-1] + (str[j] == 'X');
    }

    //初始化dp数组
    f[0][1][m] = 1;
    get_prefix_sum(0);

    int res = 1;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= m;++j)
        {
            for(int  k = j;k <= m;k++)
            if(c[i][k] - c[i][j-1] == 0)
            {
                LL &x = f[i][j][k];
                x = (x + get_sum(1,k,j,m))%mod;
                res = (res + x)%mod;
            }
        }
        get_prefix_sum(i);
    }

    cout<<(res + mod)%mod<<endl;

    return 0;
}
```

### 标题：矩阵求和

> 考点：
>
> 总结：

```ruby
#include<iostream>

using namespace std;

typedef long long LL;

const int N = 1e7+10, mod = 1e9 + 7;

int primes[N],euler[N],cnt;
bool st[N];

LL s[N];

//质数存在在primes[]中，euler[i]表示
//i的欧拉函数

void get_eulers(int n)
{
    euler[1] = 1;
    for(int i = 2;i <= n;++i)
    {
        if(!st[i])
        {
            primes[cnt++] = i;
            euler[i] = i - 1;
        }
        for(int j = 0;j < cnt && i * primes[j] <= n;j++)
        {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0)
            {
                euler[i * primes[j]] = euler[i] * primes[j];
                break;
            }
            euler[i * primes[j]] = euler[i] * (primes[j] - 1);
        }
    }

    s[1] = euler[1];
    for(int i = 2;i <= n;i++)
        s[i] = (s[i - 1] + 2 * euler[i])%mod;
}

int main()
{
    int n;
    cin>>n;

    get_eulers(n);

    LL res = 0;
    for(int d = 1;d <= n;d++)
        res = (res + s[n/d] * d % mod *d)%mod;
    
    cout<<res<<endl;
    return 0;
}
```





--------

###数论问题算法模板

1.欧几里得算法

```ruby
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
```

2.扩展欧几里得算法

> 

```ruby
nt exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1; y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a/b) * x;
    return d;
}
```

3.线性筛素数

```ruby
int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )//筛选掉所有质数的倍数
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
```

4.欧拉函数

```ruby
int primes[N], euler[N], cnt;
bool st[N];

// 质数存在primes[]中，euler[i] 表示
// i的欧拉函数
void get_eulers(int n)
{
    euler[1] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i])
        {
            primes[cnt ++ ] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
            {
                euler[i * primes[j]] = euler[i] * primes[j];
                break;
            }
            euler[i * primes[j]] = euler[i] * (primes[j] - 1);
        }
    }
}

```

