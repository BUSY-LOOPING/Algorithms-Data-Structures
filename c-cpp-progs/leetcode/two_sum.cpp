#include <iostream>
#include <bits/stdc++.h>
#include <random>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        this->target = target;
        nums.push_back(target);
        nums.push_back(INT_MAX);
        vector<int> indx;
        vector<int> res;
        for(int i = 0; i < nums.size();i ++) {
            indx.push_back(i);
        }
        //sorting the input array - randomized quick sort
        quickSort(nums, indx ,0, nums.size());
        cout << nums.size() << endl;
        for (int i = 0; i < nums.size() - 1; i ++) {
            cout << indx[i] << "  ";
        }
        return res;
    }
private:
    int targetPos = -1;
    int target = 0;
    void myswap(vector<int>& lst, int i, int j) {
        int temp = lst[i];
        lst[i] = lst[j];
        lst[j] = temp;
    }

    int partition(vector<int>& nums,vector<int>& idx, int l, int h) {
        srand(time(0));
        int pivot_idx =l + (rand()% static_cast<int>(h - l + 1));
        int pivot = nums[pivot_idx];
        int i = l, j = h;
        while (i < j) {
            do {
                i++;
            }while(nums[i] <= pivot);

            do {
                j--;
            }while(nums[j] > pivot);

            if (i < j) {  
                myswap(idx, i, j);
                swap(nums[i], nums[j]);
            }
        }
        if (this->target != -1 && nums[pivot_idx] == this->target) {
            this->targetPos = j;
        }
        myswap(idx, pivot_idx, j);
        swap(nums[pivot_idx], nums[j]);

        return j;
    }

    void quickSort(vector<int>& nums,vector<int>& idx, int l, int h) {
        if (l < h) {
            int j = partition(nums, idx, l, h);
            quickSort(nums, idx, l, j);
            quickSort(nums, idx, j + 1, h);
        }
    }
};

int main() {
    Solution s;
    vector<int> v1 {2,11, 7,15};
    vector<int> res = s.twoSum(v1, 9);
    cout << res[0] <<"  " <<res[1];
}