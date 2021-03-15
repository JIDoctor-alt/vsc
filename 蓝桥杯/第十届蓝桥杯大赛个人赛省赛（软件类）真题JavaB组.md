###第十届蓝桥杯大赛个人赛省赛（软件类）真题JavaB组

****

#### 试题 A: 组队 

> 490
>
> 

#### 试题 B: 不同子串 

> 考点：字符串，枚举
>
> 总结：100

```ruby
#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
    string line;
    cin>>line;
    set<string> s;
    for(int i = 0;i < line.size();++i)
    {
        for(int j = i;j <= line.size();++j)
        {
            s.insert(line.substr(i,j-i+1));
        }
    }
    cout<<s.size()<<endl;
    return 0;
}
```

#### 试题 C: 数列求值 

> 考点：枚举（按照顺序）
>
> 总结：
>
> 测试       20190324
> 答案：    4659

```ruby
#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
    int a = 1,b = 1,c = 1;
    int n;
    cin>>n;
    while(--n)
    {
        int d = (a + b + c)%10000;
        a = b , b = c , c = d;
    }
    cout<<a<<endl;
    return 0;
}
```

#### 试题 D: 数的分解 

> 考点：
>
> 总结：
>
> 40785

```ruby
#include<iostream>
#include<string>
#include<set>
using namespace std;
bool check(int number)
{
    while(number > 0)
    {
        int t = number % 10;
        if(t == 2 || t == 4)
            return true;
        number /= 10;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    int res = 0;
    for(int a = 1; a <= n;a++)
    {
        for(int b = a + 1;b <= n && n - a - b > b;b++)
        {
            int c = n - a - b;
            if(!check(a)&&!check(b)&&!check(c))
                res++;
        }
    }
    cout<<res<<endl;
    return 0;
}
```

#### 试题 E: 迷宫 

> 考点：广度优先搜索，方向
>
> 总结：从终点开始搜索找到最短路径，然后开始遍历输出路径

```ruby
186
DDDDRRURRRRRRDRRRRDDDLDDRDDDDDDDDDDDDRDRDRRURRUURRDDDDRDRRRRRURRRDRRDDDRRRRUURUUUUUUULULLUUUURRRRUULLLUUUULLUUULUURRURRURURRRDRDRRRRDRDRDDLLLDDRRDDRDDLDDDLLDDLLLDLDDDLDDRRRRRRRRRDDDDDDRR
```

```ruby
#include<iostream>
#include<cstring>
#include<queue>
#include<set>
using namespace std;

const int N = 55;
int n,m;
string g[N];
int dist[N][N];
int dx[4] = {1,0,0,-1}, dy[4] = {0,-1,1,0};
char dir[4] = {'D','L','R','U'};

void bfs()
{
    queue<pair<int,int> > q;
    memset(dist,-1,sizeof(dist));
    dist[n-1][m-1] = 0;
    q.push({n - 1,m - 1});
    while (q.size())
    {
        auto t = q.front();
        q.pop();

        for(int i = 0;i < 4;++i)//只是找到最短路径
        {
            int x = t.first + dx[i],y = t.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && dist[x][y] == -1 && g[x][y] == '0')
            {
                dist[x][y] = dist[t.first][t.second] + 1;//最短路径距离为1
                q.push({x,y});
            }
        }
    }
    
}
int main()
{
    cin>>n>>m;
    for(int i = 0;i < n;++i)
        cin>>g[i];
    bfs();

    cout<<dist[0][0]<<endl;

    int x = 0,y = 0;
    string res;
    while(x != n - 1 || y != m - 1)
    {
        for(int i = 0;i < 4;++i)//这个步骤必须按照字典序列进行查找
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == '0')
            {
                if(dist[x][y] == 1 + dist[nx][ny])
                {
                    x = nx,y = ny;
                    res += dir[i];
                }
            }
        }
    }

    cout<<res<<endl;
    return 0;
}
```

