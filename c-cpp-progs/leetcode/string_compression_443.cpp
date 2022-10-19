#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {

        vector<char> res;
        int count = 1;
        for (int i = 0; i < chars.size(); i++)
        {
            if (i+1 < chars.size() && chars[i] == chars[i+1]) {
                count++;
            } else {
                res.push_back(chars[i]);
                if (count > 1) {
                    // while (count % 10 > 0) {
                    //     res.push_back(char(count % 10) + 48);
                    //     count /= 10;
                    // }
                    string s = to_string(count);
                    for (int j = 0; j < s.length(); j++) {
                        res.push_back(s[j]);
                    }
                    count = 1;
                }
            }
        }
        chars = res;
        return res.size();
    }
};

int main()
{
    Solution s;
    vector<char> vect{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    vector<char> vect2{'a'};
    vector<char> vect3{'a','b','b','b','b','b','b','b','b','b','b','b','b'};

    cout << endl<<s.compress(vect3);
    return 1;
}