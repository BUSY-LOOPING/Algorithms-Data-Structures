#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++){
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }

};

int main() {
    Solution s;
    vector<int> v1 {2,11, 7,15};
    vector<int> res = s.twoSum(v1, 9);
    cout << res[0] <<"  " <<res[1];
}