#### 试题 F: 特别数的和 

> 考点：数字判断，取余
>
> 总结：

```ruby
#include<iostream>
#include<cstring>
#include<queue>
#include<set>
using namespace std;

bool check(int number)
{
    while(number)
    {
        int t = number % 10;
        if(t == 2 ||t == 0 || t == 1 || t == 9)
            return true;
        number /= 10;
    }
    return false;
}

int  main()
{
    int n;
    cin>>n;
    int res = 0;
    for(int i = 1;i <= n;++i)
    {
        if(check(i))
            res += i;
    }
    cout<<res<<endl;
    return 0;
}
```



#### 试题 G: 外卖店优先级

总结：模拟题

考点：

```ruby
#include<iostream>
#include<cstring>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

/*
pair 默认对first升序，当first相同时对second升序；
// 如果两个对象的first和second依次相等，则这两个对象相等；该运算使用元素的==操作符。
*/

const int N = 100010;
int n,m,T;
int last[N],score[N];
bool st[N];
pair<int,int> orders[N];
int main()
{
    cin>>n>>m>>T;//t时刻以内的m条订单
    for(int i = 0;i < m;++i)
    {
        cin>>orders[i].first>>orders[i].second;
    }
    sort(orders,orders + m);
     for(int i = 0;i < m;++i)
    {
        cout<<orders[i].first<<" "<<orders[i].second<<endl;
    }
    //m以后的订单不用管了
    for(int i = 0;i < m && orders[i].first <= T;++i)
    {
        int j = i;
        while(j < m && orders[i] == orders[j])//多少订单
        {
            ++j;
        }
        //t 时刻，编号为id的店收到一个订单
        int t = orders[i].first, id = orders[i].second;

        //每经过 1 个时间单位，如果外卖店没有订单，则优先级会减少 1，最低减 到 0；
        score[id] -= t - last[id] - 1;//优先级（上一个时刻，这一刻不算在内）
        if(score[id] < 0)
        {
            score[id] = 0;
        }
        /*如果某家外卖店某时刻优先级大于 5，则会被系统加入优先缓存中；
        如果 优先级小于等于 3，则会被清除出优先缓存*/
        if(score[id] <= 3)//
        {
            st[id] = false;
        }
        last[id] = t;//保留id最后一个订单的时间


//-------------------------下面开始计算这一时刻的-----------
    //而如果外卖店有订单，则优先级不减反加，每有一单优先级加 2。 
        score[id] += (j - i)*2;

        if(score[id] > 5)
        {
            st[id] = true;
        }

        i = j -  1;//后面有个i++
    }

//最后更新到所有店主在T时刻的状态
    for(int i = 1;i <= n;++i)
    {
        if(last[i] < T)//等于T时已经计算完毕
        {
            score[i] -= T - last[i];
            if(score[i] <= 3)
            {
                st[i] = false;
            }
        }
    }

    int res = 0;
    for(int i = 1;i <= n;++i)
    {
        res += st[i];
    }
    cout<<res<<endl;
    return 0;
}
/*
2 6 6
1 1 
5 2 
3 1 
6 2 
2 1 
6 2
*/
```

####  试题 H: 人物相关性分析

> 考点：字符串
>
> 总结：如果两个名字之间的距离间隔不超过K就计算为一对，A,B和B,A两种形式。即计算A前面不超过K个字符的B的个数，加上B前面不超过K个字符的A的个数，综上为同时出现的次数。（边界处理的情况）。  时间复杂度O(n)

