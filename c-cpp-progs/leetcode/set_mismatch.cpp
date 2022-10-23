#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, bool> m;
        int repeated_num = 0;
        for (int a: nums) {
            if (!m[a]) {
                m[a] =true;
            } else {
                repeated_num = a;
            }
        }
        res.push_back(repeated_num);

        for (int i=1; i<=nums.size(); i++) {
            if (!m[i]) {
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};