#include <iostream>

#include <unordered_map>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
    private:
    bool static comp(const pair<string, int>& p1,const pair<string, int>& p2) {
        if (p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    } //use static is imp

    public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> m;  //unordered_map is faster
        for (int i = 0; i < words.size(); i++) {
            m[words[i]] += 1;
        }
        vector<pair<string, int>> temp(m.begin(), m.end());
        sort(temp.begin(), temp.end(), comp);
        for (int i = 0; i < k && i < temp.size(); i ++)
            res.push_back(temp[i].first);
        return res;
    }
};

int main() {
    Solution s;
    vector<string> words{"glarko","zlfiwwb","nsfspyox","pwqvwmlgri","qggx","qrkgmliewc","zskaqzwo","zskaqzwo","ijy","htpvnmozay","jqrlad","ccjel","qrkgmliewc","qkjzgws","fqizrrnmif","jqrlad","nbuorw","qrkgmliewc","htpvnmozay","nftk","glarko","hdemkfr","axyak","hdemkfr","nsfspyox","nsfspyox","qrkgmliewc","nftk","nftk","ccjel","qrkgmliewc","ocgjsu","ijy","glarko","nbuorw","nsfspyox","qkjzgws","qkjzgws","fqizrrnmif","pwqvwmlgri","nftk","qrkgmliewc","jqrlad","nftk","zskaqzwo","glarko","nsfspyox","zlfiwwb","hwlvqgkdbo","htpvnmozay","nsfspyox","zskaqzwo","htpvnmozay","zskaqzwo","nbuorw","qkjzgws","zlfiwwb","pwqvwmlgri","zskaqzwo","qengse","glarko","qkjzgws","pwqvwmlgri","fqizrrnmif","nbuorw","nftk","ijy","hdemkfr","nftk","qkjzgws","jqrlad","nftk","ccjel","qggx","ijy","qengse","nftk","htpvnmozay","qengse","eonrg","qengse","fqizrrnmif","hwlvqgkdbo","qengse","qengse","qggx","qkjzgws","qggx","pwqvwmlgri","htpvnmozay","qrkgmliewc","qengse","fqizrrnmif","qkjzgws","qengse","nftk","htpvnmozay","qggx","zlfiwwb","bwp","ocgjsu","qrkgmliewc","ccjel","hdemkfr","nsfspyox","hdemkfr","qggx","zlfiwwb","nsfspyox","ijy","qkjzgws","fqizrrnmif","qkjzgws","qrkgmliewc","glarko","hdemkfr","pwqvwmlgri"};
    vector<string> res = s.topKFrequent(words, 14);
    for (string word : res) {
        cout << word << " ";
    }

}