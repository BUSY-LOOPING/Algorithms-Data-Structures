#include <iostream>
#include <iostream>
#include <string> 
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string output = "1";
        for (int i = 1; i < n ; i ++) {
            string newOut = "";
            int count = 1;
            for (int j =0; j < output.length(); j++) {
                if (j < output.length() && output[j] == output[j+1]) {
                    count++;
                } else {
                    newOut += (to_string(count)+ output[j]);
                    count = 1;
                }
            }
            output = newOut;
        }
        return output;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(6);
    return 1;
}