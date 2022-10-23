// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;



class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m[nums[i]] > 0 && abs(m[nums[i]] - 1 - i) <= k)
                return true;
            
            m[nums[i]] = i + 1;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> v{1,0,1,1};
    int k = 1;
    cout << s.containsNearbyDuplicate(v, k);
}