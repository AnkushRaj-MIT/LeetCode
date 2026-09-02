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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> mp;
        int sum = 0;
        ListNode* curr = dummy->next;
        mp[0] = dummy;
        while (curr != NULL) {
            sum += curr->val;
            if (mp.find(sum) != mp.end()) {
                ListNode* prev = mp[sum];
                ListNode* temp = prev->next;
                int tempSum = sum;
                while (temp != curr) {
                    tempSum += temp->val;
                    mp.erase(tempSum);
                    temp = temp->next;
                }
                prev->next = curr->next;
            }
            else {
                mp[sum] = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};