```ruby
20
This is a story about Alice and Bob. Alice wants to send a private message to Bob.
    
#include<iostream>
#include<vector>
#include<string>

using namespace std;
vector<int> a,b;
string str;
bool check(char c)
{
    return c >= 'A'&& c <= 'Z' || c >= 'a'&&c <= 'z';
}
int main()
{
    int k;
    cin>>k;
    getchar();
    getline(cin,str);

    for(int i = 0;i + 5 <= str.size();i++)
        if((!i || !check(str[i-1]))&&(i + 5 == str.size() || !check(str[i + 5])))
        {
            if(str.substr(i,5) == "Alice")
                a.push_back(i);
        }

    for(int i = 0;i + 3 <= str.size();i++)
        if((!i || !check(str[i - 1])) && ( i + 3 == str.size() || !check(str[i + 3])))
        {
            if(str.substr(i,3) == "Bob")
                b.push_back(i);
        }

    long long res = 0;

    for(int i = 0,l = 0,r = -1;i < a.size();++i)//A前面的B的数量
    {
        while(r + 1 < a.size() && b[r + 1] <= a[i])r++;
        while(l <= r && a[i] - 1 - (b[l] + 3) + 1 > k)l++;

        res += r - l + 1;
    }


    for(int i = 0,l = 0,r = -1;i < b.size();++i)//Bob前面的A
    {
        while(r + 1 < b.size()&&a[r + 1] <= b[i])r++;
        while(l <= r && b[i] - 1 - (a[l] + 5) + 1 > k)l++;//Bob字符前的一个字符的下标， 减去 Alice后的一个字符的下标

        res += r - l + 1;
    }
    cout<<res<<endl;
    return 0;
}
```

#### 试题 I: 后缀表达式

> 考点：二叉树、后缀表达式
>
> 总结：后缀表达式可以将减号的个数调整（利用二叉树）`a-(b-c-d-e-f)`通过这样使得减号变少。给定一组数计算组合，对于只有整数的情况，我们只需减去最小值即可。对于有负数的情况，我们要减去尽可能多的负数（也就是加上尽可能小的负数的绝对值）。

```ruby
#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

typedef long long LL;
const int max_n = 100010;
int a[max_n];
int m,n;

int main()
{
    scanf("%d%d",&m,&n);
    int k = m + n + 1;
    LL sum = 0;
    for(int i = 0;i < k;++i)
    {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    sort(a,a + k);
    if(a[0] >= 0)
    {
        sum -= a[0]*2;
    }
    else 
    {
        for(int  i = 0;i < k && a[i] < 0 && n > 0;++i)
        {
            sum -= a[i]*2;
            n--;
        }
    }
    cout<<sum<<endl;
    return 0;
}
```



#### 试题 J: 灵能传输

> 考点：
>
> 总结：脑筋急转弯（可以随意调整S1到Sn-1的值）

```ruby
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N  = 300010;

int n;
LL s[N], a[N];
bool st[N];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        s[0] = 0;
        for(int  i = 1;i <= n;++i)
        {
            scanf("%lld",&s[i]);
            s[i] += s[i-1];
        }
        LL s0 = s[0], sn = s[n];//
        if(s0 > sn)swap(s0,sn);
        sort(s,s + n + 1);
//找到S0和Sn的下标
        for(int i = 0;i <= n;++i)
        {
            if(s[i] == s0)
            {
                s0 = i;
                break;
            }
        }
        for(int i = n;i >= 0;i--)
        {
            if(s[i] == sn)
            {
                sn = i;
                break;
            }
        }
	//sn和s0是初始时的下标

        memset(st,0,sizeof(st));//标记s数组中的数被拿走
        int l = 0, r = n;
            //l从左往右，r从右往左，分别从两个方向隔一个数填入a数组（放数相当于一个循环）
        for(int i = s0;i >= 0;i -=2)
        {
            a[l++] = s[i];
            st[i] = true;
        }
        for(int i = sn;i <= n;i += 2)
        {
            a[r--] = s[i];
            st[i] = true;
        }
        for(int i = 0;i <= n;++i)//从零到n
            if(!st[i])
                a[l++] = s[i];
        LL res = 0;
        for(int i = 1;i <= n;++i)
            res = max(res,abs(a[i] - a[i - 1]));
        cout<<res<<endl;
    }
    return 0;
}
```

