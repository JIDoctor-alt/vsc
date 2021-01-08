#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto w : wordDict)
        {
            if(s.find(w) != string::npos)
            {
                int index = s.find(w);
                s.erase(index,w.size);
            }
        }
        return s.size() == 0;
    }
};