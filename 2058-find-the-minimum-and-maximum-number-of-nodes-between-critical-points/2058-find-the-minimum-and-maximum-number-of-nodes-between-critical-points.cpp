class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        if (!head || !head->next || !head->next->next) return ans;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int first = -1;
        int last = -1;
        int pos = 1;
        int mindist = INT_MAX;
        while (curr->next) {
            ListNode* nex = curr->next;
            bool critical =
                (curr->val < prev->val && curr->val < nex->val) ||
                (curr->val > prev->val && curr->val > nex->val);
            if (critical) {
                if (first == -1) {
                    first = pos;
                    last = pos;
                }
                else {
                    mindist = min(mindist, pos - last);
                    last = pos;
                }
            }
            pos++;
            prev = curr;
            curr = curr->next;
        }
        if (first == -1 || first == last) return ans;
        return {mindist, last - first};
    }
};