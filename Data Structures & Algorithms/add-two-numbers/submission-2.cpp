/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;


        while(l1 || l2 || carry != 0){

            int l1v = (l1 != nullptr) ? l1->val : 0;
            int l2v = (l2 != nullptr) ? l2->val : 0;

            int curVal = (l1v+l2v+carry) % 10; 
            carry = (l1v+l2v+carry) / 10;

            ListNode* newNode = new ListNode(curVal);
            curr->next = newNode;
            curr = newNode;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr; 
        }

        ListNode* res = dummy->next;
        return res;
        
    }
};
