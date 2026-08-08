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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> temp;
        ListNode* tail=head;
        while(tail!=NULL){
            temp.push_back(tail->val);
            tail=tail->next;
        }
        sort(temp.begin(),temp.end());
        tail=head;
        int idx=0;
        while(tail!=NULL){
            tail->val=temp[idx++];
            tail=tail->next;
        }
        return head;
    }
};