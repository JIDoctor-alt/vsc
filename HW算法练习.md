

[进制转换](https://www.nowcoder.com/questionTerminal/0337e32b1e5543a19fa380e36d9343d7)

题意：长度30位，十进制转换为二进制除法过程的实现，求余数和商。注意下标范围，每次做除法操作从非零的高位开始。

数据： 7571839521700274058756011

输出： 11001000011011001100011111000110010011011010100001100101001000110101111111110101011

```c++
#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	int  num[31];
	int res[2000];

	while (cin>>str) {  //字符串转数字
		for (int i = 0; i < str.size(); i++)
			num[i] = str[i] - '0';

		int size = str.size();
		int index = 0;//结果数组游标

		for (int i = 0; i < size;) { //控制被除数开始位置
			int temp = 0, remain = 0;//余数
			for (int j = i; j < size; j++) { //控制除法运算，竖式除法，从头往后每一位依次作除法
				temp = (10 * remain + num[j]) % 2;
				num[j] = (10 * remain + num[j]) / 2;
				remain = temp;
			}
			res[index] = remain;
			index++;
			while (num[i] == 0) //从第一个非0开始
				i++;
		}

		for (int i = index - 1; i >= 0; i--) //逆序输出
		{
			printf("%d", res[i]);
		}

		printf("\n");

	}
}	
```

#### [剑指 Offer II 041. 滑动窗口的平均值](https://leetcode.cn/problems/qIsx9U/)

> 根据题意，需要一个数据容器来储存数据，因为该容器具有当容量达到上限时需要释放最早加入容器的性质，即符合 “先进先出”，那么这个容器就可以使用队列。另外可以迭代计算队列中的和来提高计算效率，而不是每次都循环计算得到和。
>

```
class MovingAverage {
private:
    int len = 0;
    queue<int> nums;
    double sum = 0;
public:
    MovingAverage(int size) {
        len = size;
    }
    
    double next(int val) {
        nums.push(val);
        sum += val;
        if (nums.size() > len) {
            sum -= nums.front();
            nums.pop();
        }
        return sum / nums.size();
    }
};
```

#### [575. 分糖果](https://leetcode.cn/problems/distribute-candies/)

> 选择两个值最大者，贪心？

#### [剑指 Offer 19. 正则表达式匹配](https://leetcode.cn/problems/zheng-ze-biao-da-shi-pi-pei-lcof/)

>动态规划

#### [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/)

>动态规划

12. #### [12. 整数转罗马数字](https://leetcode.cn/problems/integer-to-roman/)

>模拟：我们用来确定罗马数字的规则是：对于罗马数字从左到右的每一位，选择尽可能大的符号值。
>
><p>根据罗马数字的唯一表示法，为了表示一个给定的整数num,我们寻找不超过num的最大符号值，将num
>    
></p>
>
>减去该符号值，然后继续寻找不超过num的最大符号值，将该符号拼接在上一个找到的符号之后，循环直至num为0。最后得到的字符串即为num的罗马数字表示。</p>
>
>硬编码数字：

```c++
const pair<int, string> valueSymbols[] = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        for (const auto &[value, symbol] : valueSymbols) {
            while (num >= value) {
                num -= value;
                roman += symbol;
            }
            if (num == 0) {
                break;
            }
        }
        return roman;
    }
};
```

#### [36. 有效的数独](https://leetcode.cn/problems/valid-sudoku/)

>哈希表：i/3 j/3 下取整

​	

#### [15. 三数之和](https://leetcode.cn/problems/3sum/)

> 排序+双指针：先排序，从三重循环 化简 两重循环  确定枚举 first的元素  ： 枚举第second元素  ： third 从后向second方向移动
>
> 

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};		
```

#### [122. 买卖股票的最佳时机 II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/)

> 注意题目规定在任何时候最多只持有一张股票
>
> 贪心：求区间最大值
>
> 动态规划：

#### [11. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/)

> 双指针

#### [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/)

> 

