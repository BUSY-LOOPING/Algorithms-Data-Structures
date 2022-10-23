#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        vector<int> add;
        while (temp1 != nullptr && temp2 != nullptr) {
            int temp = temp1->val + temp2->val + carry;
            if (temp > 9) {
                carry = temp / 10;
                temp = temp % 10;
            }
            else 
                carry = 0;
            add.push_back(temp);
            temp2 = temp2-> next;
            temp1 = temp1 -> next;
        }

        if (temp1 != nullptr) {
            int temp = temp1->val + carry;
            add.push_back(temp);
        } else if (temp2 != nullptr) {
            int temp = temp2->val + carry;
            add.push_back(temp);
        }
        ListNode* res = new ListNode();
        ListNode* temp = res;
        temp -> val = add[0];
        for (int i = add.size() - 1; i >= 0; i--) {
            ListNode* n = new ListNode(add[i], temp);
            res = n;
        }
        return res;
    }
};

int main() {
    ListNode* l1 = new ListNode(2);
    ListNode* l2 = new ListNode(4);
    ListNode* l3 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;

    ListNode* l4 = new ListNode(5);
    ListNode* l5 = new ListNode(6);
    ListNode* l6 = new ListNode(4);
    l4->next = l5;
    l5->next = l6;

    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l4);
    ListNode* temp = res;
    while(temp != NULL) {
        cout << temp->val << endl;
        temp = temp->next;
    }
}