#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
using pii = pair<int,int>;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int  n = obstacleGrid.size(), m = obstacleGrid[0].size();

        vector<int> fm(m,0);
        fm[0] = 1;
        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                if(obstacleGrid[i][j] == 1){
                    fm[j] = 0;
                    continue;
                }

                if(j - 1 >= 0 && obstacleGrid[i][j -1] == 0)
                    fm[j] += fm[j-1];
            }
        }
        return fm.back();
    }
};