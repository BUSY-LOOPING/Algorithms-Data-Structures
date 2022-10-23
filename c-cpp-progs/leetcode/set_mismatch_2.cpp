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
        int sumn = (nums.size() * (nums.size() + 1)) / 2;
        int sumx = 0;
        for (int a: nums) {
            if (!m[a]) {
                m[a] =true;
                sumx += a;
            } else {
                repeated_num = a;
            }
        }
        res.push_back(repeated_num);
        int x = sumn - sumx;
        res.push_back(x);
        return res;
    }
};

int main() {
    vector<int> v{1,2,2,4};
    Solution s;
    vector<int> res = s.findErrorNums(v);
    cout << res[0] << res[1];
}