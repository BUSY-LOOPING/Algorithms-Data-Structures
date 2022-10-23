// #include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++) {
            try {
                vector<int> map_value = m.at(nums[i]);
                for (int j = 0; j < map_value.size(); j++) {
                    if (abs(map_value[j] - i) <= k) {
                        return true;
                    }
                }
                map_value.push_back(i);
                m[nums[i]] = map_value;
            
            }catch(const std::out_of_range&){
                vector<int> temp{i};
                m.insert({nums[i], temp});
            }
        }
        return false;
    }
};

int main() {
    unordered_map<int, vector<int>> m;
    m.insert({1, vector<int>{1}});
    vector<int> temp = m[1];
    cout << temp.size() << endl;
    Solution s;
    vector<int> v{1,2,3,1,2,3};
    int k = 2;
    cout << s.containsNearbyDuplicate(v, k);
}