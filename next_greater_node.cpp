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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> st;
        if (head == NULL)
            return ans;
        
        stack<int> minHeap;
        ListNode *rev = reverse(head);
        
        while(rev != NULL) {
            while (!minHeap.empty() && minHeap.top() <= rev->val)
                minHeap.pop();
            st.push(minHeap.empty() ? 0 : minHeap.top());
            minHeap.push(rev->val);
            rev = rev->next;
        }
        
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
    
    ListNode* reverse(ListNode *head) {
        ListNode *p = head, *q = NULL;
        while(p != NULL) {
            ListNode *temp = p->next;
            p->next = q, q = p, p = temp;
        }
        return q;
    }
};