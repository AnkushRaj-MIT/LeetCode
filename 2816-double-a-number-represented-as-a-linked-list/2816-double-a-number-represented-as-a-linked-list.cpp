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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        int carry = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            int temp = 2*curr->val + carry;
            carry = temp/10;
            curr->val = temp%10;
            prev = curr;
            curr = curr->next;
        }
        if(carry != 0){
            ListNode* newnode = new ListNode(carry);
            prev->next = newnode;
            newnode->next = NULL;
        }
        head = reverse(head);
        return head;
    }
};